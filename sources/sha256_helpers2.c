/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_helpers2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:16:07 by fherbine          #+#    #+#             */
/*   Updated: 2020/11/07 21:16:07 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

uint32_t		sha_helper_5(uint32_t n)
{
	return (rightrotate(n, 7) ^ rightrotate(n, 18) ^ (n >> 3));
}

uint32_t		sha_helper_6(uint32_t n)
{
	return (rightrotate(n, 17) ^ rightrotate(n, 19) ^ (n >> 10));
}

void			sha_fill_table(t_sha256 *sha_struct, uint32_t *chunk)
{
	uint8_t		i;

	i = 0;
	while (i < 64)
	{
		if (i <= 15)
			sha_struct->table[i] = chunk[i];
		else
			sha_struct->table[i] = (sha_helper_6(sha_struct->table[i - 2]) + \
				sha_struct->table[i - 7] \
				+ sha_helper_5(sha_struct->table[i - 15]) \
				+ sha_struct->table[i - 16]);
		i++;
	}
}

void			initialize_sha(t_sha256 *sha_struct)
{
	sha_struct->a = SHA256_H0;
	sha_struct->b = SHA256_H1;
	sha_struct->c = SHA256_H2;
	sha_struct->d = SHA256_H3;
	sha_struct->e = SHA256_H4;
	sha_struct->f = SHA256_H5;
	sha_struct->g = SHA256_H6;
	sha_struct->h = SHA256_H7;
}
