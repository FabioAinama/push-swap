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

	int length;
	t_pile *a;
	t_pile *b;
	t_pile *c;

	length = get_length_args(argc - 1, argv + 1);
	a = init_pile(97, length);
	b = init_pile(98, length);
	c = init_pile(99, length);
	b->pile[0] = 0;
	fill_piles(a, c, argc, argv);
	if (argc > 1)
	{
		order_numbers(a, c);
		sort_algo2(a, b);
	}
	return (1);
}
