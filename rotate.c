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

int		rotate_pile(t_pile *p, int both)
{
	int tmp;
	int i;

	i = 0;
	tmp = p->pile[0];
	if (p->len < 2)
		return (0);
	while (p->pile[i] != 0)
	{
		p->pile[i] = p->pile[i + 1];
		i++;
	}
	p->pile[i - 1] = tmp;
	p->pile[i] = 0;
	if (both == 0)
		printf("r%c\n", p->letter);
	return (1);
}

int		rotate_both(t_pile *a, t_pile *b)
{
	rotate_pile(a, 1);
	rotate_pile(b, 1);
	printf("rr\n");
	return (1);
}

int 	reverse_rotate_pile(t_pile *p, int both)
{
	int tmp;
	int length;

	length = p->len - 1;
	tmp = p->pile[length];
	if (length < 1)
		return (0);
	while (length > 0)
	{
		p->pile[length] = p->pile[length - 1];
		length--;
	}
	p->pile[0] = tmp;
	if (both == 0)
		printf("rr%c\n", p->letter);
	return (1);
}

int		reverse_rotate_both(t_pile *a, t_pile *b)
{
	reverse_rotate_pile(a, 1);
	reverse_rotate_pile(b, 1);
	printf("rrr\n");
	return (1);
}
