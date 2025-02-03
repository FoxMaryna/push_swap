/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryna <maryna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:37:32 by mkrainyk          #+#    #+#             */
/*   Updated: 2025/02/03 11:25:37 by maryna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void quicksort_array(int *arr, int low, int high)
{
    if (low < high)
    {
        int pivot = arr[high];
        int i = low - 1;
        int j, temp;

        for (j = low; j < high; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int partition_index = i + 1;
        quicksort_array(arr, low, partition_index - 1);
        quicksort_array(arr, partition_index + 1, high);
    }
}

int find_pivot(t_stack *stack, int size)
{
    int *values = malloc(sizeof(int) * size);
    if (!values)
        handle_error(NULL, NULL);

    t_stack *current = stack;
    for (int i = 0; i < size; i++)
    {
        values[i] = current->value;
        current = current->next;
    }

    quicksort_array(values, 0, size - 1); // Сортировка массива
    int pivot = values[size / 2];         // Средний элемент как pivot
    free(values);

    return pivot;
}

void quicksort_stack(t_stack **stack_a, t_stack **stack_b, int size)
{
    if (size <= 1)
        return;
    if (size == 2 && !is_sorted(*stack_a))
    {
        sa(stack_a);
        return;
    }

    int pivot = find_pivot(*stack_a, size);
    int pushed = 0;

    for (int i = 0; i < size; i++)
    {
        if ((*stack_a)->value < pivot)
        {
            pb(stack_a, stack_b);
            pushed++;
        }
        else
            ra(stack_a);
    }

    quicksort_stack(stack_a, stack_b, size - pushed);
    quicksort_stack(stack_b, stack_a, pushed);

    while (pushed-- > 0)
        pa(stack_b, stack_a);
}

int	get_max_value(t_stack *stack)
{
	int	max;
	
	max = stack->value;
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

    while ((max_num >> max_bits) != 0)
        max_bits++;

    for (int i = 0; i < max_bits; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if ((((*stack_a)->value >> i) & 1) == 0)
                pb(stack_a, stack_b);
            else
                ra(stack_a);
        }

        while (*stack_b)
            pa(stack_b, stack_a);
    }
}
