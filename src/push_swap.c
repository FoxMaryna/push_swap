/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrainyk <mkrainyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:52:19 by mkrainyk          #+#    #+#             */
/*   Updated: 2024/12/18 16:00:58 by mkrainyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node *new_node(int value)
{
	t_node *node = malloc(sizeof(t_node));
	if(!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

t_node *stack_init(int ac, char **av)
{
	t_node *stack = NULL;
	t_node *current;
	int i;
	int value;

	i = 1;
	while (i < ac)
	{
		value = ft_atoi(av[i]); // wirhout validation
		t_node *new = new_node(value);
		if (!new)
			return (free_stack(&stack), NULL);
		if (!stack)
			stack = new;
		else
			current->next = new;
		current = new;
		i++;
	}
	return (stack);
}

void free_srack(t_node **stack)
{
	t_node *tmp;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		ft_printf("Usage: ./push_swap [numbers]\n");
		return (1);
	}
	t_node *stack = stack_init(ac, av);
	if (!stack)
	{
		ft_printf("Error\n");
		return (1);
	}
	ft_printf("Stack initialized:\n");
	print_stack(stack);
	free_stack(&stack);
	return (0);
}