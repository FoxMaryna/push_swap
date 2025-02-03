/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryna <maryna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:37:15 by mkrainyk          #+#    #+#             */
/*   Updated: 2025/02/03 11:26:42 by maryna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack **stack_a)
{
	t_stack *last, *second_last;
    
    if (!*stack_a || !(*stack_a)->next)
        return;
    last = *stack_a;
    second_last = NULL;
    while (last->next)
    {
        second_last = last;
        last = last->next;
    }
    last->next = *stack_a;
    *stack_a = last;
    second_last->next = NULL;
    ft_printf("rra\n");
}

void	rrb(t_stack **stack_b)
{
	t_stack *last, *second_last;
    
    if (!*stack_b || !(*stack_b)->next)
        return;
    last = *stack_b;
    second_last = NULL;
    while (last->next)
    {
        second_last = last;
        last = last->next;
    }
    last->next = *stack_b;
    *stack_b = last;
    second_last->next = NULL;
    ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	ft_printf("rrr\n");
}