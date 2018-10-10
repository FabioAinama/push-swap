/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 03:35:10 by fginja-d          #+#    #+#             */
/*   Updated: 2018/10/05 03:35:12 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

int		reverse_rotate_pile(t_pile *p, int print)
{
	int tmp;
	int i;

	i = 0;
	tmp = p->pile[0];
	if (p->len < 2)
		return (0);
	while (i < p->len)
	{
		p->pile[i] = p->pile[i + 1];
		i++;
	}
	p->pile[i - 1] = tmp;
	p->pile[i] = 0;
	if (print == 1)
	{
		ft_putstr("rr");
		ft_putchar(p->letter);
		ft_putstr("\n");
	}
	return (1);
}

int		rotate_both(t_pile *a, t_pile *b, int print)
{
	rotate_pile(a, 0);
	rotate_pile(b, 0);
	if (print == 1)
		ft_putendl("rr");
	return (1);
}

int 	rotate_pile(t_pile *p, int print)
{
	int tmp;
	int length;

	length = p->len - 1;
	tmp = p->pile[length];
	if (length < 2)
		return (0);
	while (length > 0)
	{
		p->pile[length] = p->pile[length - 1];
		length--;
	}
	p->pile[0] = tmp;
	if (print == 1)
	{
		ft_putstr("r");
		ft_putchar(p->letter);
		ft_putstr("\n");
	}
	return (1);
}

int		reverse_rotate_both(t_pile *a, t_pile *b, int print)
{
	reverse_rotate_pile(a, 0);
	reverse_rotate_pile(b, 0);
	if (print == 1)
		ft_putendl("rrr");
	return (1);
}
