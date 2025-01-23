#include "../push_swap.h"

void rra(t_stack **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return;
	t_stack *prev = NULL;
	t_stack *curr = *stack_a;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = NULL;
	curr->next = *stack_a;
	*stack_a = curr;
	ft_printf("rra\n");
}

void rrb(t_stack **stack_b)
{
	if (!*stack_b || !(*stack_b)->next)
		return;
	t_stack *prev = NULL;
	t_stack *curr = *stack_b;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = NULL;
	curr->next = *stack_b;
	*stack_b = curr;
	ft_printf("rra\n");
}

void rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	ft_printf("rrr\n");
}