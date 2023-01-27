/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_alist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:36:21 by diogmart          #+#    #+#             */
/*   Updated: 2023/01/25 10:31:55 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_alist	*ft_alstnew(void *content)
{
	t_alist	*new;

	new = (t_alist *)malloc(sizeof(t_alist));
	if (!new)
		return (NULL);
	new->index = -1;
	new->content = ft_atoi(content);
	new->next = NULL;
	return (new);
}

int	ft_alstsize(t_alist *lst)
{
	t_alist	*tmp;
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

void	ft_alstadd_back(t_alist **lst, t_alist *new)
{
	t_alist	*tmp;

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

void	ft_alstadd_front(t_alist **lst, t_alist *new)
{
	new->next = *lst;
	*lst = new;
}

t_alist	*ft_alstlast(t_alist *lst)
{
	t_alist	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	return (tmp);
}
