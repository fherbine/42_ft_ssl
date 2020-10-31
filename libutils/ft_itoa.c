/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:51:43 by fherbine          #+#    #+#             */
/*   Updated: 2020/10/31 11:51:43 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

static size_t	ft_number_len(intmax_t number)
{
	size_t		len;

	len = (number < 0) ? 2 : 1;
	number = ft_absolute(number);
	while (number > 10)
	{
		number /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(intmax_t number)
{
	char		*number_str;
	size_t		i;

	i = 0;
	number_str = (char *)malloc(sizeof(char) * (ft_number_len(number) + 1));
	if (!number_str)
		return (NULL);
	while (number)
	{
		number_str[i] = (char)(number % 10 + 48);
		number /= 10;
		i++;
	}
	number_str[i] = '\0';
	return (ft_strrev(number_str));
}
