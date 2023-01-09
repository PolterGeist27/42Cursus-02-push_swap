/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:09:25 by diogmart          #+#    #+#             */
/*   Updated: 2023/01/09 11:44:45 by diogmart         ###   ########.fr       */
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

	if (!lst || ft_lstsize(*lst) > index)
		return (NULL);
	tmp = *lst;
	i = 0;
	while (tmp->next != NULL)
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
