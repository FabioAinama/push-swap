
#include "push-swap.h"

int		quicksort(t_pile *a, t_pile *b, int pivot, int *res)
{
	int op;

	op = 0;
	while (a->pile[a->len - 1] <= pivot && a->pile[a->len - 1] != 1)
	{
		if (a->pile[a->len - 1] == a->pile[0] + 1)
			op += rotate_pile(a, 1, res);
		else
			op += push_pile(a, b, 1, res);
	}
	if (b->len != 0)
		op += push_to_merge(a, b, res);
	return (op);
}

int		quicksort_split(t_pile *a, t_pile *b, int pivot, int *res)
{
	int avg;
	int op;
	int nb_rot;

	op = 0;
	nb_rot = 0;
	if (!(avg = get_average_pivot(a, pivot)))
		return (0);
	while (a->pile[a->len - 1] <= pivot && a->pile[a->len - 1] != 1)
	{
		if (a->pile[a->len - 1] >= avg)
		{
			op += rotate_pile(a, 1, res);
			nb_rot++;
		}
		else
			op += push_pile(a, b, 1, res);
	}
	while (nb_rot--)
	{
		if (b->pile[b->len - 1] < b->pile[0] && b->len > 1)
			op += reverse_rotate_both(a, b, 1, res);
		else
			op += reverse_rotate_pile(a, 1, res);
	}
	if (b->len != 0)
		op += push_to_merge(a, b, res);
	op += quicksort(a, b, pivot, res);
	return (op);
}

int		push_to_merge(t_pile *a, t_pile *b, int *res)
{
	int op;
	int pivot;
	int length;

	length = b->len;
	op = 0;
	if (b->len == 0)
		return (op);
	pivot = find_max(b);
	get_average(b);
	while (length)
	{
		if (b->len <= 13)
		{
			op += push_number_to_top(b, a, b->max, res);
			op += push_pile(b, a, 1, res);
		}
		else if (b->pile[b->len - 1] == 1 || b->pile[b->len - 1] == (a->pile[0] + 1))
		{
			op += push_pile(b, a, 1, res);
			if (b->pile[b->len - 1] < b->avg && b->pile[b->len - 1] != (a->pile[0] + 2) && b->len > 1)
				op += rotate_both(a, b, 1, res);
			else
				op += rotate_pile(a, 1, res);
		}
		else if (b->pile[b->len - 1] >= b->avg)
			op += push_pile(b, a, 1, res);
		else
			op += rotate_pile(b, 1, res);
		length--;
	}
	while (!sorted(a) && (a->pile[a->len - 1] == 1 || a->pile[a->len - 1] == (a->pile[0] + 1)))
	{
		if (b->pile[b->len - 1] < b->pile[0] && b->len > 1)
			op += rotate_both(a, b, 1, res);
		else
			op += rotate_pile(a, 1, res);
	}
	op += push_to_merge(a, b, res);
	op += quicksort_split(a, b, pivot, res);
	return (op);
}

void	sort_algo(t_pile *a, t_pile *b, int fd)
{
	int *res;
	int pivot;

	res = (int *)malloc(sizeof(int) * 1000);
	ft_memset(res, 0, 1000);
	find_max(a);
	pivot = a->len / 2;
	if (a->len % 2 != 0)
		pivot++;
	split_a(a, b, pivot, res);
	push_to_merge(a, b, res);
	quicksort_split(a, b, a->max, res);
	reduce_result(res);
	convert_result(res, fd);
}
