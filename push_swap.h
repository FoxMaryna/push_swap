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
void push_swap(t_stack **stack_a, t_stack **stack_b);

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
int is_valid_number(char *str);

// sorting func
void sort_three(t_stack **stack_a);
int get_min_value(t_stack *stack);
int get_index_of_value(t_stack *stack, int value);
void move_to_top(t_stack **stack, int i);
void sort_five(t_stack **stack_a, t_stack **stack_b, int size);
void sort_small_stack(t_stack **stack_a, t_stack **stack_b, int size);
void quicksort_array(int *arr, int low, int high);
int find_pivot(t_stack *stack, int size);
int find_pivot(t_stack *stack, int size);
void quicksort_stack(t_stack **stack_a, t_stack **stack_b, int size);
int get_max_value(t_stack *stack);
void radix_sort(t_stack **stack_a, t_stack **stack_b, int size);

// error
void handle_error(void);

#endif