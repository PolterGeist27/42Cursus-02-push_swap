/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:14:54 by diogmart          #+#    #+#             */
/*   Updated: 2023/01/19 13:20:34 by diogmart         ###   ########.fr       */
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
}	t_alist;

//	Moves
void	swap(t_alist **stack, char c);
void	push(t_alist **stack_give, t_alist **stack_receive, char c);
void	rotate(t_alist **stack, char c);
void	reverse_rotate(t_alist **stack, char c);

//	Utils
t_alist	*remove_index(t_alist **lst, int index);
int		get_min(t_alist *stack);
int		get_max(t_alist *stack);
int		get_average(t_alist *stack, int size);
int		ft_is_sorted(t_alist *stack, char c);
int		get_min_index(t_alist *stack);
int		get_max_index(t_alist *stack);
void	ft_index(t_alist **stack);
void	ft_handle_5(t_alist **a_stack, t_alist **b_stack);
void	ft_handle_3(t_alist **stack, char c);

// t_alist functions
t_alist	*ft_alstnew(void *content);
int		ft_alstsize(t_alist *lst);
void	ft_alstadd_back(t_alist **lst, t_alist *new);
void	ft_alstadd_front(t_alist **lst, t_alist *new);
t_alist	*ft_alstlast(t_alist *lst);

#endif