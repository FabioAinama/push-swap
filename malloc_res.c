/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_res.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 14:25:05 by fginja-d          #+#    #+#             */
/*   Updated: 2018/10/18 14:25:07 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*malloc_res(t_pile *a, t_pile *b, int fd, int length)
{
	int *res;

	res = NULL;
	if (!(res = (int *)malloc(sizeof(int) * length)))
	{
		close_fd(fd);
		exit_all(a, b, 1);
	}
	ft_memset(res, 0, ((length) * sizeof(int)));
	return (res);
}
