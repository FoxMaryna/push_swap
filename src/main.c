/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrainyk <mkrainyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:48:07 by mkrainyk          #+#    #+#             */
/*   Updated: 2025/02/02 14:27:13 by mkrainyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**tokens;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
	{
		ft_printf("Usage: ./push_swap [number]\n");
		return (1);
	}
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
