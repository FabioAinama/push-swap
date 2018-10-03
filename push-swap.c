/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:04:38 by fginja-d          #+#    #+#             */
/*   Updated: 2018/09/24 19:04:40 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

void	reverse_rotate_pile(int *pile)
{
	int tmp;
	int length;

	length = 0;
	while (pile[length] != 0)
		length++;
	length--;
	tmp = pile[length];
	while (length > 0)
	{
		pile[length] = pile[length - 1];
		length--;
	}
	pile[0] = tmp;
}

void	revers_rotate_both(int *pile_a, int *pile_b)
{
	reverse_rotate_pile(pile_a);
	reverse_rotate_pile(pile_b);
}

void	rotate_pile(int *pile)
{
	int tmp;
	int i;

	i = 0;
	tmp = pile[0];
	while (pile[i] != 0)
	{
		pile[i] = pile[i + 1];
		i++;
	}
	pile[i - 1] = tmp;
	pile[i] = 0;
}

void	rotate_both(int *pile_a, int *pile_b)
{
	rotate_pile(pile_a);
	rotate_pile(pile_b);
}

void	push_pile(int *pile_src, int *pile_dst)
{
	int i;

	i = 0;
	if (pile_src[0] == 0)
		return ;
	// Decale dst vers le bas, et copie le top de src dans le top de dst
	while (pile_dst[i] != 0)
		i++;
	pile_dst[i + 1] = 0;
	while (i != 0)
	{
		pile_dst[i] = pile_dst[i - 1];
		i--;
	}
	pile_dst[0] = pile_src[0];
	// Decale src vers le haut
	while (pile_src[i] != 0)
	{
		pile_src[i] = pile_src[i + 1];
		i++;
	}
}

void	swap_pile(int *pile)
{
	int tmp;
	int i;

	i = 0;
	while (pile[i])
		i++;
	if (i > 1)
	{
		tmp = pile[1];
		pile[1] = pile[0];
		pile[0] = tmp;
	}
}

void	swap_both(int *pile_a, int *pile_b)
{
	swap_pile(pile_a);
	swap_pile(pile_b);
}

int		main(int argc, char **argv)
{
	int *pile_b;
	int *copy_a;
	int i;
	t_pile *a;
	t_pile *b;

	a = (t_pile*)malloc(sizeof(t_pile));
	b = (t_pile*)malloc(sizeof(t_pile));

	i = 0;
	a->pile = (int *)malloc(sizeof(int) * argc);
	b->pile = (int *)malloc(sizeof(int) * argc);
	a->min = 0;
	a->max = 0;
	a->last_sorted = 0;
	b->min = 0;
	b->max = 0;
	copy_a = (int *)malloc(sizeof(int) * argc);
	a->pile[argc - 1] = 0;
	b->pile[0] = 0;
	while (i < argc - 1)
	{
		a->pile[i] = ft_atoi(argv[i + 1]);
		copy_a[i] = a->pile[i];
		i++;
	}
	if (argc > 1)
	{
		print_pile(a->pile, 'A');
		print_pile(b->pile, 'B');		
		order_numbers(a->pile, copy_a);
		// sort_algo(a->pile, b->pile);
		sort_algo2(a, b);
	}
	last_check(a->pile);
	return (0);
}
