/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogmart <diogmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:14:54 by diogmart          #+#    #+#             */
/*   Updated: 2023/01/09 15:04:52 by diogmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

//	Moves
void	swap(t_list **stack);
void	push(t_list **stack_give, t_list **stack_receive);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);

//	Utils
t_list	*remove_index(t_list **lst, int index);
int		get_min_index(t_list *stack);

#endif