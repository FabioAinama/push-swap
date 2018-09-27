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

int		push_b_to_a(int *pile_a, int *pile_b)
{
	int operations;

	operations = 0;
	while (pile_b[0] != 0)
	{
		if (pile_b[0] < pile_b[1])
		{
			swap_pile(pile_b);
			operations++;
		}
		if (pile_b[0] > pile_a[0])
		{
			push_pile(pile_a, pile_b);
			operations++;
		}
		if (pile_b[0] >= pile_b[1])
		{
			push_pile(pile_b, pile_a);
			operations++;
		}
		// if (pile_a[])
	}
	return (operations);
}

int		get_pile_length(int *pile)
{
	int i;

	i = 0;
	while (pile[i] != 0)
		i++;
	return (i);
}

void	should_swap_or_rotate_a(int *pile)
{
	int length;

	length = get_pile_length(pile);
	if (pile[1] <= pile[length - 1] && pile[1] <= pile[length - 2])
	{
		swap_pile(pile);
		printf("Swap pile A:\n");
	}
	else if (pile[length - 1] < pile[0])
	{
		reverse_rotate_pile(pile);
		printf("Reverse Rotate pile A:\n");		
	}
	else
	{
		rotate_pile(pile);
		printf("Rotate pile A:\n");
	}
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

int		check_pile(int *pile)
{
	int i;

	i = 0;
	while (pile[i] != 0 && pile[i] > pile[i + 1])
		i++;
	if (i == get_pile_length(pile))
		return (1);
	return (0);
}

int		check_correct_order(int *pile, int call)
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
	if (length > 3)
	{
		if ((pile[0] < pile[1]) && (pile[0] < pile[2]) && (pile[0] > pile[length - 1]))
			correct = 0;
		// correct = check_pile(pile);		
		// printf(">>>>Check pile return: %d\n", check_pile(pile));
	}
	if (correct == 0)
	{
		correct = 1;
		while (pile[0] < pile[i + 1])
			i++;
		if (i > (length - 1) / 2)
			correct = 0;
	}
	if (correct == 0)
	{
		while(pile[0] > pile[length - 1])
		{
			if (count == 0)
				count++;
			reverse_rotate_pile(pile);
			swap_pile(pile);
			printf("Going to reverse-rotate and swap B.Count = %d\n", count);
			print_pile(pile);
			count++;
			operations += 2;
		}
		while (count != 0)
		{
			rotate_pile(pile);
			count--;
			operations++;
		}
		operations += check_correct_order(pile, 1);
	}
		// printf("Count = %d\n", count);
	// if (correct == 1 && call == 1)
	// {
	// 	printf("Going to rotate twice B. Count = %d\n", count);
	// 	while (count != 0)
	// 	{
	// 		rotate_pile(pile);
	// 		count--;
	// 	}
	// 	print_pile(pile);
	// 	operations += 2;
	// }
	return (operations);
}

void    sort_algo(int *pile_a, int *pile_b)
{
	int finished;
	int a_length;
	int b_length;
	int operations;
	// int tmp;
	// int debug = 50;

	finished = 0;
	operations = 0;
	// tmp = -1;
	a_length = get_pile_length(pile_a);
	b_length = get_pile_length(pile_b);
	printf("\nSort Algo: \n\n");
	while (a_length > 3 && !finished)
	{
		if (pile_a[0] <= pile_a[1] && pile_a[0] <= pile_a[a_length - 1] && pile_a[0] <= pile_a[a_length - 2])
		{
			printf("Going to push %2d into pile B:\n", pile_a[0]);
			push_pile(pile_a, pile_b);
			print_piles(pile_a, pile_b);
			operations += check_correct_order(pile_b, 0);
			a_length--;
			b_length++;
			operations++;
		}
		else
		{
			printf("Going to Swap/Rotate/RevRotate pile A\n");
			should_swap_or_rotate_a(pile_a);
			print_piles(pile_a, pile_b);
			operations++;	
		}
		if (b_length > 1)
		{
			// tmp = operations;
			if (pile_a[0] > pile_a[a_length - 1] && pile_b[0] < pile_b[b_length - 1])
			{
				printf("Going to Rotate 2 piles\n");
				rotate_both(pile_a, pile_b);
				print_piles(pile_a, pile_b);
				operations++;
			}
			else if (pile_a[0] > pile_a[a_length - 1])
			{
				printf("Going to Rotate pile A\n");
				rotate_pile(pile_a);
				print_piles(pile_a, pile_b);
				operations++;
			}
			else if (pile_b[0] < pile_b[b_length - 1])
			{
				printf("Going to Rotate pile B\n");
				rotate_pile(pile_b);
				print_piles(pile_a, pile_b);
				operations++;
			}
			if (pile_a[0] > pile_a[1] && pile_b[0] < pile_b[1])
			{
				printf("Going to Swap 2 piles\n");
				swap_both(pile_a, pile_b);
				print_piles(pile_a, pile_b);
				operations++;			
			}
			else if (pile_b[0] < pile_b[1])
			{
				printf("Going to Swap pile B\n");
				swap_pile(pile_b);
				print_piles(pile_a, pile_b);
				operations++;
			}
		}
		if (pile_a[0] > pile_a[1])
		{
			printf("Going to Swap pile A\n");
			swap_pile(pile_a);
			print_piles(pile_a, pile_b);
			operations++;			
		}
		// if (!(pile_a[0] <= pile_a[1] && pile_a[0] <= pile_a[2] && pile_a[0] <= pile_a[a_length - 1] && pile_a[0] <= pile_a[a_length - 2]))
		// {
		// 	finished = 1;
		// }
	}
	operations += push_b_to_a(pile_a, pile_b);
	print_piles(pile_a, pile_b);	
	printf("Number of operations: %d\n", operations);
}
