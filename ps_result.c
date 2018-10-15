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

void	push_into_res(int *res, int value)
{
	int i;

	i = 0;
	while (res[i] != 0)
		i++;
	res[i] = value;
	res[i + 1] = 0;
}

void	print_result(int *res, int fd)
{
	int i;
	(void)fd;

	i = 0;
	while (res[i] != 0)
	{
		ft_putnbr(res[i]);
		ft_putstr("\n");
		// ft_putnbr_fd(res[i], fd);
		// ft_putstr("\n", fd);
		i++;
	}
}

void	reduce_result(int *res)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (res[i + 1] != 0)
	{
		if ((res[i] ^ res[i + 1]) == 15 || (res[i] == 1 && res[i + 1] == 1)
			|| (res[i] == 2 && res[i + 1] == 2) || (res[i] == 4 && res[i + 1] == 4))
		{
			j = i;
			while (res[j + 2] != 0)
			{
				res[j] = res[j + 2];
				res[j + 1] = res[j + 3];
				j += 2;
			}
			res[j] = 0;
			res[j + 1] = 0;
			i -= 2;
		}
		i++;
	}
}

void	convert_result(int *res, int fd)
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
		else if (res[i] == 6)
			ft_putendl_fd("ra", fd);
		else if (res[i] == 10)
			ft_putendl_fd("rb", fd);
		else if (res[i] == 8)
			ft_putendl_fd("rr", fd);
		else if (res[i] == 9)
			ft_putendl_fd("rra", fd);
		else if (res[i] == 5)
			ft_putendl_fd("rrb", fd);
		else if (res[i] == 7)
			ft_putendl_fd("rrr", fd);
		else
			ft_putendl_fd("WHAT?!!!!!!!!!!", fd); // Eror need to be throwned
	}
}
