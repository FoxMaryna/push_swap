/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrainyk <mkrainyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:52:19 by mkrainyk          #+#    #+#             */
/*   Updated: 2025/02/02 14:52:25 by mkrainyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_string_array(char **array)
{
	int	i;
	
	if (!array)
		return ;
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	populate_stack(t_stack **stack, char **tokens)
{
	int	i;
	
	i = 0;
	while (tokens[i])
	{
		if (!is_valid_number(tokens[i]))
			handle_error(stack, NULL);
		push(stack, ft_atoi(tokens[i]));
		i++;
	}
	if (has_duplicates(*stack))
		handle_error(stack, NULL);
}

int	is_valid_number(char *str)
{
	int	i;
	
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*checker;

	current = stack;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->value == checker->value)
				return (1);
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}

// void	push(t_stack **stack, int value)
// {
// 	t_stack	*new_node;
// 	t_stack	*current;
	
// 	new_node = malloc(sizeof(t_stack));
// 	if (!new_node)
// 		handle_error();
// 	new_node->value = value;
// 	new_node->next = NULL;
// 	if (*stack == NULL)
// 		*stack = new_node;
// 	else
// 	{
// 		current = *stack;
// 		while (current->next)
// 			current = current->next;
// 		current->next = new_node;
// 	}
// }

// int	pop(t_stack **stack)
// {
// 	t_stack	*temp;
// 	int		value;

// 	if (!*stack)
// 		return (0);
// 	temp = *stack;
// 	value = temp->value;
// 	*stack = temp->next;
// 	free(temp);
// 	return (value);
// }

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	if (size <= 5)
		sort_small_stack(stack_a, stack_b, size);
	else if (size <= 100)
		quicksort_stack(stack_a, stack_b, size);
	else
		radix_sort(stack_a, stack_b, size);
}
