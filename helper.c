/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 23:54:52 by fginja-d          #+#    #+#             */
/*   Updated: 2018/10/01 23:54:55 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

int			find_min(t_pile *p)
{
	int i;

	i = 0;
	while (i < p->len)
	{
		if (p->pile[i] < p->min || p->min == 0)
			p->min = p->pile[i];
		i++;
	}
	return (p->min);
}

int			find_max(t_pile *p)
{
	int i;

	i = 0;
	p->max = 0;
	while (i < p->len)
	{
		if (p->pile[i] > p->max)
			p->max = p->pile[i];
		i++;
	}
	return (p->max);
}

int			push_number_to_top(t_pile *b, t_pile *a, int nb)
{
	int i;
	int op;

	i = 0;
	op = 0;
	while (i < b->len && b->pile[i] != nb)
		i++;
	if (i * 2 > b->len)
	{
		while (b->pile[0] != nb)
		{
			if (b->pile[0] == a->pile[a->len - 1] + 1)
			{
				op += push_pile(b, a);
				op += rotate_pile(a, 0);
			}
			op += reverse_rotate_pile(b, 0);
		}
	}
	else
	{
		while (b->pile[0] != nb)
		{
			if (b->pile[0] == a->pile[a->len - 1] + 1)
			{
				op += push_pile(b, a);
				op += rotate_both(a, b);
			}
			else
				op += rotate_pile(b, 0);
		}
	}
	return (op);
}

int		push_pile(t_pile *src, t_pile *dst)
{
	int i;

	i = 0;
	if (src->pile[0] == 0)
		return (0);
	i = dst->len;
	dst->pile[i + 1] = 0;
	while (i != 0)
	{
		dst->pile[i] = dst->pile[i - 1];
		i--;
	}
	dst->pile[0] = src->pile[0];
	while (src->pile[i] != 0)
	{
		src->pile[i] = src->pile[i + 1];
		i++;
	}
	if (dst->pile[0] > dst->max)
		dst->max = dst->pile[0];
	if (dst->pile[0] < dst->min || dst->min == 0)
		dst->min = dst->pile[0];
	dst->len++;
	src->len--;
	if (src->len == 0)
	{
		src->min = 0;
		src->max = 0;
	}
	find_max(src);
	printf("p%c\n", dst->letter);
	return (1);
}

int		swap_pile(t_pile *p, int both)
{
	int tmp;

	if (p->len > 1)
	{
		tmp = p->pile[1];
		p->pile[1] = p->pile[0];
		p->pile[0] = tmp;
	}
	if (both == 0)
		printf("s%c\n", p->letter);
	return (1);
}

int		swap_both(t_pile *a, t_pile *b)
{
	swap_pile(a, 1);
	swap_pile(b, 1);
	ft_putendl("ss");
	return (1);
}
