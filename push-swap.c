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

int     main(int argc, char **argv)
{
	int *pile_a;
	int *pile_b;
	int i;

	i = 0;
	pile_a = (int *)malloc(sizeof(int) * argc);
	pile_b = (int *)malloc(sizeof(int) * argc);
	pile_a[argc - 1] = 0;
	pile_b[0] = 0;
	while (i < argc - 1)
	{
		pile_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	i = 0;
	if (argc > 1)
	{
		// push_pile(pile_a, pile_b);
		// swap_pile(pile_a);
		// reverse_rotate_pile(pile_a);
		while (pile_a[i] != 0)
		{
			printf("Pile A: %d\n", pile_a[i]);
			i++;
		}
		i = 0;
		while (pile_b[i] != 0)
		{
			printf("Pile B: %d\n", pile_b[i]);
			i++;
		}
		sort_algo(pile_a, pile_b);
	}
	return (0);
}
