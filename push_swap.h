/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrainyk <mkrainyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:52:26 by mkrainyk          #+#    #+#             */
/*   Updated: 2024/12/18 16:00:59 by mkrainyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# include "./inc/ft_printf/ft_printf.h"

typedef struct s_stack
{
	int value;
	struct s_stack *next;
} t_stack;

// main functions
void push(t_stack **t_stack, int value);
int pop(t_stack **stack);

// sort_operations
void sa(t_stack **stack_a);
void sa(t_stack **stack_b);
void ss(t_stack **stack_a, t_stack **stack_b);
void pa(t_stack **stack_a, t_stack **stack_b);
void pb(t_stack **stack_a, t_stack **stack_b);
void ra(t_stack **stack_a);
void rb(t_stack **stack_b);
void rr(t_stack **stack_a, t_stack **stack_b);
void rra(t_stack **stack_a);
void rrb(t_stack **stack_b);
void rrr(t_stack **stack_a, t_stack **stack_b);

// utils
void print_stack(t_stack *stack);
void free_stack(t_stack **stack);
int is_sorted(t_stack *stack);
int stack_size(t_stack *s_stack);

// sorting func
void sort_two(t_stack **stack_a);
void sort_three(t_stack **stack_a);
void sort_small_stack(t_stack **stack_a, t_stack **stack_b, int size);
void sort_large_stack(t_stack **stack_a, t_stack **stack_b, int size);
void push_swap(t_stack **stack_a, t_stack **stack_b);

// error
void handle_error(void);

#endif