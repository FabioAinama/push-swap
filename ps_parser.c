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

#include "push_swap.h"

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
	ft_memset(p->pile, 0, ((length + 1) * sizeof(int)));
	return (p);
}

static	int	check_only_digits(char *str)
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

static	int	free_tab_and_return(char **tab, int j)
{
	ft_strdel(&tab[j]);
	free(tab);
	return (-1);
}

int			fill_piles(t_pile *a, t_pile *c, int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	char	**tab;
	long	ln;

	i = -1;
	k = a->len - 1;
	while (++i < argc)
	{
		j = -1;
		tab = ft_strsplit(argv[i], ' ');
		while (tab[++j])
		{
			ln = ft_atol(tab[j]);
			if (ln > INT_MAX || check_only_digits(tab[j]) == 0)
				return (free_tab_and_return(tab, j));
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
	int		i;
	int		j;
	int		k;
	char	**tab;
	long	ln;

	i = -1;
	k = a->len - 1;
	while (++i < argc)
	{
		j = -1;
		tab = ft_strsplit(argv[i], ' ');
		while (tab[++j])
		{
			ln = ft_atol(tab[j]);
			if (ln > INT_MAX || !check_only_digits(tab[j])
				|| find_duplicates(a, ln, k))
				return (free_tab_and_return(tab, j));
			a->pile[k] = ln;
			ft_strdel(&tab[j]);
			k--;
		}
		free(tab);
	}
	return (0);
}
