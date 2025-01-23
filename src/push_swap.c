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

void push(t_stack **stack, int value)
{
	t_stack *new_node = malloc(sizeof(t_stack));
	if (!new_node)
		handle_error();
	new_node->value = value;
	new_node->next = *stack;
	*stack = new_node;
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
	if (size <= 3)
		sort_small_stack(stack_a, stack_b, size);
	else
		sort_large_stack(stack_a, stack_b, size);
}

int main(int ac, char **av)
{
	t_stack *stack_a = NULL;
	t_stack *stack_b = NULL;

	if (ac < 2)
	{
		ft_printf("Usage: ./push_swap [number]\n");
		return (1);
	}
	int i = ac - 1;
	while (i > 0)
	{
		push(&stack_a, ft_atoi(av[i]));
		i--;
	}
	if (!is_sorted(stack_a))
		push_swap(&stack_a, &stack_b);

	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
