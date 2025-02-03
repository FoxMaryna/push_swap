/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryna <maryna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:37:15 by mkrainyk          #+#    #+#             */
/*   Updated: 2025/02/03 17:58:03 by maryna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void reverse_rotate(t_stack **stack)
{
    t_stack *last, *second_last;

    if (!*stack || !(*stack)->next)
        return;
    last = *stack;
    second_last = NULL;
    while (last->next)
    {
        second_last = last;
        last = last->next;
    }
    last->next = *stack;
    *stack = last;
    second_last->next = NULL;
}

void rra(t_stack **stack_a)
{
    reverse_rotate(stack_a);
    ft_printf("rra\n");
}

void rrb(t_stack **stack_b)
{
    reverse_rotate(stack_b);
    ft_printf("rrb\n");
}

void rrr(t_stack **stack_a, t_stack **stack_b)
{
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
    ft_printf("rrr\n");
}