/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryna <maryna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:37:09 by mkrainyk          #+#    #+#             */
/*   Updated: 2025/02/04 01:17:29 by maryna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void push(t_stack **dst, t_stack **src)
{
    t_stack *temp;

    if (!*src)
        return;
    temp = *src;
    *src = (*src)->next;
    temp->next = *dst;
    *dst = temp;
}

void pa(t_stack **a, t_stack **b)
{
    push(a, b);
    ft_printf("pa\n");
}

void pb(t_stack **a, t_stack **b)
{
    push(b, a);
    ft_printf("pb\n");
}


