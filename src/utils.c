/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryna <maryna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:37:39 by mkrainyk          #+#    #+#             */
/*   Updated: 2025/02/04 01:40:01 by maryna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int stack_size(t_stack *stack)
{
    int size = 0;
    while (stack)
    {
        size++;
        stack = stack->next;
    }
    return size;
}

int is_sorted(t_stack *stack)
{
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return 0;
        stack = stack->next;
    }
    return 1;
}

void free_stack(t_stack **stack)
{
    t_stack *temp;

    while (*stack)
    {
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
}

t_stack *create_node(int value)
{
    t_stack *new = malloc(sizeof(t_stack));
    if (!new)
        return NULL;
    new->value = value;
    new->index = 0;
    new->next = NULL;
    return new;
}

void add_node_back(t_stack **stack, t_stack *new)
{
    t_stack *last;

    if (!*stack)
    {
        *stack = new;
        return;
    }
    last = *stack;
    while (last->next)
        last = last->next;
    last->next = new;
}

int get_min(t_stack *stack)
{
    int min = INT_MAX;

    while (stack)
    {
        if (stack->index < min)
            min = stack->index;
        stack = stack->next;
    }
    return min;
}

void index_stack(t_stack **stack)
{
    t_stack *current = *stack;
    t_stack *temp;
    int index = 0;

    while (current)
    {
        temp = *stack;
        while (temp)
        {
            if (temp->value < current->value)
                index++;
            temp = temp->next;
        }
        current->index = index;
        current = current->next;
        index = 0;
    }
}
