#include "../push_swap.h"

void ra(t_stack **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return;
	t_stack *temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = NULL;
	t_stack *last = *stack_a;
	while (last->next)
	{
		last = last->next;
	}
	last->next = temp;
	ft_printf("ra\n");
}

void rb(t_stack **stack_b)
{
	if (!*stack_b || !(*stack_b)->next)
		return;
	t_stack *temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = NULL;
	t_stack *last = *stack_b;
	while (last->next)
		last = last->next;
	last->next = temp;
	ft_printf("ra\n");
}

void rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_printf("rr\n");
}
