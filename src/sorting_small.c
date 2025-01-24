#include "../push_swap.h"

void sort_three(t_stack **stack_a)
{
    // Если первый элемент больше второго и третьего, сдвигаем его в конец (ra)
    if ((*stack_a)->value > (*stack_a)->next->value && (*stack_a)->value > (*stack_a)->next->next->value)
        ra(stack_a);

    // Если второй элемент больше первого и третьего, сдвигаем его в начало (rra)
    if ((*stack_a)->next->value > (*stack_a)->value && (*stack_a)->next->value > (*stack_a)->next->next->value)
        rra(stack_a);

    // Если первый элемент больше второго, меняем их местами (sa)
    if ((*stack_a)->value > (*stack_a)->next->value)
        sa(stack_a);
}

int get_index_of_value(t_stack *stack, int value)
{
	int i = 0;
	while (stack)
	{
		if (stack->value == value)
			return i;
		stack = stack->next;
		i++;
	}
	return -1;
}

void move_to_top(t_stack **stack, int i)
{
	int size;
	
	if (!stack || !*stack)
		return;
	
	size = stack_size(*stack);
	if (i < 0 || i >= size)
		return;
	if (i <= size / 2)
	{
		while (i > 0)
		{
			ra(stack);
			i--;
		}
	}
	else
	{
		while (i < size)
		{
			rra(stack);
			i++;
		}
	}
}

void sort_five(t_stack **stack_a, t_stack **stack_b, int size)
{
	int min_value;
	int i;

	while (size > 3)
	{
		min_value = get_min_value(*stack_a);
		i = get_index_of_value(*stack_a, min_value);
		move_to_top(stack_a, i);
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (stack_size(*stack_b) > 0)
		pa(stack_b, stack_a);
}

void sort_small_stack(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
	}
	else if (size == 3)
		sort_three(stack_a);
	else if (size <= 5)
		sort_five(stack_a, stack_b, size);
}
