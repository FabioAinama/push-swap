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

void	split_a(t_pile *a, t_pile *b, int pivot, int *res)
{
	int half;

	half = a->len / 2;
	while (a->len > half && half > 0)
	{
		if (a->pile[a->len - 1] > pivot)
		{
			if (b->pile[b->len - 1] < (pivot / 2) && b->len > 1)
				rotate_both(a, b, 1, res);
			else
				rotate_pile(a, 1, res);
		}
		else
			push_pile(a, b, 1, res);
	}
}