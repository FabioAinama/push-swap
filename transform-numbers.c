/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform-numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 00:45:15 by fginja-d          #+#    #+#             */
/*   Updated: 2018/09/28 00:45:17 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

void	transform_numbers(t_pile *a, t_pile *cpy)
{
	int nb;
	int i;
	int j;

	i = 0;
	while (i < a->len)
	{
		j = 0;
		nb = cpy->pile[i];
		while (a->pile[i] != cpy->pile[j] && j < a->len)
			j++;
		a->pile[i] = j + 1;
		i++;
	}
}

void	order_numbers(t_pile *a, t_pile *cpy) // A modifier en quicksort!!!!!!!!!
{
	int length;
	int i;
	int j;
	int tmp;

	cpy->len = a->len;
	j = 0;
	while (j < a->len - 1)
	{
		i = 0;
		while (i < a->len - 1 - j)
		{
			if (cpy->pile[i] > cpy->pile[i + 1])
			{
				tmp = cpy->pile[i + 1];
				cpy->pile[i + 1] = cpy->pile[i];
				cpy->pile[i] = tmp;
			}
			i++;
		}
		j++;
	}
	transform_numbers(a, cpy);
}
