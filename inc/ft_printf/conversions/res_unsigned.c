/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_unsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrainyk <mkrainyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:01:47 by mkrainyk          #+#    #+#             */
/*   Updated: 2024/12/07 17:01:47 by mkrainyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	res_unsigned(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr > 9)
		count += res_decimal(nbr / 10);
	count += res_character((nbr % 10) + 48);
	return (count);
}
