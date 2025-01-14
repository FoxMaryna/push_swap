/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrainyk <mkrainyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:02:00 by mkrainyk          #+#    #+#             */
/*   Updated: 2024/12/07 17:02:02 by mkrainyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>

# include "../libft/libft.h"

# define LOWER_HEX "0123456789abcdef"
# define UPPER_HEX "0123456789ABCDEF"

int	res_character(int c);
int	res_string(char *s);
int	res_decimal(int nbr);
int	res_unsigned(unsigned int nbr);
int	res_hexadecimal(unsigned int nbr, char *base);
int	res_pointer(void *p);

int	ft_printf(const char *format, ...);

#endif