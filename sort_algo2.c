
#include "push-swap.h"

int		push_to_merge(t_pile *a, t_pile *b)
{
	int op;

	op = 0;
	if (b->len == 0)
		return (op);
	find_max(b);
	get_average(b);
	if (b->pile[0] == 1 || b->pile[0] == (a->pile[a->len - 1] + 1))
	{
		op += push_pile2(b, a);
		op += rotate_pile2(a);
	}
	else if (b->pile[0] >= b->avg)
		op += push_pile2(b, a);
	else
		op += rotate_pile2(b);
	while (!sorted(a) && (a->pile[0] == 1 || a->pile[0] == a->pile[a->len - 1] + 1))
		op += rotate_pile2(a);
	op += push_to_merge(a, b);
	return (op);
}

int		push_to_pile_until(t_pile *a, t_pile *b, int nb)
{
	int op;

	op = 0;
	while (a->pile[0] != nb)
	{
		if (a->pile[0] == (a->pile[a->len - 1] + 1))
			op += rotate_pile2(a);
		else
			op += push_pile2(a, b);
	}
	op += push_pile2(a, b);
	op += rotate_pile2(a);
	return (op);
}

int		end_sort_backtrack(t_pile *a, t_pile *b)
{
	int next;
	int op;
	
	// next = find_first_error(a); // avant
	next = a->pile[a->len - 1] + 1; // apres
	if (a->pile[0] == 1 && b->pile[0] == 0)
		return (0);
	op = 0;
	printf("Next to order: %d\n", next);
	if (contain_number(b, next))
	{
		printf("Going to find %d in B to push it into A\n", next);
		// op += push_to_merge(a, b); // Test
		op += push_number_to_top(b, a, next);
		op += push_pile2(b, a);
		op += rotate_pile2(a);
		print_piles(a->pile, b->pile);
	}
	else
	{
		printf("Going to push to B until finding %d\n", next);
		while (a->pile[0] != next)
		{
			if (a->pile[0] == 1)
				return 0;
			op += push_pile2(a, b);
			// op += order_b_reverse(b);
		}
		op += rotate_pile2(a);
		print_piles(a->pile, b->pile);
	}
	op += end_sort_backtrack(a, b);
	return (op);
}

void	sort_algo2(t_pile *a, t_pile *b)
{
	int half;
	int condition;
	int op;

	op = 0;
	a->len = get_pile_length(a->pile);
	b->len = get_pile_length(b->pile);
	find_max(a);
	half = a->len / 2;
	condition = half;
	if (a->len % 2 != 0)
		half++;
	printf("\nSort Algo 2: \n\n");
	printf("Half: %d, Condition: %d\n", half, condition);
	// Split in half
	while (a->len > condition)
	{
		if (a->pile[0] > half)
		{
			if (b->pile[0] < b->pile[b->len - 1])
				rotate_both(a->pile, b->pile);
			else
				rotate_pile2(a);
			op++;
		}
		else
			op += push_pile2(a, b);
		// print_piles(a->pile, b->pile);
	}
	print_piles(a->pile, b->pile);
	printf("Number of operations 1: %d\n", op);	
	printf("\n------------End of Split Half------------\n\n");
	// End split in half
	op += push_to_merge(a, b);
	print_piles(a->pile, b->pile);
	printf("Number of operations 2: %d\n", op);		
	a->last_sorted = a->pile[a->len - 1];
	op += end_sort_backtrack(a, b);
	print_piles(a->pile, b->pile);
	printf("Number of operations 3: %d\n", op);
}
