/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 16:09:20 by fginja-d          #+#    #+#             */
/*   Updated: 2018/10/09 16:09:22 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

static	void	empty_b(t_pile *a, t_pile *b, int *res)
{
	while (b->len > 0)
	{
		push_number_to_top(b, a, a->pile[a->len - 1] - 1, res);
		push_pile(b, a, 1, res);
	}
}

static	void	order_a(t_pile *a, int *res)
{
	int max;
	int min;

	max = find_max(a);
	min = find_min(a);
	while (!sorted(a))
	{
		if (a->pile[2] == min)
			reverse_rotate_pile(a, 1, res);
		else if (a->pile[2] == max)
		{
			if (a->pile[0] == min)
				swap_pile(a, 1, res);
			else
				rotate_pile(a, 1, res);
		}
		else
		{
			if (a->pile[0] == min)
				reverse_rotate_pile(a, 1, res);
			else
				swap_pile(a, 1, res);
		}
	}
}

/*
**	Sorting algorithm for 10 or less numbers
*/

void			simple_sort(t_pile *a, t_pile *b, int fd)
{
	int *res;
	int max;

	if (!(res = (int *)malloc(sizeof(int) * 1000)))
	{
		close_fd(fd);
		exit_all(a, b);
	}
	ft_memset(res, 0, 100);
	max = find_max(a);
	while (a->len > 3)
	{
		if (a->pile[a->len - 1] < max - 2)
			push_pile(a, b, 1, res);
		else if (a->pile[a->len - 1] > a->pile[0] && b->pile[b->len - 1] < b->pile[0])
			rotate_both(a, b, 1, res);
		else
			rotate_pile(a, 1, res);
		if (a->pile[a->len - 1] > a->pile[a->len - 2] && b->pile[b->len - 1] < b->pile[b->len - 2])
			swap_both(a, b, 1, res);
	}
	order_a(a, res);
	empty_b(a, b, res);
	reduce_result(res);
	convert_result(res, fd);
}
