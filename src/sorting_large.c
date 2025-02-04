/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrainyk <mkrainyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:37:32 by mkrainyk          #+#    #+#             */
/*   Updated: 2025/02/04 13:54:21 by mkrainyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;
	int	num;

	max_bits = 0;
	size = stack_size(*a);
	i = -1;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			num = (*a)->index;
			if ((num >> i) & 1)
				ra(a);
			else
				pb(a, b);
		}
		while (*b)
			pa(a, b);
	}
}
