/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 20:18:34 by fherbine          #+#    #+#             */
/*   Updated: 2020/10/31 20:18:34 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

char		*ft_strcat(char *s1, char *s2)
{
	char	*dst;
	int		i1;
	int		i2;

	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dst)
		return (NULL);
	i1 = 0;
	i2 = 0;
	while (s1[i1])
	{
		dst[i1] = s1[i1];
		i1++;
	}
	while (s2[i2])
	{
		dst[i1] = s2[i2];
		i1++;
		i2++;
	}
	dst[i1] = '\0';
	return (dst);
}
