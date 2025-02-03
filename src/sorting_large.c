/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryna <maryna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:37:32 by mkrainyk          #+#    #+#             */
/*   Updated: 2025/02/03 19:03:37 by maryna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int get_max_bits(t_stack **stack)
{
    t_stack *head;
    int     max;
    int     max_bits;

    head = *stack;
    max = head->index;
    max_bits = 0;
    while (head)
    {
        if (head->index > max)
            max = head->index;
        head = head->next;
    }
    while ((max >> max_bits) != 0)
        max_bits++;
    return (max_bits);
}

void radix_sort(t_stack **stack_a, t_stack **stack_b)
{
    int i = 0;
    int size = stack_size(*stack_a);
    int max_bits = get_max_bits(stack_a);

    while (i < max_bits)
    {
        int j = 0;
        while (j++ < size)
        {
            if ((((*stack_a)->index >> i) & 1) == 1)
                ra(stack_a);
            else
                pb(stack_a, stack_b);
        }
        while (*stack_b)
            pa(stack_a, stack_b);
        if (is_sorted(*stack_a))
            break;
        i++;
    }
}

