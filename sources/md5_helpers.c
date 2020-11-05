/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 22:27:48 by fherbine          #+#    #+#             */
/*   Updated: 2020/11/05 22:27:48 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void			md5_helper_1(uint32_t *index, uint32_t *inputs, uint32_t *outs)
{
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;

	b = inputs[1];
	c = inputs[2];
	d = inputs[3];
	outs[0] = (b & c) | ((~b) & d);
	outs[1] = *index;
}

void			md5_helper_2(uint32_t *index, uint32_t *inputs, uint32_t *outs)
{
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;

	b = inputs[1];
	c = inputs[2];
	d = inputs[3];
	outs[0] = (d & b) | ((~d) & c);
	outs[1] = (5 * (*index) + 1) % 16;
}

void			md5_helper_3(uint32_t *index, uint32_t *inputs, uint32_t *outs)
{
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;

	b = inputs[1];
	c = inputs[2];
	d = inputs[3];
	outs[0] = b ^ c ^ d;
	outs[1] = (3 * (*index) + 5) % 16;
}

void			md5_helper_4(uint32_t *index, uint32_t *inputs, uint32_t *outs)
{
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;

	b = inputs[1];
	c = inputs[2];
	d = inputs[3];
	outs[0] = c ^ (b | (~d));
	outs[1] = 7 * (*index) % 16;
}
