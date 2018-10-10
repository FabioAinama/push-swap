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
	char letter;
	int *pile;
	int min;
	int max;
	int avg;
	int len;
}				t_pile;

int		get_pile_length(int *pile);
void	order_numbers(t_pile *a, t_pile *cpy);
void	last_check(t_pile *p);
void	fill_piles(t_pile *a, t_pile *c, int argc, char **argv);
void	fill_pile(t_pile *a, int argc, char **argv);
void	sort_algo2(t_pile *a, t_pile *b);
int 	push_pile(t_pile *src, t_pile *dst, int print);
int		swap_pile(t_pile *p, int print);
int 	swap_both(t_pile *a, t_pile *b, int print);
int		rotate_pile(t_pile *p, int print);
int		rotate_both(t_pile *a, t_pile *b, int print);
int 	reverse_rotate_pile(t_pile *p, int print);
int		reverse_rotate_both(t_pile *a, t_pile *b, int print);
int		find_min(t_pile *p);
int		find_max(t_pile *p);
void	find_last_sorted_rev(t_pile *p);
void	find_last_sorted(t_pile *p);
void	get_average(t_pile *p);
int		push_number_to_top(t_pile *src, t_pile *dst, int nb);
int		sorted(t_pile *p);
int		get_average_pivot(t_pile *p, int pivot);
int		push_to_merge(t_pile *a, t_pile *b);
int		split_a(t_pile *a, t_pile *b, int pivot);
t_pile	*init_pile(int c, int length);
int		get_length_args(int argc, char **argv);

void	print_pile(t_pile *p);
void	print_piles(t_pile *a, t_pile *b);

#endif
