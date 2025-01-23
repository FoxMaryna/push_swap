#include "../push_swap.h"

void sort_two(t_stack **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

void sort_three(t_stack **stack_a)
{
	if (is_sorted(*stack_a))
		return;
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
	if (!is_sorted(*stack_a))
	{
		ra(stack_a);
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
		rra(stack_a);
	}
}

void sort_small_stack(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else
	{
		while (stack_size(*stack_a) > 3)
			pb(stack_a, stack_b);
		sort_three(stack_a);
		while (*stack_b)
			pa(stack_b, stack_a);
	}
}

void sort_large_stack(t_stack **stack_a, t_stack **stack_b, int size)
{
	int max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	int i = 0;
	int j;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*stack_a)->value >> i) & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			j++;
		}
		while (*stack_b)
			pa(stack_b, stack_a);
		i++;
	}
}