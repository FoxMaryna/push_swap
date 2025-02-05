/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrainyk <mkrainyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:06:44 by mkrainyk          #+#    #+#             */
/*   Updated: 2025/02/05 12:51:09 by mkrainyk         ###   ########.fr       */
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

void	free_split(char **split)
{
	int i;

	if (!split)
		return;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	check_overflow(long result, int digit, int sign)
{
	if (result > LONG_MAX / 10 \
		|| (result == LONG_MAX / 10 && digit > LONG_MAX % 10))
	{
		errno = ERANGE;
		if (sign == 1)
			return (1);
		else
			return (-1);
	}
	return (0);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;
	int		overflow_check;

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
		overflow_check = check_overflow(result, str[i] - '0', sign);
		if (overflow_check == 1)
			return (LONG_MAX);
		else if (overflow_check == -1)
			return (LONG_MIN);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
