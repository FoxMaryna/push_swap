/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrainyk <mkrainyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:02:34 by mkrainyk          #+#    #+#             */
/*   Updated: 2024/12/07 17:22:14 by mkrainyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversions(const char *format, va_list args);

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_conversions(format, args);
		}
		else
		{
			count += res_character(*format);
		}
		format++;
	}
	va_end (args);
	return (count);
}

int	ft_conversions(const char *format, va_list args)
{
	unsigned int	count;

	count = 0;
	if (*format == 'c')
		count += res_character(va_arg(args, int));
	else if (*format == 's')
		count += res_string(va_arg(args, char *));
	else if (*format == 'p')
		count += res_pointer(va_arg(args, void *));
	else if (*format == 'd' || *format == 'i')
		count += res_decimal(va_arg(args, int));
	else if (*format == 'u')
		count += res_unsigned(va_arg(args, unsigned int));
	else if (*format == 'x')
		count += res_hexadecimal(va_arg(args, unsigned int), LOWER_HEX);
	else if (*format == 'X')
		count += res_hexadecimal(va_arg(args, unsigned int), UPPER_HEX);
	else if (*format == '%')
		count += res_character('%');
	return (count);
}

/*int main()
{
	ft_printf("Char: %c\n", 'A');
	ft_printf("String: %s\n", "Hello, world!");
	ft_printf("Pointer: %p\n", &main);
	ft_printf("Decimal: %d\n", -123);
	ft_printf("Integer: %i\n", -123);
	ft_printf("Unsigned: %u\n", 123456);
	ft_printf("Hex lowercase: %x\n", 255);
	ft_printf("Hex uppercase: %X\n", 255);
	ft_printf("Percent: %%\n");
	return (0);
}*/