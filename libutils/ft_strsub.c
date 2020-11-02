/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:49:13 by fherbine          #+#    #+#             */
/*   Updated: 2020/11/02 18:49:13 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

char				*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char			*cpy;
	unsigned int	i;

	i = 0;
	if (!(s))
		return (NULL);
	if ((cpy = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while ((size_t)i < len)
	{
		cpy[i] = s[start];
		start++;
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
