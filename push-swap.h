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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>

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
int		order_numbers(t_pile *a, t_pile *cpy);
void	last_check(t_pile *a, t_pile *b);
int		fill_piles(t_pile *a, t_pile *c, int argc, char **argv);
int		fill_pile(t_pile *a, int argc, char **argv);
void	sort_algo(t_pile *a, t_pile *b, int fd);
int 	push_pile(t_pile *src, t_pile *dst, int print, int *res);
int		swap_pile(t_pile *p, int print, int *res);
int 	swap_both(t_pile *a, t_pile *b, int print, int *res);
int		rotate_pile(t_pile *p, int print, int *res);
int		rotate_both(t_pile *a, t_pile *b, int print, int *res);
int 	reverse_rotate_pile(t_pile *p, int print, int *res);
int		reverse_rotate_both(t_pile *a, t_pile *b, int print, int *res);
int		find_min(t_pile *p);
int		find_max(t_pile *p);
void	find_last_sorted_rev(t_pile *p);
void	find_last_sorted(t_pile *p);
void	get_average(t_pile *p);
int		push_number_to_top(t_pile *src, t_pile *dst, int nb, int *res);
int		sorted(t_pile *p);
int		get_average_pivot(t_pile *p, int pivot);
int		push_to_merge(t_pile *a, t_pile *b, int *res);
int		split_a(t_pile *a, t_pile *b, int pivot, int *res);
t_pile	*init_pile(int c, int length);
int		get_length_args(int argc, char **argv);

void	push_into_res(int *res, int value);
void	print_result(int *res, int fd);

void	print_pile(t_pile *p);
void	print_piles(t_pile *a, t_pile *b);
void	reduce_result(int *res);
void	convert_result(int *res, int fd);

void	simple_sort(t_pile *a, t_pile *b, int fd);
void	exit_all(t_pile *a, t_pile *b);

#endif
