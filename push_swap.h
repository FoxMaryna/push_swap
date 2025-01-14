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
# include "./inc/libft/libft.h"

typedef struct s_node
{
	int value;
	struct s_node *next;
} t_node;

t_node *stack_init(int ac, char **av);
void	free_stack(t_node **stack);
void	print_stack(t_node *stack);

#endif