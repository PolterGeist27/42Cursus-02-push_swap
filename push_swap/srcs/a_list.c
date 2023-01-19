/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:36:21 by diogmart          #+#    #+#             */
/*   Updated: 2023/01/19 10:46:40 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

a_list	*ft_alstnew(void *content)
{
	a_list	*new;

	new = (a_list *)malloc(sizeof(a_list));
	if (!new)
		return (NULL);
	new->index = -1;
	new->content = ft_atoi(content);
	new->next = NULL;
	return (new);
}

int	ft_alstsize(a_list *lst)
{
	a_list	*tmp;
	int		i;

	if (!lst)
		return (0);
	i = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	ft_alstadd_back(a_list **lst, a_list *new)
{
	a_list	*tmp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = ft_alstlast(*lst);
		tmp->next = new;
	}
}

void	ft_alstadd_front(a_list **lst, a_list *new)
{
	new->next = *lst;
	*lst = new;
}

a_list	*ft_alstlast(a_list *lst)
{
	a_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	return (tmp);
}
