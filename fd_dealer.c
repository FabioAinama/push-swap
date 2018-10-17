/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_dealer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 17:01:18 by fginja-d          #+#    #+#             */
/*   Updated: 2018/10/16 17:01:20 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

/*
**	Initialize fd needed to visualizer or to read instructions
*/

t_fd	*init_fd_readers(t_fd *fd)
{
	if (!(fd = (t_fd*)malloc(sizeof(t_fd))))
		exit(0);
	fd->read_fd = 0;
	fd->vis_fd = -1;
	fd->inst_fd = -1;
	return (fd);
}

/*
**	Open instructions file descriptor
*/

int		open_inst(int argc, char **argv, t_fd *fd)
{
	if ((fd->read_fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putendl("Failed to open fd. Usage: ./checker -f [file]");
		free(fd);
		return (-1);
	}
	return (argc - 2);
}

/*
**	Open/create files needed to visualizer
*/

int		create_vis_files(t_fd *fd)
{
	fd->vis_fd = open("vis/numbers.txt", O_CREAT | O_TRUNC | O_RDWR, S_IRWXU);
	fd->inst_fd = open("vis/inst.txt", O_CREAT | O_TRUNC | O_RDWR, S_IRWXU);
	return (1);
}
