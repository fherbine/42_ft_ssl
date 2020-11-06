/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:03:20 by fherbine          #+#    #+#             */
/*   Updated: 2020/11/06 13:03:20 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

void			*ft_memjoin(void *a, void *b, intmax_t size1, intmax_t size2)
{
	char		*joined;
	intmax_t	i;
	intmax_t	i2;

	i = 0;
	i2 = 0;
	if (!(joined = (char *)ft_memalloc(sizeof(char) * (size1 + size2))))
		exit(EXIT_FAILURE);
	while (i < size1)
	{
		joined[i] = ((char *)a)[i];
		i++;
	}
	while (i2 < size2)
	{
		joined[i] = ((char *)b)[i2];
		i++;
		i2++;
	}
	free(a);
	return ((void *)joined);
}
