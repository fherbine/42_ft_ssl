/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:37:52 by fherbine          #+#    #+#             */
/*   Updated: 2020/10/31 13:37:52 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

intmax_t			ft_power(int number, unsigned int power)
{
	unsigned int	i;
	intmax_t		result;

	i = 0;
	result = 1;
	if (!power)
		return (1);
	while (i < power)
	{
		result *= number;
		i++;
	}
	return (result);
}
