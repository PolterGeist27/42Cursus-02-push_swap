/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:36:43 by diogmart          #+#    #+#             */
/*   Updated: 2023/01/24 15:37:16 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	has_pushable_number(t_alist **stack, int shift, int bit)
{
	t_alist *tmp;

	tmp = *stack;
	while (tmp != NULL)
	{
		if ((tmp->index & (1 << shift)) == bit)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	find_least_moves(t_alist **stack, int index);
