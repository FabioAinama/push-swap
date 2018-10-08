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

int		push_pile(t_pile *src, t_pile *dst, int print)
{
	int i;

	i = 0;
	if (src->pile[0] == 0)
		return (0);
	i = dst->len;
	dst->pile[i + 1] = 0;
	while (i != 0)
	{
		dst->pile[i] = dst->pile[i - 1];
		i--;
	}
	dst->pile[0] = src->pile[0];
	while (src->pile[i] != 0)
	{
		src->pile[i] = src->pile[i + 1];
		i++;
	}
	if (dst->pile[0] > dst->max)
		dst->max = dst->pile[0];
	dst->len++;
	src->len--;
	find_max(src);
	if (print == 1)
	{
		ft_putstr("p");
		ft_putchar(dst->letter);
		ft_putstr("\n");
	}
	return (1);
}

int		swap_pile(t_pile *p, int print)
{
	int tmp;

	if (p->len > 1)
	{
		tmp = p->pile[1];
		p->pile[1] = p->pile[0];
		p->pile[0] = tmp;
	}
	if (print == 0)
	{
		ft_putstr("s");
		ft_putchar(p->letter);
		ft_putstr("\n");
	}
	return (1);
}

int		swap_both(t_pile *a, t_pile *b, int print)
{
	swap_pile(a, 1);
	swap_pile(b, 1);
	if (print == 1)
		ft_putendl("ss");
	return (1);
}
