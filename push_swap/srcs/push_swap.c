/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:20:12 by diogmart          #+#    #+#             */
/*   Updated: 2023/01/19 12:47:34 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
Possible ways to sort the stacks:
	1:
		- Divide them up;
		- Idex the numbers;
		- Turn them into binary;
		- Radix sort;
	2:
		-...
*/

void	ft_binary_radix(int shift, a_list **a_stack, a_list **b_stack)
{
	int	size;
	int	i;

	size = ft_alstsize(*a_stack);
	i = 0;
	while (i < size)
	{
		if (((*a_stack)->index & (1 << shift)) == 0)
		{
			push(a_stack, b_stack, 'b');
		}
		else
			rotate(a_stack, 'a');
		i++;
	}
	while (*b_stack != NULL)
		push(b_stack, a_stack, 'a');
}

void	ft_sort(a_list **a_stack, a_list **b_stack)
{
	int	i;

	i = 0;
	while (!ft_is_sorted(*a_stack, 'a') || *b_stack != NULL)
	{
		ft_binary_radix(i, a_stack, b_stack);
		i++;
	}
	
}

void	ft_lstprint(a_list **lst)
{
	a_list	*tmp;

	if(*lst == NULL) {
		ft_printf("Empty list");
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL){
		ft_printf("%d ",tmp->content);
		tmp = tmp->next;
	}
	ft_printf("%d ",tmp->content);
}

int	main(int argc, char **argv)
{
	a_list	*a_stack;
	a_list	*b_stack;
	int		i;

	if (argc <= 3)
		ft_printf("Error! Input an array to sort!\n");
	i = 1;
	a_stack = NULL;
	b_stack = NULL;
	while (argv[i] != NULL)
	{
		ft_alstadd_back(&a_stack, ft_alstnew(argv[i]));
		i++;
	}
	ft_index(&a_stack);
	if (ft_alstsize(a_stack) <= 3)
		ft_handle_3(&a_stack, 'a');
	else if (ft_alstsize(a_stack) <= 5)
		ft_handle_5(&a_stack, &b_stack);
	else
		ft_sort(&a_stack, &b_stack);
}
