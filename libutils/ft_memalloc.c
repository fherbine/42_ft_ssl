/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 22:12:17 by fherbine          #+#    #+#             */
/*   Updated: 2020/11/05 22:12:17 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

void	*ft_memalloc(size_t size)
{
	void *s;

	if ((s = (malloc(size))) == NULL)
		exit(EXIT_FAILURE);
	ft_bzero(s, size);
	return (s);
}
