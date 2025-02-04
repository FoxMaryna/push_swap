/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryna <maryna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:06:44 by mkrainyk          #+#    #+#             */
/*   Updated: 2025/02/04 21:20:19 by maryna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

void	error_exit(t_stack **a, t_stack **b)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	ft_printf("Error\n");
	exit(1);
}

long    ft_atol(const char *str)
{
    long    result;
    int        sign;
    int        i;

    result = 0;
    sign = 1;
    i = 0;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        if ((result > (LONG_MAX / 10)) || 
            (result == (LONG_MAX / 10) && (str[i] - '0') > (LONG_MAX % 10)))
        {
            errno = ERANGE;
            return (sign == 1 ? LONG_MAX : LONG_MIN);
        }
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result * sign);
}
