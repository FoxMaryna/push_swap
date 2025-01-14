/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_decimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrainyk <mkrainyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:01:27 by mkrainyk          #+#    #+#             */
/*   Updated: 2024/12/07 17:01:28 by mkrainyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	res_decimal(int nbr)
{
	int	count;

	count = 0;
	if (nbr == INT_MIN)
	{
		return (res_string("-2147483648"));
	}
	else if (nbr < 0)
	{
		count += res_character('-');
		nbr = -nbr;
	}
	if (nbr > 9)
		count += res_decimal(nbr / 10);
	count += res_character(nbr % 10 + 48);
	return (count);
}
