/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:04:38 by fginja-d          #+#    #+#             */
/*   Updated: 2018/09/24 19:04:40 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

int		main(int argc, char **argv)
{
	int fd;
	char *line;
	int length;
	t_pile *a;
	t_pile *b;
	t_pile *c;

	if (ft_strcmp(argv[1], "-f") == 0)
	{
		printf("-f Flag present\n");
		fd = open(argv[2], O_WRONLY);
		// while (get_next_line(fd, &line) > 0)
		// {
		// 	ft_putendl(line);
		// }
		argv += 2;
		argc -= 2;
	}
	else
	{
		fd = 1;
	}
	length = get_length_args(argc - 1, argv + 1);
	a = init_pile(97, length);
	b = init_pile(98, length);
	c = init_pile(99, length);
	fill_piles(a, c, argc, argv);
	while (length--)
		b->pile[length] = 0;
	b->pile[0] = 0;
	// Je dois check si tout est order, je retourne rien, et que je ne lance que si j'ai plus d'un arg
	if (argc > 1)
	{
		order_numbers(a, c);
		sort_algo(a, b, fd);
	}
	return (0);
}
