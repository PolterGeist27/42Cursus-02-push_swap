/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:20:12 by diogmart          #+#    #+#             */
/*   Updated: 2023/01/17 15:14:07 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_lstprint(t_list **lst)
{
	t_list	*tmp;

	if(*lst == NULL) {
		ft_printf("Empty list");
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL){
		ft_printf("%s ",tmp->content);
		tmp = tmp->next;
	}
	ft_printf("%s ",tmp->content);
}

void	ft_sort_average(t_list **stack_give, t_list **stack_receive, char c, int size)
{
	int	average;
	int	i;

	average = get_average(*stack_give);
	i = 0;
	while (i < ft_lstsize(*stack_give))
	{
		if (ft_atoi((*stack_give)->content) < average && c == 'b' && ft_lstsize(*stack_give) > size)
			push(stack_give, stack_receive, c);
		else if (ft_atoi((*stack_give)->content) >= average && c == 'a')
			push(stack_give, stack_receive, c);
		else if (ft_lstsize(*stack_give) != 3)
		{
			if (c == 'a')
				rotate(stack_give, 'b');
			else if (c == 'b' && ft_lstsize(*stack_give) > size)
				rotate(stack_give, 'a');
		}
		i++;
	}
}

void	ft_sort_stack(t_list **stack, char c)
{
	ft_printf("----------------\n");
	ft_printf("Stack A: ");
	ft_lstprint(stack);
	ft_printf("\n----------------\n");
	while ((*stack) != NULL && !ft_is_sorted(*stack, c))
	{
		if (c == 'a')
		{
			if (ft_atoi(((*stack)->next)->content) > ft_atoi((((*stack)->next)->next)->content))
			{
				rotate(stack, c);
				swap(stack, c);
				if (!ft_is_sorted(*stack, c))
					reverse_rotate(stack, c);
			}
			if (ft_atoi((*stack)->content) > ft_atoi(((*stack)->next)->content))
				swap(stack, c);
		}
		if (c == 'b')
		{
			if (ft_atoi(((*stack)->next)->content) < ft_atoi((((*stack)->next)->next)->content))
			{
				rotate(stack, c);
				swap(stack, c);
				if (!ft_is_sorted(*stack, c))
					reverse_rotate(stack, c);
			}
			if (ft_atoi((*stack)->content) < ft_atoi(((*stack)->next)->content))
				swap(stack, c);
		}
	}
}


void	ft_sort(t_list **a_stack, t_list **b_stack)
{
	int current_size;

	current_size = 3;
	while (!ft_is_sorted(*a_stack, 'a') || *b_stack != NULL)
	{
		while (ft_lstsize(*a_stack) != current_size)
			ft_sort_average(a_stack, b_stack, 'b', current_size);
		ft_sort_stack(a_stack, 'a');
		while ((*b_stack) != NULL)
			ft_sort_average(b_stack, a_stack, 'a', current_size);
		ft_sort_stack(b_stack, 'b');
		current_size += 3;
	}
}

int	main(int argc, char **argv)
{
	t_list	*a_stack;
	t_list	*b_stack;
	int		i;

	if (argc <= 3)
		ft_printf("Error! Input an array to sort!\n");
	i = 1;
	a_stack = NULL;
	b_stack = NULL;
	while (argv[i] != NULL)
	{
		ft_lstadd_back(&a_stack, ft_lstnew(argv[i]));
		i++;
	}
	ft_sort(&a_stack, &b_stack);
	ft_printf("----------------\n");
	ft_printf("Stack A: ");
	ft_lstprint(&a_stack);
	ft_printf("\nStack B: ");
	ft_lstprint(&b_stack);
	ft_printf("\n----------------\n");
}
