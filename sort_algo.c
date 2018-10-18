/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 14:31:52 by fginja-d          #+#    #+#             */
/*   Updated: 2018/10/18 14:31:53 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	quicksort(t_pile *a, t_pile *b, int pivot, int *res)
{
	while (a->pile[a->len - 1] <= pivot && a->pile[a->len - 1] != 1)
	{
		if (a->pile[a->len - 1] == a->pile[0] + 1)
			rotate_pile(a, 1, res);
		else
			push_pile(a, b, 1, res);
	}
	if (b->len != 0)
		push_to_merge(a, b, res);
}

static	void	quicksort_split(t_pile *a, t_pile *b, int pivot, int *res)
{
	int avg;
	int nb_rot;

	nb_rot = 0;
	if (!(avg = get_average_pivot(a, pivot)))
		return ;
	while (a->pile[a->len - 1] <= pivot && a->pile[a->len - 1] != 1)
	{
		if (a->pile[a->len - 1] >= avg)
			nb_rot += rotate_pile(a, 1, res);
		else
			push_pile(a, b, 1, res);
	}
	while (nb_rot--)
	{
		if (b->pile[b->len - 1] < b->pile[0] && b->len > 1)
			reverse_rotate_both(a, b, 1, res);
		else
			reverse_rotate_pile(a, 1, res);
	}
	if (b->len != 0)
		push_to_merge(a, b, res);
	quicksort(a, b, pivot, res);
}

static	void	empty_some(t_pile *a, t_pile *b, int *res, int length)
{
	while (length)
	{
		if (b->len <= 13)
		{
			push_number_to_top(b, a, b->max, res);
			push_pile(b, a, 1, res);
		}
		else if (b->pile[b->len - 1] == 1
			|| b->pile[b->len - 1] == (a->pile[0] + 1))
		{
			push_pile(b, a, 1, res);
			if (b->pile[b->len - 1] < b->avg
				&& b->pile[b->len - 1] != (a->pile[0] + 2) && b->len > 1)
				rotate_both(a, b, 1, res);
			else
				rotate_pile(a, 1, res);
		}
		else if (b->pile[b->len - 1] >= b->avg)
			push_pile(b, a, 1, res);
		else
			rotate_pile(b, 1, res);
		length--;
	}
}

void			push_to_merge(t_pile *a, t_pile *b, int *res)
{
	int pivot;
	int length;

	length = b->len;
	if (b->len == 0)
		return ;
	pivot = find_max(b);
	get_average(b);
	empty_some(a, b, res, length);
	while (!sorted(a) && (a->pile[a->len - 1] == 1
		|| a->pile[a->len - 1] == (a->pile[0] + 1)))
	{
		if (b->len > 0)
		{
			if (b->pile[b->len - 1] < b->pile[0])
				rotate_both(a, b, 1, res);
			else
				rotate_pile(a, 1, res);
		}
		else
			rotate_pile(a, 1, res);
	}
	push_to_merge(a, b, res);
	quicksort_split(a, b, pivot, res);
}

void			sort_algo(t_pile *a, t_pile *b, int fd)
{
	int *res;
	int pivot;

	res = malloc_res(a, b, fd, MAX_INST);
	find_max(a);
	pivot = a->len / 2;
	if (a->len % 2 != 0)
		pivot++;
	split_a(a, b, pivot, res);
	push_to_merge(a, b, res);
	quicksort_split(a, b, a->max, res);
	reduce_result(res);
	convert_result_clofree(res, fd);
	free_both_piles(a, b);
}
