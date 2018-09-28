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

void	print_pile(int *pile)
{
	int i;

	i = 0;			
	while (pile[i] != 0)
	{
		printf("Pile B: %10d\n", pile[i]);
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
	return (0);
}

int		find_min_to_push(int *p_a, int *p_b)
{
	int a_len;
	int operations;

	a_len = get_pile_length(p_a);
	operations = 0;
	if (maybe_better_rotate(p_a, p_b))
	{
		// Ici optimisation possible en choississant entre rotate et reverse rotate selon ce qui serait le plus pratique
		rotate_pile(p_a);
		operations++;
		operations += find_min_to_push(p_a, p_b);
		return (operations);
	}
	if (a_len >= 4)
	{
		if (p_a[1] <= p_a[2] && p_a[1] <= p_a[a_len - 1] && p_a[1] <= p_a[a_len - 2])
		{
			swap_pile(p_a);
			operations++;
		}
		else if (p_a[2] <= p_a[1] && p_a[2] <= p_a[a_len - 1] && p_a[2] <= p_a[a_len - 2])
		{
			rotate_pile(p_a);
			swap_pile(p_a);
			operations += 2;
		}
		else if (p_a[a_len - 1] <= p_a[1] && p_a[a_len - 1] <= p_a[2] && p_a[a_len - 1] <= p_a[a_len - 2])
		{
			reverse_rotate_pile(p_a);
			operations++;
		}
		else if (p_a[a_len - 2] <= p_a[1] && p_a[a_len - 2] <= p_a[2] && p_a[a_len - 2] <= p_a[a_len - 1])
		{
			reverse_rotate_pile(p_a);
			reverse_rotate_pile(p_a);
			operations += 2;
		}
		push_pile(p_a, p_b);
		operations++;
	}
	return (operations);
}

void    sort_algo(int *pile_a, int *pile_b)
{
	int a_length;
	int b_length;
	int operations;
	int *max;

	int j;

	j = 0;
	if (!(max = (int*)malloc(sizeof(int) * 4)))
		return ;
	while (j < 4)
	{
		max[j] = 0;
		j++;
	}

	operations = 0;
	a_length = get_pile_length(pile_a);
	b_length = get_pile_length(pile_b);
	printf("\nSort Algo: \n\n");
	while (a_length > 3)
	{
		if (pile_a[0] <= pile_a[1] && pile_a[0] <= pile_a[2] && pile_a[0] <= pile_a[a_length - 1] && pile_a[0] <= pile_a[a_length - 2])
		{
			// if (maybe_better_rotate(pile_a, pile_a))
			// {
			// 	rotate_pile(pile_a);
			// 	operations++;
			// }
			// else
			// {
				printf("Going to push %2d into pile B:\n", pile_a[0]);
				push_pile(pile_a, pile_b);
				print_piles(pile_a, pile_b);
				a_length--;
				b_length++;
				operations++;
				printf("Number of operations: %d\n", operations);
			// }
		}
		else
		{
			printf("Going to find MIN and push it into pile B\n");
			operations += find_min_to_push(pile_a, pile_b);
			a_length = get_pile_length(pile_a);
			b_length = get_pile_length(pile_b);
			print_piles(pile_a, pile_b);
			printf("Number of operations: %d\n", operations);
		}
		if (pile_a[0] > pile_a[a_length - 1] && pile_b[0] < pile_b[b_length - 1])
		{
			printf("Going to Rotate 2 piles\n");
			rotate_both(pile_a, pile_b);
			print_piles(pile_a, pile_b);
			operations++;
			printf("Number of operations: %d\n", operations);
		}
		operations += order_b(pile_b, b_length);
	}
	printf("Number of operations (Push to B): %d\n", operations);
	operations += push_b_to_a(pile_a, pile_b);
	print_piles(pile_a, pile_b);
	printf("Number of operations (Total): %d\n", operations);
}
