/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryna <maryna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:48:07 by mkrainyk          #+#    #+#             */
/*   Updated: 2025/02/04 01:38:48 by maryna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int is_number(char *str)
{
    int i = 0;

    if (str[i] == '-')
        i++;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

static void parse_args(int argc, char **argv, t_stack **a)
{
    int i;
    long num;

    for (i = 1; i < argc; i++)
    {
        if (!is_number(argv[i]))
            error_exit(a, NULL);
        num = atol(argv[i]);
        if (num > INT_MAX || num < INT_MIN)
            error_exit(a, NULL);
        add_node_back(a, create_node((int)num));
    }
}

void error_exit(t_stack **a, t_stack **b)
{
    if (a)
        free_stack(a);
    if (b)
        free_stack(b);
    ft_printf("Error\n");
    exit(1);
}

int main(int argc, char **argv)
{
    t_stack *a = NULL;
    t_stack *b = NULL;

    if (argc < 2)
        return 0;

    parse_args(argc, argv, &a);
    if (is_sorted(a))
    {
        free_stack(&a);
        return 0;
    }

    index_stack(&a);

    if (stack_size(a) <= 3)
        sort_three(&a);
    else if (stack_size(a) <= 5)
        sort_small(&a, &b);
    else
        sort_stack(&a, &b);

    free_stack(&a);
    return 0;
}

