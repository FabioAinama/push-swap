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
			correct = 0;
		}
		else
		{
			// Plus proche du top
			printf("Going to swap B\n");
			swap_pile(pile);
			operations++;
			print_pile(pile, 'B');
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
	print_pile(pile, 'B');
	return (operations);
}

int		order_b2(t_pile *p)
{
	// Utiliser last sorted pour savoir quel est mon plus grand nb bien trié (ex 1,2,3,4 -> 4)
	// int length;
	int operations;
	int i;

	// length = get_pile_length(p->pile);
	printf("Last sorted B: %d\n", p->last_sorted);
	operations = 0;
	i = 0;
	if (p->pile[0] == 1)
		p->last_sorted = 1;
	// if (p->pile[0] == (p->last_sorted + 1))
	// {
	// 	while (p->pile[1] != p->last_sorted)
	// 	{
	// 		operations += reverse_rotate_pile2(p);
	// 		operations += swap_pile2(p);
	// 		i++;
	// 	}
	// 	while (i + 1)
	// 	{
	// 		operations += rotate_pile2(p);
	// 		i--;
	// 	}
	// 	find_last_sorted_rev(p);
	// }
	if (p->len >= 2)
	{
		if (p->pile[0] < p->pile[p->len - 1])
		{
			// printf("Going to rotate B\n");
			rotate_pile(p->pile);
			operations++;
		}
		// if (p->pile[p->len - 1] - p->pile[0] > p->pile[0] - p->pile[1])
		// {
		// 	// printf("Going to rev-rotate, swp, and rotate(x2) B\n");
		// 	reverse_rotate_pile(p->pile);
		// 	swap_pile(p->pile);
		// 	rotate_pile(p->pile);
		// 	rotate_pile(p->pile);
		// 	operations += 4;
		// }
		if (p->pile[0] < p->pile[1])
		{
			// printf("Going to swap B\n");
			swap_pile(p->pile);
			operations++;
		}
	}
	return (operations);
}

int		order_b_reverse(t_pile *p)
{
	int length;
	int operations;

	length = p->len;
	operations = 0;
	if (length >= 2)
	{
		if (p->pile[0] > p->pile[length - 1])
		{
			// printf("Going to rotate B\n");
			// rotate_pile(pile);
			rotate_pile2(p);
			operations++;
		}
		if (p->pile[0] > p->pile[1])
		{
			// printf("Going to swap B\n");
			swap_pile2(p);
			operations++;
		}
	}
	return (operations);
}