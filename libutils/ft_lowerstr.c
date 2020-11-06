/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowerstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 10:40:45 by fherbine          #+#    #+#             */
/*   Updated: 2020/11/06 10:40:45 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

char		*ft_lowerstr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}
