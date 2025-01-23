#include "../push_swap.h"

void pa(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_b)
		return;
	int value = pop(stack_b);
	push(stack_a, value);
	ft_printf("pa\n");
}

void pb(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a)
		return;
	int value = pop(stack_a);
	push(stack_b, value);
	ft_printf("pb\n");
}