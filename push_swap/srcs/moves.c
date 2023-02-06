/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:57:31 by diogmart          #+#    #+#             */
/*   Updated: 2023/02/06 10:30:40 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

/*
Linked list functions in libft:

	- ft_lstnew(void *content);
		Allocates (with malloc(3)) and returns a new node.
		The member variable ’content’ is initialized
		with the value of the parameter ’content’.
		The variable ’next’ is initialized to NULL.

	- ft_lstadd_front(t_alist **lst, t_alist *new);
		Adds the node ’new’ at the beginning of the list.

	- ft_lstadd_back(t_alist **lst, t_alist *new);
		Adds the node ’new’ at the end of the list.

	- ft_lstsize(t_alist *lst);
		Counts the number of nodes in a list.

	- ft_lstlast(t_alist *lst);
		Returns the last node of the list.

	-  ft_lstdelone(t_alist *lst, void (*del)(void*));
		Takes as a parameter a node and frees the memory of 
		the node and it’s content using the function ’del’.
		The memory of ’next’ is not be freed.

	- ft_lstclear(t_alist **lst, void (*del)(void*));
		Deletes and frees the given node and every successor
		of that node, using the function ’del’ and free(3).
		The pointer to the list is set to NULL.

	- ft_lstiter(t_alist *lst, void (*f)(void *));
		Iterates the list ’lst’ and applies 
		the function ’f’ on the content of each node.

	- ft_lstmap(t_alist *lst, void *(*f)(void *),void (*del)(void *));
		Iterates the list ’lst’ and applies the 
		function ’f’ on the content of each node.
		Creates a new list resulting of the 
		successive applications of the function ’f’.
		The ’del’ function is used to delete the 
		content of a node if needed.
*/

/*
	typedef struct s_list
	{
		void			*content;
		struct s_list	*next;
	}	t_alist;
*/

/*
	Stack (double pointer) → Head (pointer) → Node (t_alist)
*/

void	swap(t_alist **stack, char c)
{
	t_alist	*tmp;

	if (!stack || !(*stack))
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	ft_alstadd_front(stack, tmp);
	if (c == 'a')
		ft_printf("sa\n");
	if (c == 'b')
		ft_printf("sb\n");
	if (c == '2')
		ft_printf("ss\n");
}

void	push(t_alist **stack_give, t_alist **stack_receive, char c)
{
	t_alist	*tmp;

	if (!stack_give || !(*stack_give))
		return ;
	tmp = (*stack_give)->next;
	ft_alstadd_front(stack_receive, *stack_give);
	*stack_give = tmp;
	if (c == 'a')
		ft_printf("pa\n");
	if (c == 'b')
		ft_printf("pb\n");
}

void	rotate(t_alist **stack, char c)
{
	t_alist	*tmp;

	if (!stack || !(*stack))
		return ;
	tmp = *stack;
	ft_alstadd_back(stack, tmp);
	*stack = tmp->next;
	tmp->next = NULL;
	if (c == 'a')
		ft_printf("ra\n");
	if (c == 'b')
		ft_printf("rb\n");
	if (c == '2')
		ft_printf("rr\n");
}

void	reverse_rotate(t_alist **stack, char c)
{
	t_alist	*tmp;
	int		size;

	if (!stack || !(*stack))
		return ;
	size = ft_alstsize(*stack);
	tmp = remove_index(stack, size - 1);
	if (tmp == NULL)
		return ;
	tmp->next = *stack;
	*stack = tmp;
	if (c == 'a')
		ft_printf("rra\n");
	if (c == 'b')
		ft_printf("rrb\n");
	if (c == '2')
		ft_printf("rrr\n");
}
