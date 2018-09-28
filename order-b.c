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

int		order_b(int *pile, int b_length)
{
	int length;
	int i;
	int correct;
	int operations;
	int count;

	length = get_pile_length(pile);
	correct = 1;
	i = 0;
	count = 0;
	operations = 0;
	if (length >= 2)
	{
		if (pile[0] < pile[length - 1])
		{
			printf("Going to rotate B\n");
			rotate_pile(pile);
			operations++;
		}
	}
	if (length >= 3)
	{
		if (pile[0] < pile[1])
			correct = 0;
	}
	if (correct == 0)
	{
		correct = 1;
		while (pile[0] < pile[i + 1])
			i++;
		if (i > (length - 1) / 2)
		{
			// Plus proche du bot
			correct = 0;
		}
		else
		{
			// Plus proche du top
			printf("Going to swap B\n");
			swap_pile(pile);
			operations++;
			print_pile(pile);
			// Ne vaut le coup que si le cout pour le placer correctement est inferieur au nombre de piece restant a placer
			// if (i * i * 2 < b_length) // Nouveau
			// {
			// 	while (count < i - 1)
			// 	{
			// 		printf("Going to rotate + swap B\n");
			// 		rotate_pile(pile);
			// 		swap_pile(pile);
			// 		print_pile(pile);
			// 		operations += 2;
			// 		count++;
			// 	}
			// 	while (count)
			// 	{
			// 		printf("Going rev rotate B\n");
			// 		reverse_rotate_pile(pile);
			// 		print_pile(pile);
			// 		operations++;
			// 		count--;
			// 	}
			// }
			// printf("Going to swap B\n");
			// swap_pile(pile);
			// operations++;
		}
	}
	if (correct == 0)
	{
		while(pile[0] > pile[length - 1])
		{
			if (count == 0)
				count++;
			reverse_rotate_pile(pile);
			swap_pile(pile);
			printf("Going to reverse-rotate and swap B. Count = %d\n", count);
			// print_pile(pile);
			count++;
			operations += 2;
		}
		while (count != 0)
		{
			rotate_pile(pile);
			count--;
			operations++;
		}
	}
	print_pile(pile);
	return (operations);
}
