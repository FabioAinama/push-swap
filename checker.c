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

void	last_check(t_pile *a, t_pile *b)
{
	int i;

	i = 0;
	while (a->pile[i] != 0)
	{
		if (a->pile[i] < a->pile[i + 1])
		{
			ft_putendl_fd("KO", 2);
			break;
		}
		i++;
	}
	if (a->pile[i] == 0 && b->pile[0] == 0 && a->len != 0)
		ft_putendl("OK");
	else
		ft_putendl_fd("KO", 2);
}

int		ps_dispatcher(t_pile *a, t_pile *b, char *inst, int *res)
{
	if (ft_strcmp(inst, "ra") == 0)
		rotate_pile(a, 0, res);
	else if (ft_strcmp(inst, "rb") == 0)
		rotate_pile(b, 0, res);
	else if (ft_strcmp(inst, "rr") == 0)
		rotate_both(a, b, 0, res);
	else if (ft_strcmp(inst, "pa") == 0)
		push_pile(b, a, 0, res);
	else if (ft_strcmp(inst, "pb") == 0)
		push_pile(a, b, 0, res);
	else if (ft_strcmp(inst, "sa") == 0)
		swap_pile(a, 0, res);
	else if (ft_strcmp(inst, "sb") == 0)
		swap_pile(b, 0, res);
	else if (ft_strcmp(inst, "ss") == 0)
		swap_both(a, b, 0, res);
	else if (ft_strcmp(inst, "rra") == 0)
		reverse_rotate_pile(a, 0, res);
	else if (ft_strcmp(inst, "rrb") == 0)
		reverse_rotate_pile(b, 0, res);
	else if (ft_strcmp(inst, "rrr") == 0)
		reverse_rotate_both(a, b, 0, res);
	else
		return (0);
	return (1);
}

void	print_pile_fd(t_pile* a, int fd)
{
	int		i;
	char	*nb;

	i = a->len - 1;
	while (i >= 0)
	{
		nb = ft_itoa(a->pile[i]);
		ft_putendl_fd(nb, fd);
		ft_strdel(&nb);
		i--;
	}
}

int		main(int argc, char **argv)
{
	t_pile	*a;
	t_pile	*b;
	int		length;
	int		vis_fd;
	int		inst_fd;
	int		read_fd;
	int		*res;
	char	*line;

	vis_fd = -1;
	inst_fd = -1;
	if (argc == 1)
		return (0);
	argv++;
	argc--;
	if (ft_strcmp(argv[0], "-f") == 0)
	{
		if ((read_fd = open(argv[1], O_RDONLY)) == -1)
		{
			// Pas pu ouvrir le fd, surement quil ny a pas de fichier ou ecrire
			return (0);
		}
		argv += 2;
		argc -= 2;
	}
	else
		read_fd = 0;
	if (ft_strcmp(argv[0], "-v") == 0)
	{
		vis_fd = open("visualizer/numbers.txt", O_CREAT|O_TRUNC|O_RDWR, S_IRWXO);
		inst_fd = open("visualizer/instructions.txt", O_CREAT|O_TRUNC|O_RDWR, S_IRWXO);
		argv++;
		argc--;
	}
	res = (int *)malloc(sizeof(int) * 1000);
	ft_memset(res, 0, 1000);
	length = get_length_args(argc, argv);
	a = init_pile(97, length);
	b = init_pile(98, length);
	if (fill_pile(a, argc, argv) == -1)
		exit_all(a, b);
	if (vis_fd != -1)
		print_pile_fd(a, vis_fd);
	b->pile[0] = 0;
	a->len = get_pile_length(a->pile);
	b->len = 0;
	while (get_next_line(read_fd, &line) > 0)
	{
		if (inst_fd != -1)
			ft_putendl_fd(line, inst_fd);
		if (ps_dispatcher(a, b, line, res) == 0)
		{
			// printf("I'm going to exit\n");
			exit_all(a, b);
		}
		// ft_strdel(&line);
	}
	// free(line);
	last_check(a, b);
	return (0);
}