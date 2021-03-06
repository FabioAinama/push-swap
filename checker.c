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

#include "push_swap.h"

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

void	print_pile_fd(t_pile *a, int fd)
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

void	checker_reader(t_pile *a, t_pile *b, t_fd *fd)
{
	char	*line;
	int		*res;

	line = NULL;
	if ((res = (int *)malloc(sizeof(int) * 10000)) == 0)
		exit_all(a, b, 1);
	ft_memset(res, 0, 10000);
	while (get_next_line(fd->read_fd, &line) > 0)
	{
		if (fd->inst_fd != -1)
			ft_putendl_fd(line, fd->inst_fd);
		if (ps_dispatcher(a, b, line, res) == 0)
		{
			free(fd);
			free(res);
			ft_strdel(&line);
			exit_all(a, b, 1);
		}
		ft_strdel(&line);
	}
	if (line != NULL)
		ft_strdel(&line);
	free(res);
}

void	checker(int argc, char **argv, t_fd *fd)
{
	int		length;
	t_pile	*a;
	t_pile	*b;

	length = get_length_args(argc, argv);
	if (!(a = init_pile(97, length)))
		return ;
	if (!(b = init_pile(98, length)))
		exit_all(a, b, 1);
	b->len = 0;
	if (fill_pile(a, argc, argv) == -1)
	{
		free(fd);
		exit_all(a, b, 1);
	}
	if (fd->vis_fd != -1)
		print_pile_fd(a, fd->vis_fd);
	checker_reader(a, b, fd);
	if (fd->vis_fd != -1 && fd->inst_fd != -1)
	{
		system("open -a \"Google Chrome\" \"http://localhost:8080/vis\"");
		system("ruby -run -e httpd . -p 8080");
	}
	last_check_free(a, b);
}

int		main(int argc, char **argv)
{
	t_fd	*fd;

	fd = NULL;
	fd = init_fd_readers(fd);
	if (argc == 1)
		return (0);
	argv++;
	argc--;
	if (ft_strcmp(argv[0], "-f") == 0)
	{
		if ((argc = open_inst(argc, argv, fd)) == -1)
			return (0);
		argv += 2;
	}
	if (ft_strcmp(argv[0], "-v") == 0)
	{
		argc -= create_vis_files(fd);
		argv++;
	}
	checker(argc, argv, fd);
	close_all_fd(fd);
	free(fd);
	return (0);
}
