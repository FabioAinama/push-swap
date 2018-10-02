/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 23:54:52 by fginja-d          #+#    #+#             */
/*   Updated: 2018/10/01 23:54:55 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

void		find_min(t_pile *p)
{
	int i;

	i = 0;
	while (i < p->len)
	{
		if (p->pile[i] < p->min || p->min == 0)
			p->min = p->pile[i];
		i++;
	}
}

int			push_min_to_top(t_pile *src, t_pile *dst)
{
	int i;
	int operations;

	i = 0;
	operations = 0;
	while (i < src->len && src->pile[i] != src->min)
		i++;
	if (dst->pile[0] == (src->pile[0] + 1))
		operations += push_pile2(src, dst);
	if (i * 2 > src->len)
	{
		while (src->pile[0] != src->min)
		{
			operations += reverse_rotate_pile2(src);
			if (dst->pile[0] == (src->pile[0] + 1))
			{
				operations += push_pile2(src, dst);
				src->min = 0;
				find_min(src);
			}
		}
	}
	else
	{
		while (src->pile[0] != src->min)
		{
			operations += rotate_pile2(src);
			if (dst->pile[0] == (src->pile[0] + 1))
			{
				operations += push_pile2(src, dst);
				src->min = 0;
				find_min(src);
			}
		}
	}
	return (operations);
}

int	    push_pile2(t_pile *src, t_pile *dst)
{
	int i;

	i = 0;
	if (src->pile[0] == 0)
		return (0);
	// Decale dst vers le bas, et copie le top de src dans le top de dst
    i = dst->len;
	dst->pile[i + 1] = 0;
	while (i != 0)
	{
		dst->pile[i] = dst->pile[i - 1];
		i--;
	}
    dst->pile[0] = src->pile[0];
	// Decale src vers le haut
	while (src->pile[i] != 0)
	{
		src->pile[i] = src->pile[i + 1];
		i++;
    }
    if (dst->pile[0] > dst->max)
        dst->max = dst->pile[0];
    if (dst->pile[0] < dst->min || dst->min == 0)
        dst->min = dst->pile[0];
    dst->len++;
	src->len--;
	if (src->len == 0)
	{
		src->min = 0;
		src->max = 0;
	}
    return (1);
}

int	    swap_pile2(t_pile *p)
{
	int tmp;

	if (p->len > 1)
	{
		tmp = p->pile[1];
		p->pile[1] = p->pile[0];
		p->pile[0] = tmp;
    }
    return (1);
}

int		rotate_pile2(t_pile *p)
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
	return (1);
}

int 	reverse_rotate_pile2(t_pile *p)
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
    return (1);
}

void	find_last_sorted_rev(t_pile *p)
{
	int i;
	printf("Find Last sorted Called\n");
	i = p->len - 1;
	while (i > 0)
	{
		printf("FLS: pile[i] = %d - pile[i - 1] = %d, i = %d\n", p->pile[i], p->pile[i - 1], i);
	
		if (p->pile[i] == p->pile[i - 1] - 1)
			p->last_sorted = p->pile[i - 1];
		i--;
	}
}

void	find_last_sorted(t_pile *p)
{
	int i;
	printf("Find Last sorted Called\n");
	i = 0;
	while (i < p->len)
	{
		printf("FLS: pile[i] = %d - pile[i - 1] = %d, i = %d\n", p->pile[i], p->pile[i - 1], i);
	
		if (p->pile[i] == p->pile[i + 1] + 1)
			p->last_sorted = p->pile[i - 1];
		i++;
	}
}


// int     find_max(t_pile *p)
// {
//     int i;
//     int max;

//     i = 0;
//     max
//     while (i < p->len)
//     {
//         if (p->pile[i] > )
//         i++;
//     }
// }