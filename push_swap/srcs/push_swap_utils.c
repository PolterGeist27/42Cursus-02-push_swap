/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:09:25 by diogmart          #+#    #+#             */
/*   Updated: 2023/01/19 10:45:16 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
	This fuction takes and index and a list and "cuts"
	the list at 'index'
	
	Given a linked list 'lst' and an index 'index'
	this function iterates through the list until 
	'index' is found and sets the 'next' attribute
	of the previous node to NULL and returns a pointer
	to the first node of the section removed from the list.
*/ 

a_list	*remove_index(a_list **lst, int index)
{
	a_list	*tmp;
	a_list	*tmp2;
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

int	get_min(a_list *stack)
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
	return (min);
}

int	get_max(a_list *stack)
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
	return (max);
}

int	get_average(a_list *stack, int size)
{
	a_list	*tmp;
	int 	average;
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

int	ft_is_sorted(a_list *stack, char c)
{
	a_list *tmp1;
	a_list *tmp2;

	tmp1 = stack;
	tmp2 = stack->next;
	while(tmp2 != NULL)
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