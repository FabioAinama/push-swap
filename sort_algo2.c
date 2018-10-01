
#include "push-swap.h"

int		push_to_merge(int *p_a, int *p_b)
{
	int operations;
	
	operations = 0;
	while (p_b[0] != 0)
	{
		
	}
	return (operations);
}

void	sort_algo2(int *pile_a, int *pile_b)
{
	int a_length;
	int half;
	int b_length;
	int operations;
	int i;

	operations = 0;
	a_length = get_pile_length(pile_a);
	b_length = get_pile_length(pile_b);
	half = a_length / 2;
	printf("\nSort Algo: \n\n");
	// Split in half
	while (a_length > half + 1)
	{
		if (pile_a[0] > half)
		{
			if (pile_b[0] < pile_b[b_length - 1])
				rotate_both(pile_a, pile_b);
			else
				rotate_pile(pile_a);
		}
		else
		{
			push_pile(pile_a, pile_b);
			b_length++;
			a_length--;
			operations += order_b2(pile_b);
		}
		operations++;
		print_piles(pile_a, pile_b);
	}
	// End split in half
	printf("Number of operations: %d\n", operations);
}