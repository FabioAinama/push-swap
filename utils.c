/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 00:51:22 by fginja-d          #+#    #+#             */
/*   Updated: 2018/10/03 00:51:23 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

int		sorted(t_pile *p)
{
	int i;

	i = 0;
	while (i < p->len - 1)
	{
		if (p->pile[i] > p->pile[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	get_average(t_pile *p)
{
	int i;
	int sum;

	i = 0;
	sum = 0;
	if (p->len > 0)
	{
		while (i < p->len)
		{
			sum += p->pile[i];
			i++;
		}
		p->avg = (sum / p->len);
	}
}

int		get_average_pivot(t_pile *p, int pivot)
{
	int i;
	int sum;

	i = 0;
	sum = 0;
	if (p->len > 0)
	{
		while (i < p->len && p->pile[i] <= pivot && p->pile[i] != 1)
		{
			sum += p->pile[i];
			i++;
		}
		if (i == 0)
			return (0);
		else
			return ((int)(sum / i));
	}
	return (0);
}

int		get_pile_length(int *pile)
{
	int i;

	i = 0;
	while (pile[i] != 0)
		i++;
	return (i);
}
