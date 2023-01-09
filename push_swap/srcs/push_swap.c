/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:20:12 by diogmart          #+#    #+#             */
/*   Updated: 2023/01/09 15:28:40 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
TODO:
	- Sorting algorithm
	- Test move functions
	-...
*/

#include <stdio.h>

void	ft_lstprint(t_list **lst)
{
	t_list	*tmp;

	if(*lst == NULL) {
		ft_printf("Empty list\n");
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL){
		ft_printf("%s ",tmp->content);
		tmp = tmp->next;
	}
	ft_printf("%s ",tmp->content);
}

void	apply_func(t_list **a_stack, t_list **b_stack, char *str)
{
	if (!ft_strncmp(str, "sa", 3))
		swap(a_stack);
	else if (!ft_strncmp(str, "sb", 3))
		swap(b_stack);
	else if (!ft_strncmp(str, "ra", 3))
		rotate(a_stack);
	else if (!ft_strncmp(str, "rb", 3))
		rotate(b_stack);
	else if (!ft_strncmp(str, "rra", 3))
		reverse_rotate(a_stack);
	else if (!ft_strncmp(str, "rrb", 3))
		reverse_rotate(b_stack);
	else if (!ft_strncmp(str, "pa", 3))
		push(b_stack, a_stack);
	else if (!ft_strncmp(str, "pb", 3))
		push(a_stack, b_stack);
	else
		ft_printf("There is no such commmand. Try Again\n");
}

int	sort(t_list **a_stack, t_list **b_stack)
{
	int		min_index;
	int		size;
	char	*command;

	min_index = get_min_index(*a_stack);
	size = ft_lstsize(*a_stack);
	command = ft_calloc(4, sizeof(char));
	if (min_index > (size / 2))
		command = "ra";
	else
		command = "rra";
	while (get_min_index(*a_stack) != 0)
	{
		if (!ft_strncmp(command, "rra", 3))
			reverse_rotate(a_stack);
		else
			rotate(a_stack);
	}
	push(a_stack, b_stack);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*a_stack;
	t_list	*b_stack;
	int		i;
	int		j;
	//char	str[10];

	if (argc <= 1)
		ft_printf("Error! Input an array to sort!\n");
	i = 1;
	a_stack = NULL;
	b_stack = NULL;
	while (argv[i] != NULL)
	{
		ft_lstadd_back(&a_stack, ft_lstnew(argv[i]));
		i++;
	}
	ft_printf("Stack A: ");
	ft_lstprint(&a_stack);
	ft_printf("\nStack B: ");
	ft_lstprint(&b_stack);
	ft_printf("----------------\n");
	j = 0;
	while(ft_lstsize(a_stack) != 2)
	{
		sort(&a_stack, &b_stack);
		ft_printf("Stack A: ");
		ft_lstprint(&a_stack);
		ft_printf("\nStack B: ");
		ft_lstprint(&b_stack);
		ft_printf("\n");
		ft_printf("----------------\n");
	}
	/*while (1)
	{
		sort(&a_stack, &b_stack);
		scanf("%s", str);
		apply_func(&a_stack, &b_stack, str);
		ft_printf("Stack A: ");
		ft_lstprint(&a_stack);
		ft_printf("\nStack B: ");
		ft_lstprint(&b_stack);
		j++;
		ft_printf("\nNumber of moves: %d", j);
		ft_printf("\n");
	}*/
}
