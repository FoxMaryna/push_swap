/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryna <maryna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:48:07 by mkrainyk          #+#    #+#             */
/*   Updated: 2025/02/03 11:15:02 by maryna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int main(int ac, char **av)
{
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;
    char **tokens;

    av++;
    while (--ac)
    {
        tokens = ft_split(*av, ' ');
        if (!tokens)
            handle_error(&stack_a, &stack_b);
        populate_stack(&stack_a, tokens);
        free_string_array(tokens);
        av++;
    }
    if (!is_sorted(stack_a))
        push_swap(&stack_a, &stack_b);
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}
