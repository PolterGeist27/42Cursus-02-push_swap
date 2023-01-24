/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:20:12 by diogmart          #+#    #+#             */
/*   Updated: 2023/01/24 12:14:20 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
TODO:
	- Find if the next "pushable" number is faster to reach using "rra" or "ra"
	and apply this when pushing the numbers from a_stack (with the current bit at '0')
	and  when pushing the numbers from b_stack (with the next bit at '1')
*/

void	ft_lstprint(t_alist **lst)
{
	t_alist	*tmp;

	if(*lst == NULL) {
		ft_printf("Empty list");
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL){
		ft_printf("%d ",tmp->index);
		tmp = tmp->next;
	}
	ft_printf("%d ",tmp->index);
}

void	free_stack(t_alist *stack)
{
	t_alist *tmp;
	t_alist *tmp_next;
	
	if (!stack)
		return ;
	tmp = stack;
	while(tmp != NULL)
	{
		tmp_next = tmp->next;
		free(tmp);
		tmp = tmp_next;
	}
}

void	ft_binary_radix(int shift, t_alist **a_stack, t_alist **b_stack)
{
	int	size;
	int	i;

	size = ft_alstsize(*a_stack);
	i = 0;
	while (i < size && (!ft_is_sorted(*a_stack, 'a') && *a_stack != NULL))
	{
		if (((*a_stack)->index & (1 << shift)) == 0)
			push(a_stack, b_stack, 'b');
		else
			rotate(a_stack, 'a');
		i++;
	}
	if (ft_is_sorted(*b_stack, 'b') && (ft_is_sorted(*a_stack, 'a') || *a_stack == NULL))
	{
		while (*b_stack != NULL)
			push(b_stack, a_stack, 'a');
		return ;
	}
	size = ft_alstsize(*b_stack);
	i = 0;
	while (i < size && (*b_stack) != NULL && !ft_is_sorted(*b_stack, 'b'))
	{
		if (((*b_stack)->index & (1 << (shift + 1))) == 0)
			rotate(b_stack, 'b');
		else
			push(b_stack, a_stack, 'a');
		i++;
	}
}

void	ft_sort(t_alist **a_stack, t_alist **b_stack)
{
	int	i;

	i = 0;
	while (!ft_is_sorted(*a_stack, 'a') || *b_stack != NULL)
	{
		ft_binary_radix(i, a_stack, b_stack);
		//ft_printf("\nI: %d\n", i);
		i++;
		if (i > 15)
			return;
		/*ft_printf("\n----------\nStack A: ");
		ft_lstprint(a_stack);
		ft_printf("\nStack B: ");
		ft_lstprint(b_stack);
		ft_printf("\n----------\n");*/
	}
}

void	ft_get_input(int argc, char **argv, t_alist **a_stack)
{
	int		i;
	char	**stack;
	
	
	stack = NULL;
	if (argc > 2)
	{
		i = 1;
		while (argv[i] != NULL)
		{
			ft_alstadd_back(a_stack, ft_alstnew(argv[i]));
			i++;
		}
	}
	else if (argc == 2)
	{
		i = 0;
		stack = ft_split(argv[1], ' ');
		while (stack[i] != NULL)
		{
			ft_alstadd_back(a_stack, ft_alstnew(stack[i]));
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	t_alist	*a_stack;
	t_alist	*b_stack;


	if (argc < 2)
	{
		ft_printf("Error! Input an array to sort!\n");
		return (0);
	}
	a_stack = NULL;
	b_stack = NULL;
	ft_get_input(argc, argv, &a_stack);
	ft_index(&a_stack);
	if (ft_alstsize(a_stack) <= 3)
		ft_handle_3(&a_stack, 'a');
	else if (ft_alstsize(a_stack) <= 5)
		ft_handle_5(&a_stack, &b_stack);
	else
		ft_sort(&a_stack, &b_stack);
	free_stack(a_stack);
	free_stack(b_stack);
}
