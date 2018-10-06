/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 01:24:53 by fginja-d          #+#    #+#             */
/*   Updated: 2018/09/28 01:24:55 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

void	last_check(t_pile *p)
{
	int i;

	i = 0;
	while (p->pile[i] != 0)
	{
		if (p->pile[i] > p->pile[i + 1] && p->pile[i + 1] != 0)
		{
			ft_putendl("\x1B[31mKO");
			break;
		}
		i++;
	}
	if (p->pile[i] == 0)
		ft_putendl("\x1B[32mOK");
}
