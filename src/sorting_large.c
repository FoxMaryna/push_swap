/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryna <maryna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:37:32 by mkrainyk          #+#    #+#             */
/*   Updated: 2025/02/04 01:40:30 by maryna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void sort_stack(t_stack **a, t_stack **b)
{
    int size = stack_size(*a);
    int max_bits = 0;
    int max = size - 1;
    int i, j;

    while ((max >> max_bits) != 0)
        ++max_bits;

    for (i = 0; i < max_bits; ++i)
    {
        for (j = 0; j < size; ++j)
        {
            int num = (*a)->index;
            if ((num >> i) & 1)
                ra(a);
            else
                pb(a, b);
        }
        while (*b)
            pa(a, b);
    }
}