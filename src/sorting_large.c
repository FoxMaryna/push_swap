#include "../push_swap.h"

void quicksort_array(int *arr, int low, int high)
{
    if (low < high)
    {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int partition_index = i + 1;
        quicksort_array(arr, low, partition_index - 1);
        quicksort_array(arr, partition_index + 1, high);
    }
}

int find_pivot(t_stack *stack, int size)
{
    int *values;
    int pivot;
    int i;

    values = malloc(sizeof(int) * size);
    if (!values)
        return 0;

    for (i = 0; i < size; i++)
    {
        values[i] = stack->value;
        stack = stack->next;
    }
    quicksort_array(values, 0, size - 1);
    pivot = values[size / 2];
    free(values);
    return pivot;
}

void quicksort_stack(t_stack **stack_a, t_stack **stack_b, int size)
{
	int pivot;
	int pushed = 0;
	int rotated = 0;

	if (size <= 3)
	{
		sort_small_stack(stack_a, stack_b, size);
		return;
	}
	pivot = find_pivot(*stack_a, size);
	int i = 0;
	while (i < size)
	{
		if ((*stack_a)->value < pivot)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
		{
			ra(stack_a);
			rotated++;
		}
	}
	while (rotated-- > 0)
		rra(stack_a);

	quicksort_stack(stack_a, stack_b, size - pushed);
	quicksort_stack(stack_b, stack_a, pushed);

	while (pushed-- > 0)
	{
		pa(stack_b, stack_a);
	}
}

int get_max_value(t_stack *stack)
{
    int max = stack->value;
    while (stack)
    {
        if (stack->value > max)
            max = stack->value;
        stack = stack->next;
    }
    return max;
}

void radix_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int max_bits = 0;
	int max_num = get_max_value(*stack_a);
	int i;
	int j;
	while ((max_num >> max_bits) != 0)
		max_bits++;

	i = 0;
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
		i++;
	}
	while (stack_size(*stack_b) > 0)
		pa(stack_b, stack_a);
}