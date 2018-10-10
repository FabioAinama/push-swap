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

int			closer_to_which(t_pile *p, int nb)
{
	int i;

	i = 0;
	while (i < p->len && p->pile[i] != nb)
		i++;
	if (i * 2 <= p->len)
		return (1);
	else
		return (0);
}

int			push_number_to_top(t_pile *b, t_pile *a, int nb)
{
	// int i;
	int op;

	// i = 0;
	op = 0;
	// while (i < b->len && b->pile[i] != nb)
	// 	i++;
	if (closer_to_which(b, nb))
	{
		while (b->pile[b->len - 1] != nb)
		{
			if (b->pile[b->len - 1] == a->pile[0] + 1)
			{
				op += push_pile(b, a, 1);
				if (closer_to_which(b, nb + 1))
					op += rotate_both(a, b, 1);
				else
					op += rotate_pile(a, 1);
			}
			else
				op += reverse_rotate_pile(b, 1);
		}
	}
	else
	{
		while (b->pile[b->len - 1] != nb)
		{
			if (b->pile[b->len - 1] == a->pile[0] + 1)
			{
				op += push_pile(b, a, 1);
				// if (closer_to_which(b, nb + 1))
				// 	op += rotate_both(a, b, 1);
				// else
					op += rotate_pile(a, 1);
			}
			else
				op += rotate_pile(b, 1);
		}
	}
	return (op);
}
