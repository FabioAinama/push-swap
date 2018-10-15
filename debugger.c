/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugger.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 09:00:44 by fginja-d          #+#    #+#             */
/*   Updated: 2018/10/11 09:00:46 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"


int	main(int ac, char **argv)
{
	char *line;
	char *line2;
	int fd;
	int fd2;
	int i;

	printf("Debuger launched\n");
	i = 0;
	if (ac == 3)
	{
		fd = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);

		while (get_next_line(fd, &line) > 0 && get_next_line(fd2, &line2) > 0)
		{
			if (ft_strcmp(line, line2) != 0)
			{
				printf("Diff: %s vs %s - Ligne %d\n", line, line2, i);
			}
			i++;
		}
	}

	return (0);
}