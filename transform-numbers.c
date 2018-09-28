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

void	transform_numbers(int *pile, int *copy)
{
	int nb;
	int length;
	int i;
	int j;

	length = get_pile_length(copy);
	i = 0;
	while (i < length)
	{
		j = 0;
		nb = copy[i];
		while (pile[j] != nb)
			j++;
		pile[j] = i + 1;
		i++;
	}
	// print_pile(pile);
}

void	order_numbers(int *pile, int *copy)
{
	int length;
	int i;
	int j;
	int tmp;

	length = get_pile_length(copy) - 1;
	j = 0;
	while (j < length)
	{
		i = 0;
		while (i < length - j)
		{
			if (copy[i] > copy[i + 1])
			{
				tmp = copy[i + 1];
				copy[i + 1] = copy[i];
				copy[i] = tmp;
			}
			i++;
		}
		j++;
	}
	// print_pile(copy);
	transform_numbers(pile, copy);
}
