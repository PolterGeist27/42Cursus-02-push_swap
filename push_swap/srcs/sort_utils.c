/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:36:43 by diogmart          #+#    #+#             */
/*   Updated: 2023/02/06 11:01:15 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

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

int	ft_check_digit(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (1);
	if (ft_atol(str) < -2147483648 || ft_atol(str) > 2147483647)
	{
		ft_printf("Error\n");
		exit (0);
	}
	while (str[i] != '\0')
	{
		if ((str[i] != '-' && str[i] != '+') && !ft_isdigit(str[i]))
		{
			ft_printf("Error\n");
			exit (0);
		}
		i++;
	}
	return (1);
}

void	ft_check_repeats(t_alist *stack)
{
	t_alist	*tmp;
	t_alist	*tmp2;

	if (stack == NULL)
		return ;
	tmp = stack;
	tmp2 = stack->next;
	while (tmp->next != NULL)
	{
		while (tmp2 != NULL)
		{
			if (tmp->content == tmp2->content)
			{
				ft_printf("Error\n");
				exit (0);
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
		tmp2 = tmp->next;
	}
}

long	ft_atol(char *str)
{
	int			i;
	int			j;
	int			h;
	long int	final;

	i = 0;
	j = 0;
	final = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			j++;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		h = str[i] - 48;
		final = (final * 10) + h;
		i++;
	}
	if (j % 2 == 1)
		final *= -1;
	return (final);
}
