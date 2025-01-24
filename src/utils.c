#include "../push_swap.h"

void free_stack(t_stack **stack)
{
	while (*stack)
		pop(stack);
}

void free_split(char **s)
{
    int i = 0;

    while (s[i])
    {
        free(s[i]);
        i++;
    }
    free(s);
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

int get_min_value(t_stack *stack)
{
	int min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return min;
}