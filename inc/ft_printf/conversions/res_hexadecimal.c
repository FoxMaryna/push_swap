/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_hexadecimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrainyk <mkrainyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:01:34 by mkrainyk          #+#    #+#             */
/*   Updated: 2024/12/07 17:01:35 by mkrainyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	res_hexadecimal(unsigned int nbr, char *base)
{
	int	len;
	int	count;

	len = ft_strlen(base);
	count = 0;
	if (nbr >= (unsigned int)len)
		count += res_hexadecimal(nbr / len, base);
	count += res_character(base[nbr % len]);
	return (count);
}
