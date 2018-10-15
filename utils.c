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
	while (i < p->len)
	{
		if (p->pile[i] < p->pile[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	get_average(t_pile *p)
{
	int i;
	int sum;

	i = p->len - 1;
	sum = 0;
	if (p->len > 0)
	{
		while (i >= 0)
		{
			sum += p->pile[i];
			i--;
		}
		p->avg = (sum / p->len);
	}
}

/*
** It's possible to change the value of the return (-1, -2...) to optimize the number of operations
*/

int		get_average_pivot(t_pile *p, int pivot)
{
	int i;
	int sum;

	i = p->len - 1;
	sum = 0;
	if (p->len > 0)
	{
		while (i >= 0 && p->pile[i] <= pivot && p->pile[i] != 1)
		{
			sum += p->pile[i];
			i--;
		}
		if (i == p->len - 1)
			return (0);
		else
			return ((int)(sum / (p->len - i - 2)));
	}
	return (0);
}

int		get_pile_length(int *pile)
{
	int i;

	i = 0;
	while (pile[i] != 0)
		i++;
	return (i);
}


void	print_piles(t_pile *a, t_pile *b)
{
	int i;

	i = a->len - 1;
	while (i >= 0)
	{
		printf("Pile A: %-10d\n", a->pile[i]);
		i--;
	}
	// printf("Pile A (Last): %-10d\n", a->pile[a->len]);
	i = b->len - 1;
	while (i >= 0)
	{
		if (b->pile[i] != 0)
			printf("Pile B: %10d\n", b->pile[i]);
		i--;
	}
	// printf("Pile B (Last): %10d\n", b->pile[b->len]);
	printf("----------------------------------------\n");	
}

void	print_pile(t_pile *p)
{
	int i;

	i = p->len - 1;
	while (i >= 0)
	{
		printf("Pile %c: %10d\n", p->letter, p->pile[i]);
		i--;
	}
	printf("----------------------------------------\n");	
}