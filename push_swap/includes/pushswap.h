/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:14:54 by diogmart          #+#    #+#             */
/*   Updated: 2023/01/19 11:28:37 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

// Modified list struct
typedef struct b_list
{
	int				content;
	int				index;
	struct b_list	*next;
}	a_list;

//	Moves
void	swap(a_list **stack, char c);
void	push(a_list **stack_give, a_list **stack_receive, char c);
void	rotate(a_list **stack, char c);
void	reverse_rotate(a_list **stack, char c);

//	Utils
a_list	*remove_index(a_list **lst, int index);
int		get_min(a_list *stack);
int		get_max(a_list *stack);
int		get_average(a_list *stack, int size);
int		ft_is_sorted(a_list *stack, char c);
int		get_min_index(a_list *stack);
int		get_max_index(a_list *stack);

// a_list functions
a_list	*ft_alstnew(void *content);
int		ft_alstsize(a_list *lst);
void	ft_alstadd_back(a_list **lst, a_list *new);
void	ft_alstadd_front(a_list **lst, a_list *new);
a_list	*ft_alstlast(a_list *lst);

#endif