/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap-push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 20:02:12 by fginja-d          #+#    #+#             */
/*   Updated: 2018/10/06 20:02:14 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

void	print_piles2(t_pile *a, t_pile *b)
{
	int i;

	i = a->len - 1;
	while (i >= 0)
	{
		printf("Pile A: %-10d\n", a->pile[i]);
		i--;
	}
	printf("Pile A (Last): %-10d\n", a->pile[a->len]);
	i = b->len - 1;
	while (i >= 0)
	{
		printf("Pile B: %10d\n", b->pile[i]);
		i--;
	}
	printf("Pile B (Last): %10d\n", b->pile[b->len]);
	printf("----------------------------------------\n");	
}

int		push_pile(t_pile *src, t_pile *dst, int print, int *res)
{
	(void)res;
	if (src->pile[0] == 0)
		return (0);
	dst->pile[dst->len] = src->pile[src->len - 1];
	dst->len++;
	dst->pile[dst->len] = 0;
	src->len--;
	src->pile[src->len] = 0;
	if (dst->pile[dst->len - 1] > dst->max)
		dst->max = dst->pile[dst->len - 1];
	find_max(src);
	if (print == 1)
	{
		if (dst->letter == 'a')
			push_into_res(res, 12);
		else
			push_into_res(res, 3);
		// ft_putstr("p");
		// ft_putchar(dst->letter);
		// ft_putstr("\n");
	}
	return (1);
}

int		swap_pile(t_pile *p, int print, int *res)
{
	int tmp;

	if (p->len > 1)
	{
		tmp = p->pile[p->len - 2];
		p->pile[p->len - 2] = p->pile[p->len - 1];
		p->pile[p->len - 1] = tmp;
	}
	if (print == 0)
	{
		if (p->letter == 'a')
			push_into_res(res, 1);
		else
			push_into_res(res, 2);
		// ft_putstr("s");
		// ft_putchar(p->letter);
		// ft_putstr("\n");
	}
	return (1);
}

int		swap_both(t_pile *a, t_pile *b, int print, int *res)
{
	swap_pile(a, 1, res);
	swap_pile(b, 1, res);
	if (print == 1)
	{
		push_into_res(res, 4);
		// ft_putendl("ss");
	}
	return (1);
}
