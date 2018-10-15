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

// A modifier pour passer directement le bon argc et argv
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
		fd = open(argv[2], O_CREAT|O_WRONLY, S_IRWXO);
		argv += 2;
		argc -= 2;
	}
	else
		fd = 1;
	length = get_length_args(argc - 1, argv + 1);
	a = init_pile('a', length);
	b = init_pile('b', length);
	c = init_pile('c', length);
	if (fill_piles(a, c, argc, argv) == -1)
	{
		free(c->pile);
		free(c);
		exit_all(a, b);
	}
	a->len = length;
	b->len = 0;
	c->len = a->len;
	ft_memset(b->pile, 0, length);
	if (argc > 2)
	{
		if (order_numbers(a, c) == -1)
		{
			free(c->pile);
			free(c);
			exit_all(a, b);
		}
		if (length <= 10)
			simple_sort(a, b, fd);
		else
			sort_algo(a, b, fd);
	}
	// print_piles(a, b);
	close(fd);
	return (0);
}
