/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order-a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 04:46:43 by fginja-d          #+#    #+#             */
/*   Updated: 2018/09/28 04:46:44 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

int		order_a(int *pile, int max)
{
	int length;
	int i;
	int operations;
	int count;

	length = get_pile_length(pile) - 1;
	i = 0;
	operations = 0;
	count = 0;
	if (pile[1] - pile[0] > 1)
	{
		while (pile[0] < pile[length] && pile[length] != max)
		{
			// printf("Going to exchange first and last of A (3 operations...)\n");
			reverse_rotate_pile(pile);
			swap_pile(pile);
			// rotate_pile(pile);
			operations += 3;
			count++;
		}
		while (count > 0)
		{
			// printf("Going to rotate A\n");
			rotate_pile(pile);
			operations++;
			count--;
		}
		rotate_pile(pile);
	}
	while (pile[0] == pile[length] + 1)
	{
		// printf("Going to reverse rotate A\n");
		reverse_rotate_pile(pile);
		operations++;
	}
	return (operations);
}
