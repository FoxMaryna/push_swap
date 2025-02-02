/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrainyk <mkrainyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:37:09 by mkrainyk          #+#    #+#             */
/*   Updated: 2025/02/02 11:40:38 by mkrainyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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