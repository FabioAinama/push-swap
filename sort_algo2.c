
#include "push-swap.h"

// int		push_to_merge(t_pile *a, t_pile *b)
// {
// 	int operations;
	
// 	operations = 0;
// 	while (b->pile[0] != 0)
// 	{
// 		printf("Going to Push into A\n");
// 		operations += push_pile2(b, a);
// 		print_piles(a->pile, b->pile);
// 		while (a->pile[0] == a->pile[a->len - 1] + 1)
// 		{
// 			printf("Going to Rotate A\n");			
// 			operations += rotate_pile2(a);
// 		}

// 	}
// 	operations += rotate_pile2(a);
// 	return (operations);
// }

int		push_to_merge(t_pile *a, t_pile *b)
{
	int operations;
	
	operations = 0;
	printf("Going to Reverse Rotate B\n");
	operations += reverse_rotate_pile2(b);
	printf("Going to Push into A\n");
	operations += push_pile2(b, a);
	printf("Going to Rotate A\n");
	operations += rotate_pile2(a);
	while (b->pile[0] != 0)
	{
		printf("Going to Push into A\n");
		operations += push_pile2(b, a);
		print_piles(a->pile, b->pile);
		while (a->pile[0] == a->pile[a->len - 1] + 1)
		{
			printf("Going to Rotate A\n");			
			operations += rotate_pile2(a);
		}

	}
	return (operations);
}

int		end_sort(t_pile *a, t_pile *b)
{
	int operations;
	int over;

	operations = 0;
	over = 100;
	// printf("Min B: %d, Last Sorted A: %d\n", b->min, a->last_sorted);
	while (a->last_sorted != (a->len + b->len))
	{
		// printf("Min B: %d, Last Sorted A: %d\n", b->min, a->last_sorted);
		if (b->min == (a->last_sorted + 1))
		{
			// printf("Entering condition 1\n");
			operations += push_min_to_top(b, a);
			// if (b->pile[0] == 1)
			// 	a->last_sorted = 1;
			operations += push_pile2(b, a);
			// operations += rotate_pile2(a);
			// find_last_sorted(a);
			// print_piles(a->pile, b->pile);
			b->min = 0;
			find_min(b);
		}
		else if (a->pile[0] != (a->pile[a->len - 1] + 1))
		{
			// printf("Going to Push into B\n");
			operations += push_pile2(a, b);
			// operations += order_b2(b);
			operations += order_b_reverse(b);
			// print_piles(a->pile, b->pile);
			// printf("Max B: %d, Min B: %d\n", b->max, b->min);
		}
		else
		{
			// printf("Going to Rotate A\n");
			operations += rotate_pile2(a);
			// print_piles(a->pile, b->pile);
			a->last_sorted = a->pile[a->len - 1];
		}
		over--;
		// printf("Nombre operation inside End-Sort: %d\n", operations);
	}
	return (operations);
}

void	sort_algo2(t_pile *a, t_pile *b)
{
	int half;
	int condition;
	int operations;

	operations = 0;
	a->len = get_pile_length(a->pile);
	b->len = get_pile_length(b->pile);
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
			operations++;
		}
		else
		{
			operations += push_pile2(a, b);
			operations += order_b2(b);
		}
		print_piles(a->pile, b->pile);
	}
	printf("Number of operations 1: %d\n", operations);	
	printf("\nEnd of Split Half: \n\n");
	// End split in half
	operations += push_to_merge(a, b);
	a->last_sorted = a->pile[a->len - 1];
	print_piles(a->pile, b->pile);	
	printf("Number of operations 2: %d\n", operations);
	operations += end_sort(a, b);
	printf("Number of operations 3: %d\n", operations);
	print_piles(a->pile, b->pile);	
}