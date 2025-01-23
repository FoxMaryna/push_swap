#include "../push_swap.h"

void free_stack(t_stack **stack)
{
	while (*stack)
		pop(stack);
}

int is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int stack_size(t_stack *stack)
{
	int size = 0;
	while(stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void handle_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}