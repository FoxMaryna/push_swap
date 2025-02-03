/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryna <maryna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:52:19 by mkrainyk          #+#    #+#             */
/*   Updated: 2025/02/03 19:01:13 by maryna           ###   ########.fr       */
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

void populate_stack(t_stack **stack, char **tokens)
{
    int i = 0;
    long num;
    
    while (tokens[i])
    {
        if (!is_valid_number(tokens[i]))
            handle_error(stack, NULL);
        num = ft_atoi(tokens[i]);
        if (num > INT_MAX || num < INT_MIN)
            handle_error(stack, NULL);
        push(stack, (int)num);
        i++;
    }
    if (has_duplicates(*stack))
        handle_error(stack, NULL);
}


int is_valid_number(char *str)
{
    long long num = 0;
    int sign = 1;
    int i = 0;
    
    if (str[i] == '-' || str[i] == '+')
    {
        sign = (str[i] == '-') ? -1 : 1;
        i++;
    }
    if (!str[i])
        return (0);
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        num = num * 10 + (str[i] - '0');
        if (num * sign > INT_MAX || num * sign < INT_MIN)
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

void normalize_stack(t_stack **stack)
{
    t_stack *current = *stack;
    t_stack *compare;
    int index;

    while (current)
    {
        index = 0;
        compare = *stack;
        while (compare)
        {
            if (current->value > compare->value)
                index++;
            compare = compare->next;
        }
        current->index = index;
        current = current->next;
    }
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
    normalize_stack(stack_a);
	if (size <= 5)
		sort_small_stack(stack_a, stack_b, size);
	else
		radix_sort(stack_a, stack_b);
}
