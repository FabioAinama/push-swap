/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order-b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 01:58:52 by fginja-d          #+#    #+#             */
/*   Updated: 2018/09/28 01:58:54 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

int		order_b(t_pile *p)
{
	int op;
	int i;

	op = 0;
	i = 0;
	if (p->len >= 2)
	{
		if (p->pile[0] < p->pile[p->len - 1])
			op += rotate_pile2(p);
		if (p->pile[0] < p->pile[1])
			op += swap_pile2(p);
	}
	return (op);
}

int		order_b_reverse(t_pile *p)
{
	int length;
	int op;

	length = p->len;
	op = 0;
	if (length >= 2)
	{
		if (p->pile[0] > p->pile[length - 1])
			op += rotate_pile2(p);
		if (p->pile[0] > p->pile[1])
			op += swap_pile2(p);
	}
	return (op);
}