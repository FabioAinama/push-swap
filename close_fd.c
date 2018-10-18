/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 16:33:30 by fginja-d          #+#    #+#             */
/*   Updated: 2018/10/18 16:33:33 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		close_fd(int fd)
{
	if (fd > 2)
		close(fd);
	return (0);
}

void	close_all_fd(t_fd *fd)
{
	close_fd(fd->read_fd);
	close_fd(fd->vis_fd);
	close_fd(fd->inst_fd);
}
