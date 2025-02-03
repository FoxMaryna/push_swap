/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryna <maryna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:37:09 by mkrainyk          #+#    #+#             */
/*   Updated: 2025/02/03 18:15:07 by maryna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void push(t_stack **stack, int value)
{
    t_stack *new_node;
    t_stack *last;
    
    new_node = malloc(sizeof(t_stack));
    if (!new_node)
        handle_error(stack, NULL);
    new_node->value = value;
    new_node->next = NULL;

    if (*stack == NULL)
    {
        *stack = new_node;
    }
    else
    {
        last = *stack;
        while (last->next != NULL)
            last = last->next;
        last->next = new_node;
    }
}

int pop(t_stack **stack)
{
    t_stack *temp;
    int value;

    if (!*stack)
        return (0);
    temp = *stack;
    value = temp->value;
    *stack = temp->next;
    free(temp);
    return (value);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	int	value;

	if (!*stack_b)
		return;
	value = pop(stack_b);
	push(stack_a, value);
	ft_printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	int	value;
	if (!*stack_a)
		return;
	value = pop(stack_a);
	push(stack_b, value);
	ft_printf("pb\n");
}