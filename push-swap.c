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

int		main(int argc, char **argv)
{
	int i;
	t_pile *a;
	t_pile *b;
	t_pile *cpy;
	// char **tab;

	tab = NULL;
	a = (t_pile*)malloc(sizeof(t_pile));
	b = (t_pile*)malloc(sizeof(t_pile));
	cpy = (t_pile*)malloc(sizeof(t_pile));

	i = 0;
	a->pile = (int *)malloc(sizeof(int) * argc);
	b->pile = (int *)malloc(sizeof(int) * argc);
	cpy->pile = (int *)malloc(sizeof(int) * argc);
	a->min = 0;
	a->letter = 'a';
	a->max = 0;
	a->last_sorted = 0;
	b->min = 0;
	b->max = 0;
	b->letter = 'b';
	a->pile[argc - 1] = 0;
	b->pile[0] = 0;
	while (i < argc - 1)
	{
		// tab = ft_strplit(argv[i + 1], ' ');
		a->pile[i] = ft_atoi(argv[i + 1]);
		cpy->pile[i] = a->pile[i];
		i++;
	}
	if (argc > 1)
	{
		order_numbers(a, cpy);
		sort_algo2(a, b);
	}
	// last_check(a->pile);
	return (0);
}
