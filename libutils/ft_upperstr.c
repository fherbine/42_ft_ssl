/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upperstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 10:38:46 by fherbine          #+#    #+#             */
/*   Updated: 2020/11/06 10:38:46 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

char		*ft_upperstr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}
