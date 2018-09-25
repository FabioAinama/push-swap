/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:29:14 by fginja-d          #+#    #+#             */
/*   Updated: 2018/09/25 15:29:16 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

void	push_pile(int *pile_src, int *pile_dst);
void	swap_pile(int *pile);
void	swap_both(int *pile_a, int *pile_b);
void	rotate_pile(int *pile);
void	rotate_both(int *pile_a, int *pile_b);
void	reverse_rotate_pile(int *pile);
void	revers_rotate_both(int *pile_a, int *pile_b);
void    sort_algo(int *pile_a, int *pile_b);

#endif
