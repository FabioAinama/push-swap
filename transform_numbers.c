/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 00:45:15 by fginja-d          #+#    #+#             */
/*   Updated: 2018/09/28 00:45:17 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	transform_numbers(t_pile *a, t_pile *cpy)
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

static	int		quicksort_order(int *tab, int start, int end)
{
	int pivot;
	int tmp;
	int i;
	int j;

	pivot = tab[end];
	i = start - 1;
	j = start - 1;
	while (++j <= end - 1)
	{
		if (tab[j] == pivot)
			return (-1);
		if (tab[j] <= pivot)
		{
			i++;
			tmp = tab[i];
			tab[i] = tab[j];
			tab[j] = tmp;
		}
	}
	tmp = tab[i + 1];
	tab[i + 1] = tab[end];
	tab[end] = tmp;
	return (i + 1);
}

static	int		quicksort_tab(int *tab, int start, int end)
{
	int pivot;
	int ret;

	ret = 0;
	if (start < end)
	{
		if ((pivot = quicksort_order(tab, start, end)) == -1)
			return (-1);
		ret = quicksort_tab(tab, pivot + 1, end);
		ret = quicksort_tab(tab, start, pivot - 1);
	}
	return (ret);
}

/*
**	Sort then will transform 6 8 5 20 into 2 3 1 4
**	(transform into successive numbers)
*/

int				order_numbers(t_pile *a, t_pile *cpy)
{
	if (quicksort_tab(cpy->pile, 0, cpy->len - 1) == -1)
		return (-1);
	transform_numbers(a, cpy);
	return (0);
}
