/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 11:37:44 by fginja-d          #+#    #+#             */
/*   Updated: 2018/10/06 11:44:06 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

t_pile		*init_pile(int c, int length)
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

int			get_length_args(int argc, char **argv)
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

static	int		check_only_digits(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0 && str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

// A modifier pour passer directement le bon argc et argv
int			fill_piles(t_pile *a, t_pile *c, int argc, char **argv)
{
	int i;
	int j;
	int k;
	char **tab;
	long ln;

	i = -1;
	k = argc - 2;
	while (++i < argc - 1)
	{
		j = -1;
		tab = ft_strsplit(argv[i + 1], ' ');
		while (tab[++j])
		{
			ln = ft_atol(tab[j]);
			if (ln > INT_MAX || check_only_digits(tab[j]) == 0)
				return (-1);
			a->pile[k] = ln;
			c->pile[k] = a->pile[k];
			ft_strdel(&tab[j]);
			k--;
		}
		free(tab);
	}
	return (0);
}

int			fill_pile(t_pile *a, int argc, char **argv)
{
	int i;
	int j;
	int k;
	char **tab;
	long ln;

	i = 0;
	k = argc - 1;
	a->pile[k + 1] = 0;
	while (i < argc)
	{
		j = 0;
		tab = NULL;
		tab = ft_strsplit(argv[i], ' ');
		while (tab[j])
		{
			// printf("tab[%d]: %s", j, tab[j]);
			ln = ft_atol(tab[j]);
			// printf("ln: %ld", ln);
			if (ln > INT_MAX || check_only_digits(tab[j]) == 0)
				return (-1);
			a->pile[k] = ln;
			ft_strdel(&tab[j]);
			k--;
			j++;
		}
		free(tab);
		i++;
	}
	return (0);
}
