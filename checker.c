/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 01:24:53 by fginja-d          #+#    #+#             */
/*   Updated: 2018/09/28 01:24:55 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push-swap.h"

void	last_check(t_pile *p)
{
	int i;

	i = 0;
	while (p->pile[i] != 0)
	{
		if (p->pile[i] > p->pile[i + 1] && p->pile[i + 1] != 0)
		{
			ft_putendl("\x1B[31mKO");
			break;
		}
		i++;
	}
	if (p->pile[i] == 0)
		ft_putendl("\x1B[32mOK");
}

void	ps_dispatcher(t_pile *a, t_pile *b, char *inst)
{
	// printf("Actual inst: %s\n", inst);
	if (ft_strcmp(inst, "ra") == 0)
		rotate_pile(a, 0);
	else if (ft_strcmp(inst, "rb") == 0)
		rotate_pile(b, 0);
	else if (ft_strcmp(inst, "rr") == 0)
		rotate_both(a, b, 0);
	else if (ft_strcmp(inst, "pa") == 0)
		push_pile(b, a, 0);
	else if (ft_strcmp(inst, "pb") == 0)
		push_pile(a, b, 0);
	else if (ft_strcmp(inst, "sa") == 0)
		swap_pile(a, 0);
	else if (ft_strcmp(inst, "sb") == 0)
		swap_pile(b, 0);
	else if (ft_strcmp(inst, "ss") == 0)
		swap_both(a, b, 0);
	else if (ft_strcmp(inst, "rra") == 0)
		reverse_rotate_pile(a, 0);
	else if (ft_strcmp(inst, "rrb") == 0)
		reverse_rotate_pile(b, 0);
	else if (ft_strcmp(inst, "rrr") == 0)
		reverse_rotate_both(a, b, 0);
	// else
	// 	return (0);
	// return (1);
}

int		main(int argc, char **argv)
{
	char *line;
	int length;
	t_pile *a;
	t_pile *b;

	length = get_length_args(argc - 1, argv + 1);
	a = init_pile(97, length);
	b = init_pile(98, length);
	fill_pile(a, argc, argv);
	b->pile[0] = 0;
	while (get_next_line(0, &line))
	{
		// ps_dispatcher(a, b, line);
		ft_putendl(line);
		// if (ps_dispatcher(a, b, line) == 0)
		// {
		// 	ft_putendl("Error");
		// 	// return (0);
		// }
		ft_strdel(&line);
	}
	last_check(a);
	return (1);
}