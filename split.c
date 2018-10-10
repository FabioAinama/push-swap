/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 05:04:13 by fginja-d          #+#    #+#             */
/*   Updated: 2018/10/05 05:04:14 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

int		split_a(t_pile *a, t_pile *b, int pivot, int *res)
{
	int half;
	int op;

	half = a->len / 2;
	op = 0;
	while (a->len > half)
	{
		if (a->pile[a->len - 1] > pivot)
		{
			if (b->pile[b->len - 1] < (pivot / 2) && b->len > 1)
				op += rotate_both(a, b, 1, res);
			else
				op += rotate_pile(a, 1, res);
		}
		else
			op += push_pile(a, b, 1, res);
	}
	return (op);
}