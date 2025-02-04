/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 22:14:26 by fherbine          #+#    #+#             */
/*   Updated: 2020/11/05 22:14:26 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

static char	*null_str(char *to_free)
{
	char	*ret;

	if (to_free)
		free(to_free);
	ret = ft_strdup("NULL");
	return (ret);
}

char		*ft_strjoin(char *s1, const char *s2)
{
	char	*joined;
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = 0;
	if (!(s1) || !(s2))
		return (null_str(s1));
	if (!(joined = (char *)ft_memalloc(sizeof(char) * (ft_strlen(s1) + \
						ft_strlen(s2) + 2))))
		exit(EXIT_FAILURE);
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	while (i2 < ft_strlen(s2))
	{
		joined[i] = s2[i2];
		i++;
		i2++;
	}
	joined[i] = '\0';
	free(s1);
	return (joined);
}
