/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:49:38 by fherbine          #+#    #+#             */
/*   Updated: 2020/11/02 17:49:38 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

char	*ft_strchr(const char *string, char c)
{
	size_t i;

	i = 0;
	while (string[i])
	{
		if (c == string[i])
			return ((char *)&string[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&string[i]);
	return (NULL);
}
