/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrainyk <mkrainyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:12:05 by mkrainyk          #+#    #+#             */
/*   Updated: 2024/12/07 17:17:22 by mkrainyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	res_string(char *s)
{
	unsigned int	count;

	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(s, 1);
	count = ft_strlen(s);
	return (count);
}
