/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrainyk <mkrainyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:13:10 by mkrainyk          #+#    #+#             */
/*   Updated: 2024/12/07 17:25:55 by mkrainyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_hex(unsigned long adress);

int	res_pointer(void *p)
{
	unsigned long	adress;
	int				count;

	count = 0;
	count += res_character('0');
	count += res_character('x');
	adress = (unsigned long)p;
	if (adress == 0)
		count += res_character('0');
	else
		count += ft_hex(adress);
	return (count);
}

int	ft_hex(unsigned long adress)
{
	int	count;

	count = 0;
	if (adress >= 16)
		count += ft_hex(adress / 16);
	count += res_character(LOWER_HEX[adress % 16]);
	return (count);
}
