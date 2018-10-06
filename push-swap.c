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

t_pile	*init_pile(int c, int length)
{
	t_pile *p;

	if (!(p = (t_pile*)malloc(sizeof(t_pile))))
		return (NULL);
	if (!(p->pile = (int *)malloc(sizeof(int) * (length + 1))))
		return (NULL);
	p->min = 0;
	p->max = 0;
	p->len = length;
	p->letter = c;
	return (p);
}

int		get_length_args(int argc, char **argv)
{
	int i;
	int j;
	int k;
	char **tab;

	i = 0;
	k = 0;
	while (i < argc)
	{
		j = 0;
		tab = NULL;
		tab = ft_strsplit(argv[i], ' ');
		while (tab[j])
		{
			// ft_strdel(&tab[j]);
			j++;
			k++;
		}
		free(tab);
		i++;
	}
	return (k);
}

int		main(int argc, char **argv)
{
	int i;
	int j;
	int k;
	int length;
	t_pile *a;
	t_pile *b;
	t_pile *c;
	char **tab;

	length = get_length_args(argc - 1, argv + 1);
	a = init_pile(97, length);
	b = init_pile(98, length);
	c = init_pile(99, length);
	b->pile[0] = 0;
	i = 0;
	k = 0;
	while (i < argc - 1)
	{
		j = 0;
		tab = NULL;
		tab = ft_strsplit(argv[i + 1], ' ');
		while (tab[j])
		{
			a->pile[k] = ft_atoi(tab[j]);
			c->pile[k] = a->pile[k];
			ft_strdel(&tab[j]);
			k++;
			j++;
		}
		free(tab);
		i++;
	}
	if (argc > 1)
	{
		order_numbers(a, c);
		sort_algo2(a, b);
	}
	// last_check(a);
	return (0);
}
