#include "../push_swap.h"

void sa(t_stack **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return;
	int temp = (*stack_a)->value;
	(*stack_a)->value = (*stack_a)->next->value;
	(*stack_a)->next->value = temp;
	ft_printf("sa\n");
}

void sb(t_stack **stack_b)
{
	if (!*stack_b || !(*stack_b)->next)
		return;
	int temp = (*stack_b)->value;
	(*stack_b)->value = (*stack_b)->next->value;
	(*stack_b)->next->value = temp;
	ft_printf("sb\n");
}

void ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
}