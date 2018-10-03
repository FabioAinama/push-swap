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

typedef struct	s_pile
{
	int *pile;
	int min;
	int max;
	int avg;
	int len;
	int last_sorted;
}				t_pile;

void	push_pile(int *pile_src, int *pile_dst);
void	swap_pile(int *pile);
void	swap_both(int *pile_a, int *pile_b);
void	rotate_pile(int *pile);
void	rotate_both(int *pile_a, int *pile_b);
void	reverse_rotate_pile(int *pile);
void	revers_rotate_both(int *pile_a, int *pile_b);
void	sort_algo(int *pile_a, int *pile_b);
int		get_pile_length(int *pile);
void	print_pile(int *pile, char c);
void	order_numbers(int *pile, int *new);
void	last_check(int *pile);
int		order_a(int *pile, int max);
void	print_piles(int *pile_a, int *pile_b);

void	sort_algo2(t_pile *a, t_pile *b);
int		order_b(t_pile *p);
int 	push_pile2(t_pile *src, t_pile *dst);
int 	swap_pile2(t_pile *p);
int 	reverse_rotate_pile2(t_pile *p);
int		rotate_pile2(t_pile *p);
void	find_min(t_pile *p);
void	find_max(t_pile *p);
int		push_min_to_top(t_pile *src, t_pile *dst);
int		order_b_reverse(t_pile *p);
void	find_last_sorted_rev(t_pile *p);
void	find_last_sorted(t_pile *p);
void	get_average(t_pile *p);
int		contain_number(t_pile *p, int number);
int		push_number_to_top(t_pile *src, t_pile *dst, int min);
int		sorted(t_pile *p);

#endif
