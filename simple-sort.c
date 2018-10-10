/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple-sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 16:09:20 by fginja-d          #+#    #+#             */
/*   Updated: 2018/10/09 16:09:22 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

static int	rev_sorted_until(t_pile *p)
{
	int i;

	i = 0;
	while (p->pile[i] > p->pile[i + 1] && i < p->len)
		i++;
	return (i);
}

static int	sorted_until(t_pile *p)
{
	int i;

	i = p->len - 1;
	while (p->pile[i] < p->pile[i - 1])
		i--;
	return (i);
}

int		simple_sort(t_pile *a, t_pile *b)
{
	int op;

	op = 0;
	if (a->pile[a->len - 1] > a->pile[a->len - 2])
		swap_pile(a, 1);
	
	return (op);
}
