/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrainyk <mkrainyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:52:19 by mkrainyk          #+#    #+#             */
/*   Updated: 2024/12/18 16:00:58 by mkrainyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void free_string_array(char **array)
{
    int i = 0;
    while (array[i])
        free(array[i++]);
    free(array);
}

// Заполнение стека из массива строк
void populate_stack(t_stack **stack, char **tokens)
{
    int i = 0;
    while (tokens[i])
    {
		if (!is_valid_number(tokens[i]))
		{
			handle_error();
			return;
		}
		push(stack, ft_atoi(tokens[i]));
        i++;
    }
}

int is_valid_number(char *str)
{
	int i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return 0;
		i++;
	}
	return 1;
}

void push(t_stack **stack, int value)
{
	   t_stack *new_node = malloc(sizeof(t_stack));
    if (!new_node)
        handle_error();
    new_node->value = value;
    new_node->next = NULL;

    if (*stack == NULL)
    {
        *stack = new_node;
    }
    else
    {
        t_stack *current = *stack;
        while (current->next)
            current = current->next;
        current->next = new_node;
    }
}

int pop(t_stack **stack)
{
	if (!*stack)
		return (0);
	t_stack *temp = *stack;
	int value = temp->value;
	*stack = temp->next;
	free(temp);
	return (value);
}

void push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int size = stack_size(*stack_a);
	ft_printf("Stack size: %d\n", size);

	if (size <= 5)
	{
		ft_printf("Using sort_small_stack\n");
		sort_small_stack(stack_a, stack_b, size);
	}
	else if (size <= 100)
	{
		ft_printf("Using quicksort_stack\n");
		quicksort_stack(stack_a, stack_b, size);
	}
	else
	{
		ft_printf("Using radix_sort\n");
		radix_sort(stack_a, stack_b, size);
	}
}

int main(int ac, char **av)
{
	t_stack *stack_a = NULL;
	t_stack *stack_b = NULL;
	char **tokens;

	if (ac < 2)
	{
		ft_printf("Usage: ./push_swap [number]\n");
		return (1);
	}
	av++;
	while(--ac)
	{
		tokens = ft_split(*av, ' ');
		if (!tokens)
		{
			free_stack(&stack_a);
			handle_error();
		}
		populate_stack(&stack_a, tokens);
		free_string_array(tokens);
		av++;
	}

	push_swap(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
