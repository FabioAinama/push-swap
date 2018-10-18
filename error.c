/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 14:46:56 by fginja-d          #+#    #+#             */
/*   Updated: 2018/10/11 14:46:59 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_duplicates(t_pile *a, int nb, int until)
{
	int i;

	i = a->len - 1;
	while (i > until)
	{
		if (nb == a->pile[i])
			return (1);
		--i;
	}
	return (0);
}

void	free_both_piles(t_pile *a, t_pile *b)
{
	if (a != NULL)
	{
		free(a->pile);
		free(a);
	}
	if (b != NULL)
	{
		free(b->pile);
		free(b);
	}
}

void	free_pile(t_pile *p)
{
	if (p != NULL)
	{
		if (p->pile != NULL)
			free(p->pile);
		free(p);
	}
}

void	exit_all(t_pile *a, t_pile *b, int err)
{
	free_both_piles(a, b);
	if (err == 1)
		ft_putendl_fd("Error", 2);
	exit(0);
}

/*
**	Check if pile A is ordered and pile B empty then free
*/

void	last_check_free(t_pile *a, t_pile *b)
{
	int i;

	i = 0;
	while (a->pile[i] != 0)
	{
		if (a->pile[i] < a->pile[i + 1])
		{
			ft_putendl_fd("KO", 2);
			free_both_piles(a, b);
			return ;
		}
		i++;
	}
	if (a->pile[i] == 0 && b->pile[0] == 0 && a->len != 0)
		ft_putendl("OK");
	else
		ft_putendl_fd("KO", 2);
	free_both_piles(a, b);
}
