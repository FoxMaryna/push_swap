/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrainyk <mkrainyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:37:23 by mkrainyk          #+#    #+#             */
/*   Updated: 2025/02/02 11:43:39 by mkrainyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack **stack_a)
{
	int temp;

	if (!*stack_a || !(*stack_a)->next)
		return;
	temp = (*stack_a)->value;
	(*stack_a)->value = (*stack_a)->next->value;
	(*stack_a)->next->value = temp;
	ft_printf("sa\n");
}

void	sb(t_stack **stack_b)
{
	int temp;
	if (!*stack_b || !(*stack_b)->next)
		return;
	temp = (*stack_b)->value;
	(*stack_b)->value = (*stack_b)->next->value;
	(*stack_b)->next->value = temp;
	ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
}