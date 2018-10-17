/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_result.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 09:25:59 by fginja-d          #+#    #+#             */
/*   Updated: 2018/10/10 09:26:00 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

void		push_into_res(int *res, int value)
{
	int i;

	i = 0;
	while (res[i] != 0)
		i++;
	res[i] = value;
	res[i + 1] = 0;
}

/*
**	reduce_result take an array of int and will reduce contradictory operations
*/

void		reduce_result(int *t)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (t[i + 1] != 0)
	{
		if ((t[i] ^ t[i + 1]) == 15 || (t[i] == 1 && t[i + 1] == 1)
			|| (t[i] == 2 && t[i + 1] == 2) || (t[i] == 4 && t[i + 1] == 4))
		{
			j = i;
			while (t[j + 2] != 0)
			{
				t[j] = t[j + 2];
				t[j + 1] = t[j + 3];
				j += 2;
			}
			t[j] = 0;
			t[j + 1] = 0;
			i -= 2;
		}
		i++;
	}
}

/*
**	Following of convert_result
*/

static	int	convert_result_rotate(int res, int fd)
{
	if (res == 6)
		ft_putendl_fd("ra", fd);
	else if (res == 10)
		ft_putendl_fd("rb", fd);
	else if (res == 8)
		ft_putendl_fd("rr", fd);
	else if (res == 9)
		ft_putendl_fd("rra", fd);
	else if (res == 5)
		ft_putendl_fd("rrb", fd);
	else if (res == 7)
		ft_putendl_fd("rrr", fd);
	else
		return (0);
	return (1);
}

/*
**	First convert_result will convert the array of int into a string operation
**	Then it will write it into the correct file descriptor, then close it.
*/

void		convert_result(int *res, int fd)
{
	int i;

	i = -1;
	while (res[++i] != 0)
	{
		if (res[i] == 12)
			ft_putendl_fd("pa", fd);
		else if (res[i] == 3)
			ft_putendl_fd("pb", fd);
		else if (res[i] == 1)
			ft_putendl_fd("sa", fd);
		else if (res[i] == 2)
			ft_putendl_fd("sb", fd);
		else if (res[i] == 4)
			ft_putendl_fd("ss", fd);
		else if (convert_result_rotate(res[i], fd) == 0)
			ft_putendl_fd("Error", 2);
	}
	close_fd(fd);
}
