/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:20:12 by diogmart          #+#    #+#             */
/*   Updated: 2023/01/09 11:54:15 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
TODO:
	-...
*/

int	main(int argc, char **argv)
{
	t_list	*a_stack;
	t_list	*b_stack;
	int		i;

	if (argc <= 1)
		ft_printf("Error! Input an array to sort!\n");
	i = 1;
	a_stack = NULL;
	b_stack = NULL;
	while (argv[i] != NULL)
	{
		ft_lstadd_back(&a_stack, ft_lstnew((void *)argv[i]));
		i++;
	}
}