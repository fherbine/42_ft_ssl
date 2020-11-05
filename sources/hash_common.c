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
	return ((ft_strlen((char *)str)) * 8);
}

uint32_t		block_padding(char *str, uint32_t **block_ptr)
{
	uint64_t	blen;
	uint64_t	npad;
	uint64_t	i;
	uint8_t		*buffer;

	i = ft_strlen(str);
	blen = bits_len((uint8_t *)str);
	npad = blen + (448 - (blen + 1)) % 512;
	if (!(buffer = (uint8_t *)malloc(sizeof(uint8_t) * (npad + 64 + 1) / 8)))
		return (0);
	ft_memcpy((void *)buffer, (void *)str, ft_strlen(str));
	buffer[i] = 0x80;
	i++;
	while (++i < (npad + 1) / 8)
		buffer[i] = 0x00;
	buffer[i + 0] = blen;
	buffer[i + 1] = blen >> 8;
	buffer[i + 2] = blen >> 16;
	buffer[i + 3] = blen >> 24;
	buffer[i + 4] = blen >> 32;
	buffer[i + 5] = blen >> 40;
	buffer[i + 6] = blen >> 48;
	buffer[i + 7] = blen >> 56;
	*block_ptr = ((uint32_t *)buffer);
	return (npad + 1 + 64);
}

uint32_t		leftrotate(uint32_t to_rotate, uint8_t n)
{
	return ((to_rotate << n) | (to_rotate >> (32 - n)));
}
