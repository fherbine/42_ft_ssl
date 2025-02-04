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

uint32_t		block_padding(char *str, uint32_t **block_ptr, uint64_t bz)
{
	uint64_t	blen;
	uint64_t	npad;
	uint64_t	i;
	uint8_t		*buffer;

	blen = bz * 8;
	npad = blen + (448 - (blen + 1)) % 512;
	if (!(buffer = (uint8_t *)ft_memalloc(sizeof(uint8_t) * (npad + 65) / 8)))
		return (0);
	ft_memcpy((void *)buffer, (void *)str, bz);
	buffer[bz] = 0x80;
	i = bz + 1;
	while (++i < (npad + 1) / 8)
		buffer[i] = 0x00;
	i = (npad + 1) / 8;
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

void			reverse_endianness_block(uint32_t *block_ptr, uint64_t len)
{
	uint64_t i;

	i = 0;
	while (i < len + 1)
	{
		block_ptr[i] = reverse_edianness_32(block_ptr[i]);
		i++;
	}
}

uint32_t		block_padding_be(char *str, uint32_t **block_ptr, uint64_t bz)
{
	uint64_t	npad;
	uint64_t	i;
	uint8_t		*buffer;

	i = bz + 1;
	npad = bz * 8 + (448 - (bz * 8 + 1)) % 512;
	if (!(buffer = (uint8_t *)ft_memalloc(sizeof(uint8_t) * (npad + 65) / 8)))
		return (0);
	ft_memcpy((void *)buffer, (void *)str, bz + 1);
	buffer[bz] = 0x80;
	reverse_endianness_block((uint32_t *)buffer, (npad + 65) / 32);
	while (++i < (npad + 1) / 8)
		buffer[i] = buffer[i];
	i = (npad + 1) / 8;
	buffer[i + 0] = bz * 8 >> 32;
	buffer[i + 1] = bz * 8 >> 40;
	buffer[i + 2] = bz * 8 >> 48;
	buffer[i + 3] = bz * 8 >> 56;
	buffer[i + 4] = bz * 8;
	buffer[i + 5] = bz * 8 >> 8;
	buffer[i + 6] = bz * 8 >> 16;
	buffer[i + 7] = bz * 8 >> 24;
	*block_ptr = ((uint32_t *)buffer);
	return (npad + 1 + 64);
}

uint32_t		reverse_edianness_32(uint32_t input)
{
	uint32_t	lendnum;

	lendnum = ((input >> 24) & MASK_8) |
			((input >> 8) & MASK_16) |
			((input << 8) & MASK_24) |
			((input << 24) & MASK_32);
	return (lendnum);
}

uint64_t		reverse_edianness_64(uint64_t input)
{
	uint64_t	lendnum;

	lendnum = ((input >> 56) & MASK_8) |
			((input >> 40) & MASK_16) |
			((input >> 24) & MASK_24) |
			((input >> 8) & MASK_32) |
			((input << 8) & MASK_40) |
			((input << 24) & MASK_48) |
			((input << 40) & MASK_56) |
			((input << 56) & MASK_64);
	return (lendnum);
}
