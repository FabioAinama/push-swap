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

void	last_check(int *pile)
{
	int i;

	i = 0;
	while (pile[i] != 0)
	{
		if (pile[i] > pile[i + 1] && pile[i + 1] != 0)
		{
			printf("\x1B[31m------------------FAIL------------------\n");
			break;
		}
		i++;
	}
	if (pile[i] == 0)
		printf("\x1B[32m------------------SUCCESS------------------\n");
}
