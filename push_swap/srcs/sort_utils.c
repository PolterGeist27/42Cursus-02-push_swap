/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:36:43 by diogmart          #+#    #+#             */
/*   Updated: 2023/01/27 10:22:31 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_b_stack(t_alist **b_stack, t_alist **a_stack, int shift)
{
	int	i;
	int	size;

	if (ft_is_sorted(*b_stack, 'b')
		&& (ft_is_sorted(*a_stack, 'a') || *a_stack == NULL))
	{
		while (*b_stack != NULL)
			push(b_stack, a_stack, 'a');
		return ;
	}
	size = ft_alstsize(*b_stack);
	i = 0;
	while (i < size && (*b_stack) != NULL)
	{
		if (((*b_stack)->index & (1 << (shift + 1))) == 0)
			rotate(b_stack, 'b');
		else
			push(b_stack, a_stack, 'a');
		i++;
	}
}
