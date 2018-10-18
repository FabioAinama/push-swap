/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 20:02:12 by fginja-d          #+#    #+#             */
/*   Updated: 2018/10/06 20:02:14 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		push_pile(t_pile *src, t_pile *dst, int print, int *res)
{
	if (src->len == 0)
		return (0);
	dst->pile[dst->len] = src->pile[src->len - 1];
	dst->len++;
	dst->pile[dst->len] = 0;
	src->len--;
	src->pile[src->len] = 0;
	if (dst->pile[dst->len - 1] > dst->max)
		dst->max = dst->pile[dst->len - 1];
	find_max(src);
	if (print == 1)
	{
		if (dst->letter == 'a')
			push_into_res(res, 12);
		else
			push_into_res(res, 3);
	}
	return (1);
}

int		swap_pile(t_pile *p, int print, int *res)
{
	int tmp;

	if (p->len > 1)
	{
		tmp = p->pile[p->len - 2];
		p->pile[p->len - 2] = p->pile[p->len - 1];
		p->pile[p->len - 1] = tmp;
	}
	if (print == 1)
	{
		if (p->letter == 'a')
			push_into_res(res, 1);
		else
			push_into_res(res, 2);
	}
	return (1);
}

int		swap_both(t_pile *a, t_pile *b, int print, int *res)
{
	swap_pile(a, 0, res);
	swap_pile(b, 0, res);
	if (print == 1)
		push_into_res(res, 4);
	return (1);
}
