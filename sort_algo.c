
#include "push-swap.h"

int		quicksort(t_pile *a, t_pile *b, int pivot)
{
	int op;

	op = 0;
	while (a->pile[0] <= pivot && a->pile[0] != 1)
	{
		if (a->pile[0] == a->pile[a->len - 1] + 1)
			op += rotate_pile(a, 0);
		else
			op += push_pile(a, b);
	}
	if (b->len != 0)
		op += push_to_merge(a, b);
	return (op);
}

int		quicksort_split(t_pile *a, t_pile *b, int pivot)
{
	int avg;
	int op;
	int nb_rot;

	op = 0;
	nb_rot = 0;
	if (!(avg = get_average_pivot(a, pivot)))
		return (0);
	while (a->pile[0] <= pivot && a->pile[0] != 1)
	{
		if (a->pile[0] >= avg)
		{
			op += rotate_pile(a, 0);
			nb_rot++;
		}
		else
			op += push_pile(a, b);
	}
	while (nb_rot--)
	{
		if (b->pile[0] < b->pile[b->len - 1])
			op += reverse_rotate_both(a, b);
		else
			op += reverse_rotate_pile(a, 0);
	}
	if (b->len != 0)
		op += push_to_merge(a, b);
	op += quicksort(a, b, pivot);
	return (op);
}

int		push_to_merge(t_pile *a, t_pile *b)
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
		if (b->len <= 15)
		{
			op += push_number_to_top(b, a, b->max);
			op += push_pile(b, a);
		}
		else if (b->pile[0] == 1 || b->pile[0] == (a->pile[a->len - 1] + 1))
		{
			op += push_pile(b, a);
			op += rotate_pile(a, 0);
		}
		else if (b->pile[0] >= b->avg)
			op += push_pile(b, a);
		else
			op += rotate_pile(b, 0);
		length--;
	}
	while (!sorted(a) && (a->pile[0] == 1 || a->pile[0] == a->pile[a->len - 1] + 1))
		op += rotate_pile(a, 0);
	op += push_to_merge(a, b);
	op += quicksort_split(a, b, pivot);
	return (op);
}

void	sort_algo2(t_pile *a, t_pile *b)
{
	int pivot;
	int op;

	op = 0;
	a->len = get_pile_length(a->pile);
	b->len = get_pile_length(b->pile);
	find_max(a);
	pivot = a->len / 2;
	if (a->len % 2 != 0)
		pivot++;
	op += split_a(a, b, pivot);
	op += push_to_merge(a, b);
	op += quicksort_split(a, b, a->max);
}
