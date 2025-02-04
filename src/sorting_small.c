/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryna <maryna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:37:36 by mkrainyk          #+#    #+#             */
/*   Updated: 2025/02/04 02:01:37 by maryna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void sort_three(t_stack **a)
{
    int first, second, third;

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

void sort_small(t_stack **a, t_stack **b)
{
    int size = stack_size(*a);
    int min_index = (*a)->index;
    int max_index = (*a)->index;

    t_stack *temp = *a;
    while (temp)
    {
        if (temp->index < min_index)
            min_index = temp->index;
        if (temp->index > max_index)
            max_index = temp->index;
        temp = temp->next;
    }

    while (size > 3)
    {
        if ((*a)->index == min_index || (*a)->index == max_index)
        {
            pb(a, b);
        }
        else if ((*a)->next->index == min_index || (*a)->next->index == max_index)
        {
            sa(a);
            pb(a, b);
        }
        else
        {
            rra(a);
        }
        size--;
    }
    
    sort_three(a);
    
    while (*b)
    {
        if ((*b)->index == max_index)
        {
            pa(a, b);
            ra(a);
        }
        else
        {
            pa(a, b);
        }
    }
}

