/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmemory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:57:14 by fherbine          #+#    #+#             */
/*   Updated: 2020/11/05 18:57:14 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

void		ft_printmemory(void *ptr, size_t nbytes, uint8_t word_size)
{
	size_t	i;

	i = 0;
	while (i < nbytes)
	{
		if (!(i % word_size))
		{
			ft_putstr("\n0x");
			ft_putstr(ft_itoa_base(((uintmax_t) & ptr) + i * 8, 16));
			ft_putstr(":");
		}
		ft_putstr("\t0b");
		ft_putstr(ft_itoa_base(((char *)ptr)[i], 2));
		i++;
	}
	ft_putstr("\n");
}
