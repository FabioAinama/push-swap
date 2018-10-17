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
// Non ok
#include "push-swap.h"

int		init_all_piles(t_pile **a, t_pile **b, t_pile **c, int length)
{
	// if (!(*a = init_pile('a', length)))
	// 	return (0);
	// if (!(*b = init_pile('b', length)))
	// {
	// 	// free_pile(*a);
	// 	return (0);
	// }
	// if (!(*c = init_pile('c', length)))
	// {
	// 	// free_both_piles(*a, *b);
	// 	return (0);
	// }
	*a = init_pile('a', length);
	*b = init_pile('b', length);
	*c = init_pile('c', length);
	(*b)->len = 0;
	// ft_memset((*b)->pile, 0, length);
	return (1);
}

int		main(int argc, char **argv)
{
	int		length;
	int		fd;
	t_pile	*a;
	t_pile	*b;
	t_pile	*c;

	fd = 1;
	if (ft_strcmp(argv[1], "-f") == 0)
	{
		if ((fd = open(argv[2], O_CREAT|O_WRONLY, S_IRWXO)) == -1)
			return (0);
		argv += 2;
		argc -= 2;
	}
	length = get_length_args(argc - 1, argv + 1);
	if ((init_all_piles(&a, &b, &c, length)) == 0)
	{
		close_fd(fd);
		return (0);
	}
	if (fill_piles(a, c, argc - 1, argv + 1) == -1)
	{
		close_fd(fd);
		free_pile(c);
		exit_all(a, b);
	}
	if (a->len > 1)
	{
		if (order_numbers(a, c) == -1)
		{
			free_pile(c);
			exit_all(a, b);
		}
		free_pile(c);
		if (a->len <= 10)
			simple_sort(a, b, fd);
		else
			sort_algo(a, b, fd);
	}
	return (0);
}
