/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:39:24 by fherbine          #+#    #+#             */
/*   Updated: 2020/11/03 16:39:24 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

uint64_t		bits_len(uint8_t *str)
{
	return ((ft_strlen((char *)str) - 1) * 8);
}

// get bits len "l"
// get 0 padding to add: (448 - (l + 1)) % 512

uint32_t		block_padding(char *str, uint32_t **block_ptr)
{
	uint64_t	blen;
	uint64_t	npad;
	uint64_t	i;
	uint8_t		*buffer;

	i = ft_strlen(str);
	blen = bits_len((uint8_t *)str);
	npad = blen + (448 - (blen + 1)) % 512;
	if (!(buffer = (uint8_t *)malloc(sizeof(uint8_t) * (blen + npad + 1) / 8)))
		return (NULL);
	ft_memcpy((void *)buffer, (void *)str, ft_strlen(str));
	buffer[i] = 0x01;
	i++;
	while (i < (npad + 1) / 8)
	{
		buffer[i] = 0x00;
		i++;
	}
	// 64b 8B 8 16 24 32 40 48 56 64
	buffer[i+0] = blen >> 56;
	buffer[i+1] = blen >> 48;
	buffer[i+2] = blen >> 40;
	buffer[i+3] = blen >> 32;
	buffer[i+4] = blen >> 24;
	buffer[i+5] = blen >> 16;
	buffer[i+6] = blen >> 8;
	buffer[i+7] = blen;

	*block_ptr = ((uint32_t *)buffer);
	return (blen + npad + 1 + 64);
}
