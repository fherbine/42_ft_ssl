/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_helpers1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:15:53 by fherbine          #+#    #+#             */
/*   Updated: 2020/11/07 21:15:53 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

uint32_t	rightrotate(uint32_t number, uint8_t shift)
{
	return ((number >> shift) | (number << (32 - shift)));
}

uint32_t	sha_helper_1(uint32_t x, uint32_t y, uint32_t z)
{
	return ((x & y) ^ (~x & z));
}

uint32_t	sha_helper_2(uint32_t x, uint32_t y, uint32_t z)
{
	return ((x & y) ^ (x & z) ^ (y & z));
}

uint32_t	sha_helper_3(uint32_t n)
{
	return (rightrotate(n, 2) ^ rightrotate(n, 13) ^ rightrotate(n, 22));
}

uint32_t	sha_helper_4(uint32_t n)
{
	return (rightrotate(n, 6) ^ rightrotate(n, 11) ^ rightrotate(n, 25));
}
