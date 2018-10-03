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

int		contain_number(t_pile *p, int number)
{
	int i;

	i = 0;
	// printf("Contain number called. Length of pile: %d\n", p->len);
	while (i < p->len)
	{
		if (p->pile[i] == number)
			return (1);
		i++;
	}
	return (0);
}

// int		find_push_number(t_pile *p, int number)
