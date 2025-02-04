/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrainyk <mkrainyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:37:36 by mkrainyk          #+#    #+#             */
/*   Updated: 2025/02/04 14:01:44 by mkrainyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

static int	find_min_position(t_stack *stack)
{
	t_stack	*min_node;
	t_stack	*current;
	int		min_pos;
	int		pos;

	min_node = stack;
	current = stack;
	min_pos = 0;
	pos = 0;
	while (current)
	{
		if (current->index < min_node->index)
		{
			min_node = current;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

void	sort_small(t_stack **a, t_stack **b)
{
	int	min_pos;

	while (stack_size(*a) > 3)
	{
		min_pos = find_min_position(*a);
		while (min_pos--)
			ra(a);
		pb(a, b);
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}
