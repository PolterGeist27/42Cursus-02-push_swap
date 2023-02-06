/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:09:25 by diogmart          #+#    #+#             */
/*   Updated: 2023/02/06 11:03:23 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

/*
	This fuction takes and index and a list and "cuts"
	the list at 'index'
	
	Given a linked list 'lst' and an index 'index'
	this function iterates through the list until 
	'index' is found and sets the 'next' attribute
	of the previous node to NULL and returns a pointer
	to the first node of the section removed from the list.
*/

t_alist	*remove_index(t_alist **lst, int index)
{
	t_alist	*tmp;
	t_alist	*tmp2;
	int		i;

	if (!lst || ft_alstsize(*lst) <= index)
		return (NULL);
	tmp = *lst;
	i = 0;
	while (tmp != NULL)
	{
		if ((i + 1) == index)
		{
			tmp2 = tmp->next;
			tmp->next = NULL;
			return (tmp2);
		}
		tmp = tmp->next;
		i++;
	}
	return (NULL);
}

int	get_min(t_alist *stack)
{
	t_alist	*tmp;
	int		min;
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
	return (min);
}

int	get_max(t_alist *stack)
{
	t_alist	*tmp;
	int		max;
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
	return (max);
}

int	get_average(t_alist *stack, int size)
{
	t_alist	*tmp;
	int		average;
	int		count;

	count = 0;
	average = 0;
	tmp = stack;
	while (tmp != NULL && count < (ft_alstsize(stack) - size))
	{
		average += tmp->content;
		count++;
		tmp = tmp->next;
	}
	if (average > 0)
		average = average / count;
	return (average);
}

int	ft_is_sorted(t_alist *stack, char c)
{
	t_alist	*tmp1;
	t_alist	*tmp2;

	if (stack == NULL)
		return (0);
	tmp1 = stack;
	tmp2 = stack->next;
	while (tmp2 != NULL)
	{
		if ((tmp1->content > tmp2->content) && c == 'a')
			return (0);
		if ((tmp1->content < tmp2->content) && c == 'b')
			return (0);
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}
	return (1);
}
