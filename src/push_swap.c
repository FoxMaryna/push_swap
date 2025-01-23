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

int is_valid_number(char *str)
{
	int i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
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

	if (size <= 5)
		sort_small_stack(stack_a, stack_b, size);
	else if (size <= 100)
		quicksort_stack(stack_a, stack_b, size);
	else
		radix_sort(stack_a, stack_b, size);
}

int main(int ac, char **av)
{
	t_stack *stack_a = NULL;
	t_stack *stack_b = NULL;
	char **s;

	if (ac < 2)
	{
		ft_printf("Usage: ./push_swap [number]\n");
		return (1);
	}
	if (ac == 2)
		s = ft_split(av[1], ' ');
	else
		s = av + 1;
	int i = 1;
	while (s[i])
	{
		if (!is_valid_number(av[i]))
		{
			ft_printf("Error\n");
			return 1;
		}
		int num = ac - 1;
		while (num > 0)
		{
			push(&stack_a, ft_atoi(av[i]));
			num--;
		}
		i++;
	}
	if (!is_sorted(stack_a))
		push_swap(&stack_a, &stack_b);

	free_stack(&stack_a);
	free_stack(&stack_b);
	if (ac == 2)
	{
		int j = 0;
		while (av[j])
			free(s[j++]);
		free(s);
	}
	return (0);
}
