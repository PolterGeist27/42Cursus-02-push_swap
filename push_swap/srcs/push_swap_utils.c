/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:09:25 by diogmart          #+#    #+#             */
/*   Updated: 2023/01/17 14:53:52 by diogmart         ###   ########.fr       */
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

t_list	*remove_index(t_list **lst, int index)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		i;

	if (!lst || ft_lstsize(*lst) <= index)
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

int	get_min_index(t_list *stack)
{
	t_list	*tmp;
	int 	min;
	int		i;
	int		index;

	i = 0;
	index = 0;
	tmp = stack;
	min = ft_atoi(tmp->content);
	while (tmp != NULL)
	{
		if (ft_atoi(tmp->content) < min)
		{
			min = ft_atoi(tmp->content);
			index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (index);
}

int	get_max_index(t_list *stack)
{
	t_list	*tmp;
	int 	max;
	int		i;
	int		index;

	i = 0;
	index = 0;
	tmp = stack;
	max = ft_atoi(tmp->content);
	while (tmp != NULL)
	{
		if (ft_atoi(tmp->content) > max)
		{
			max = ft_atoi(tmp->content);
			index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (index);
}

int	get_average(t_list *stack)
{
	t_list	*tmp;
	int 	average;
	int		count;
	
	count = 0;
	average = 0;
	tmp = stack;
	while (tmp != NULL)
	{
		average += ft_atoi(tmp->content);
		count++;
		tmp = tmp->next;
	}
	if (average > 0)
		average = average / count;
	return (average);
}

int	ft_is_sorted(t_list *stack, char c)
{
	t_list *tmp1;
	t_list *tmp2;

	tmp1 = stack;
	tmp2 = stack->next;
	while(tmp2 != NULL)
	{
		if (ft_atoi(tmp1->content) > ft_atoi(tmp2->content) && c == 'a')
			return (0);
		if (ft_atoi(tmp1->content) < ft_atoi(tmp2->content) && c == 'b')
			return (0);
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}
	return (1);
}