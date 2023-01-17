/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:14:54 by diogmart          #+#    #+#             */
/*   Updated: 2023/01/17 14:37:54 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

//	Moves
void	swap(t_list **stack, char c);
void	push(t_list **stack_give, t_list **stack_receive, char c);
void	rotate(t_list **stack, char c);
void	reverse_rotate(t_list **stack, char c);

//	Utils
t_list	*remove_index(t_list **lst, int index);
int		get_min_index(t_list *stack);
int		get_max_index(t_list *stack);
int		get_average(t_list *stack);
int		ft_is_sorted(t_list *stack, char c);

#endif