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

#include "push-swap.h"

static	void	free_both_piles(t_pile *a, t_pile *b)
{
	free(a->pile);
	free(b->pile);
	free(a);
	free(b);
}

void			free_pile(t_pile *p)
{
	free(p->pile);
	free(p);
}

void			exit_all(t_pile *a, t_pile *b)
{
	free_both_piles(a, b);
	ft_putendl_fd("Error", 2);
	exit(0);
}

void			last_check_free(t_pile *a, t_pile *b)
{
	int i;

	i = 0;
	while (a->pile[i] != 0)
	{
		if (a->pile[i] < a->pile[i + 1])
		{
			ft_putendl_fd("KO", 2);
			break ;
		}
		i++;
	}
	if (a->pile[i] == 0 && b->pile[0] == 0 && a->len != 0)
		ft_putendl("OK");
	else
		ft_putendl_fd("KO", 2);
	free_both_piles(a, b);
}
