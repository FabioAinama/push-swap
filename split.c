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

int		split_a(t_pile *a, t_pile *b, int pivot)
{
	int half;
	int op;

	half = a->len / 2;
	op = 0;
	while (a->len > half)
	{
		if (a->pile[0] > pivot)
		{
			if (b->pile[0] < (pivot / 2))
				op += rotate_both(a, b, 1);
			else
				op += rotate_pile(a, 1);
		}
		else
			op += push_pile(a, b, 1);
	}
	return (op);
}