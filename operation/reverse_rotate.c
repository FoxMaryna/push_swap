/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrainyk <mkrainyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:37:15 by mkrainyk          #+#    #+#             */
/*   Updated: 2025/02/02 14:19:07 by mkrainyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack **stack_a)
{
	t_stack *prev;
	t_stack *curr;

	if (!*stack_a || !(*stack_a)->next)
		return;
	prev = NULL;
	curr = *stack_a;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = NULL;
	curr->next = *stack_a;
	*stack_a = curr;
	ft_printf("rra\n");
}

void	rrb(t_stack **stack_b)
{
	t_stack *prev;
	t_stack *curr;

	if (!*stack_b || !(*stack_b)->next)
		return;
	prev = NULL;
	curr = *stack_b;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = NULL;
	curr->next = *stack_b;
	*stack_b = curr;
	ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	ft_printf("rrr\n");
}