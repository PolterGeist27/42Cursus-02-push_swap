/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:27:15 by diogmart          #+#    #+#             */
/*   Updated: 2023/01/19 11:28:10 by diogmart         ###   ########.fr       */
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