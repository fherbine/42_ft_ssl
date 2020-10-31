/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:34:47 by fherbine          #+#    #+#             */
/*   Updated: 2020/10/31 13:34:47 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

intmax_t		ft_atoi(char *number_str)
{
	int			i;
	int			power;
	char		negative;
	intmax_t	number;

	negative = (number_str[0] == '-') ? TRUE : FALSE;
	power = ft_strlen(number_str) - 1 - negative;
	number = 0;
	i = (!negative) ? 0 : 1;
	while (number_str[i])
	{
		number += (number_str[i] - 48) * ft_power(10, power);
		i++;
		power--;
	}
	return ((intmax_t)number * ((negative) ? -1 : 1));
}
