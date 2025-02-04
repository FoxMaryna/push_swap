/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryna <maryna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:48:07 by mkrainyk          #+#    #+#             */
/*   Updated: 2025/02/04 21:22:04 by maryna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	has_duplicate(t_stack *a, int num)
{
	while (a)
	{
		if (a->value == num)
			return (1);
		a = a->next;
	}
	return (0);
}

static void	parse_numbers(char **nums, t_stack **a)
{
	long	num;
	int	j;

	j = 0;
	while (nums[j])
	{
		if (!is_number(nums[j]))
			error_exit(a, NULL);
		num = ft_atol(nums[j]);
		if (num > INT_MAX || num < INT_MIN || errno == ERANGE)
  			error_exit(a, NULL);
		if (has_duplicate(*a, num))
			error_exit(a, NULL);
		add_node_back(a, create_node(num));
		free(nums[j]);
		j++;
	}
	free(nums);
}

static void	parse_args(int argc, char **argv, t_stack **a)
{
	int		i;
	char	**nums;

	i = 1;
	while (i < argc)
	{
		nums = ft_split(argv[i], ' ');
		if (!nums)
			error_exit(a, NULL);
		parse_numbers(nums, a);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	parse_args(argc, argv, &a);
	if (is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	index_stack(&a);
	if (stack_size(a) <= 3)
		sort_three(&a);
	else if (stack_size(a) <= 5)
		sort_small(&a, &b);
	else
		sort_stack(&a, &b);
	free_stack(&a);
	return (0);
}
