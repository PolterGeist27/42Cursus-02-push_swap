/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:27:15 by diogmart          #+#    #+#             */
/*   Updated: 2023/01/19 13:12:07 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	get_min_index(a_list *stack)
{
	a_list	*tmp;
	int 	min;
	int		i;
	int		index;

	i = 0;
	index = 0;
	tmp = stack;
	min = tmp->content;
	while (tmp != NULL)
	{
		if (tmp->content < min)
		{
			min = tmp->content;
			index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (index);
}

int	get_max_index(a_list *stack)
{
	a_list	*tmp;
	int 	max;
	int		i;
	int		index;

	i = 0;
	index = 0;
	tmp = stack;
	max = tmp->content;
	while (tmp != NULL)
	{
		if (tmp->content > max)
		{
			max = tmp->content;
			index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (index);
}

void	ft_index(a_list **stack)
{
	a_list	*tmp;
	int		current_index;
	int		min;
	int		max;

	min = get_min(*stack);
	max = get_max(*stack);
	current_index = 0;
	tmp = *stack;
	while (min <= max)
	{
		while (tmp != NULL)
		{
			if (tmp->content == min)
			{
				tmp->index = current_index;
				current_index++;
			}
			tmp = tmp->next;
		}
		tmp = *stack;
		min++;
	}
	
}

void	ft_handle_5(a_list **a_stack, a_list **b_stack)
{
	int	min;
	int	max;

	min = get_min(*a_stack);
	max = get_max(*a_stack);
	while (ft_alstsize(*a_stack) != 3)
	{
		if ((*a_stack)->content == min || (*a_stack)->content == max)
		{
			push(a_stack, b_stack, 'b');
		}
		else
			rotate(a_stack, 'a');
	}
	ft_handle_3(a_stack, 'a');
	push(b_stack, a_stack, 'a');
	if (ft_is_sorted(*a_stack, 'a'))
		push(b_stack, a_stack, 'a');
	else
	{
		rotate(a_stack, 'a');
		push(b_stack, a_stack, 'a');
	}
}

void	ft_handle_3(a_list **stack, char c)
{
	int min_index;
	int max_index;

	min_index = get_min_index(*stack);
	max_index = get_max_index(*stack);
	while (!ft_is_sorted(*stack, 'a'))
	{
		if (max_index == 0)
		{
			reverse_rotate(stack, c);
			reverse_rotate(stack, c);
			if (min_index == 2)
				swap(stack, c);
		}
		else if (max_index == 1)
		{
			reverse_rotate(stack, c);
			if (min_index == 0)
				swap(stack, c);
		}
		else if (max_index == 2 && min_index == 1)
			swap(stack, c);
	}
}
