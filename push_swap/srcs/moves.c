/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:57:31 by diogmart          #+#    #+#             */
/*   Updated: 2023/01/09 13:59:28 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
Linked list functions in libft:

	- ft_lstnew(void *content);
		Allocates (with malloc(3)) and returns a new node.
		The member variable ’content’ is initialized with the value of the parameter ’content’.
		The variable ’next’ is initialized to NULL.

	- ft_lstadd_front(t_list **lst, t_list *new);
		Adds the node ’new’ at the beginning of the list.

	- ft_lstadd_back(t_list **lst, t_list *new);
		Adds the node ’new’ at the end of the list.

	- ft_lstsize(t_list *lst);
		Counts the number of nodes in a list.

	- ft_lstlast(t_list *lst);
		Returns the last node of the list.

	-  ft_lstdelone(t_list *lst, void (*del)(void*));
		Takes as a parameter a node and frees the memory of the node and it’s content using the function ’del’.
		The memory of ’next’ is not be freed.

	- ft_lstclear(t_list **lst, void (*del)(void*));
		Deletes and frees the given node and every successor of that node, using the function ’del’ and free(3).
		The pointer to the list is set to NULL.

	- ft_lstiter(t_list *lst, void (*f)(void *));
		Iterates the list ’lst’ and applies the function ’f’ on the content of each node.

	- ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *));
		Iterates the list ’lst’ and applies the function ’f’ on the content of each node.
		Creates a new list resulting of the successive applications of the function ’f’.
		The ’del’ function is used to delete the content of a node if needed.
*/

/*
	typedef struct s_list
	{
		void			*content;
		struct s_list	*next;
	}	t_list;
*/

/*
	Stack (double pointer) → Head (pointer) → Node (t_list)
*/

void	swap(t_list **stack)
{
	t_list	*tmp;

	if (!stack || !(*stack))
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	ft_lstadd_front(stack, tmp);
//	tmp->next = *stack;
//	*stack = tmp;
}

void	push(t_list **stack_give, t_list **stack_receive)
{
	t_list	*tmp;

	if (!stack_give || !(*stack_give))
		return ;
	tmp = (*stack_give)->next;
	ft_lstadd_front(stack_receive, *stack_give);
	*stack_give = tmp;
}

void	rotate(t_list **stack)
{
	t_list	*tmp;

	if (!stack || !(*stack))
		return ;
	tmp = *stack;
	ft_lstadd_back(stack, tmp);
	*stack = tmp->next;
	tmp->next = NULL;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*tmp;
	int		size;

	if (!stack || !(*stack))
		return ;
	size = ft_lstsize(*stack);
	tmp = remove_index(stack, size - 1);
	if (tmp == NULL)
		return ;
	tmp->next = *stack;
	*stack = tmp;
}
