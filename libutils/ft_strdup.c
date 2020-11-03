/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:51:20 by fherbine          #+#    #+#             */
/*   Updated: 2020/11/03 14:51:20 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"


char		*ft_strdup(const char *str)
{
	size_t	i;
	char	*cpy;

	i = 0;
	if ((cpy = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))) == NULL)
		exit(EXIT_FAILURE);
	while (str[i] != '\0')
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
