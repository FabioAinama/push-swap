/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort-algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:30:01 by fginja-d          #+#    #+#             */
/*   Updated: 2018/09/25 15:30:06 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

int		check_correct_order_a(int *pile)
{
	int operations;

	operations = 0;
	if (pile[0] > pile[1])
	{
		swap_pile(pile);
		operations++;
	}
	if (pile[0] > pile[2])
	{
		reverse_rotate_pile(pile);
		operations++;
	}
	return (operations);
}

void	print_piles(int *pile_a, int *pile_b)
{
	int i;

	i = 0;			
	while (pile_a[i] != 0)
	{
		printf("Pile A: %-10d\n", pile_a[i]);
		i++;
	}
	i = 0;
	while (pile_b[i] != 0)
	{
		printf("Pile B: %10d\n", pile_b[i]);
		i++;
	}
	printf("----------------------------------------\n");	
}

void	print_pile(int *pile, char c)
{
	int i;

	i = 0;			
	while (pile[i] != 0)
	{
		printf("Pile %c: %10d\n", c, pile[i]);
		i++;
	}
	printf("----------------------------------------\n");
}

int		push_b_to_a(int *pile_a, int *pile_b)
{
	int operations;
	int max;

	operations = check_correct_order_a(pile_a);
	max = pile_a[get_pile_length(pile_a) - 1];
	while (pile_b[0] != 0)
	{
		if (pile_b[0] < pile_b[1])
		{
			// printf("Going to Swap pile B\n");
			swap_pile(pile_b);
			operations++;
			// print_piles(pile_a, pile_b);
			// printf("Number of operations: %d\n", operations);
		}
		if (pile_b[0] > pile_a[0])
		{
			// printf("Going to Push into pile B\n");
			push_pile(pile_a, pile_b);
			operations++;
			// print_piles(pile_a, pile_b);
			// printf("Number of operations: %d\n", operations);
		}
		if (pile_b[0] >= pile_b[1])
		{
			// printf("Going to Push into pile A\n");
			push_pile(pile_b, pile_a);
			operations++;
			// print_piles(pile_a, pile_b);
			// printf("Number of operations: %d\n", operations);
		}
		operations += order_a(pile_a, max);
		// print_piles(pile_a, pile_b);
	}
	printf("Number of operations (Push to A): %d\n", operations);
	return (operations);
}

int		find_max_values(int *pile, int *max)
{
	int i;

	i = 0;
	while (pile[i] != 0)
	{
		if (pile[i] > max[2])
		{
			max[0] = max[1];
			max[1] = max[2];
			max[2] = pile[i];
		}
		else if (pile[i] > max[1])
		{
			max[0] = max[1];
			max[1] = pile[i];
		}
		else if (pile[i] > max[0])
			max[0] = pile[i];
		i++;
	}
	return (1);
}

int		get_pile_length(int *pile)
{
	int i;

	i = 0;
	while (pile[i] != 0)
		i++;
	return (i);
}

int		maybe_better_rotate(int *p_a, int *p_b)
{
	int min;
	int a_len;

	a_len = get_pile_length(p_a);
	min = p_a[0];
	if (p_a[1] < min)
		min = p_a[1];
	if (p_a[2] < min)
		min = p_a[2];
	if (p_a[a_len - 1] < min)
		min = p_a[a_len - 1];
	if (p_a[a_len - 2] < min)
		min = p_a[a_len - 2];
	// printf("Min found: %d\n", min);
	if ((min - get_pile_length(p_b)) > (a_len / 2))
	{
		printf("Actually Better to rotate and try again.\n");
		return (1);
	}
	// if (p_a[0] - p_b[0] > 5 || p_b[0] - p_a[0] > 5)
	// 	return (1);
	return (0);
}
