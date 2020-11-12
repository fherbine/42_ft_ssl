/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:57:09 by fherbine          #+#    #+#             */
/*   Updated: 2020/11/07 21:57:09 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void			sha_main_loop(t_sha256 *shs)
{
	uint32_t	i;
	uint32_t	tmp[2];

	i = 0;
	while (i < 64)
	{
		tmp[0] = shs->vars[7] + sha_helper_4(shs->vars[4]) \
			+ sha_helper_1(shs->vars[4], shs->vars[5], shs->vars[6]) \
			+ g_cst_sha256[i] + shs->table[i];
		tmp[1] = sha_helper_3(shs->vars[0]) \
			+ sha_helper_2(shs->vars[0], shs->vars[1], shs->vars[2]);
		shs->vars[7] = shs->vars[6];
		shs->vars[6] = shs->vars[5];
		shs->vars[5] = shs->vars[4];
		shs->vars[4] = shs->vars[3] + tmp[0];
		shs->vars[3] = shs->vars[2];
		shs->vars[2] = shs->vars[1];
		shs->vars[1] = shs->vars[0];
		shs->vars[0] = tmp[0] + tmp[1];
		i++;
	}
}

static void		sha_variable_values(t_sha256 *sha_struct, uint8_t assign)
{
	if (assign == TRUE)
	{
		sha_struct->vars[0] = sha_struct->a;
		sha_struct->vars[1] = sha_struct->b;
		sha_struct->vars[2] = sha_struct->c;
		sha_struct->vars[3] = sha_struct->d;
		sha_struct->vars[4] = sha_struct->e;
		sha_struct->vars[5] = sha_struct->f;
		sha_struct->vars[6] = sha_struct->g;
		sha_struct->vars[7] = sha_struct->h;
	}
	else
	{
		sha_struct->a += sha_struct->vars[0];
		sha_struct->b += sha_struct->vars[1];
		sha_struct->c += sha_struct->vars[2];
		sha_struct->d += sha_struct->vars[3];
		sha_struct->e += sha_struct->vars[4];
		sha_struct->f += sha_struct->vars[5];
		sha_struct->g += sha_struct->vars[6];
		sha_struct->h += sha_struct->vars[7];
	}
}

static char		*sha_algorithm(t_sha256 sha_struct)
{
	uint64_t	i;
	char		*out;

	i = 0;
	initialize_sha(&sha_struct);
	while (i * 32 < sha_struct.bits_count)
	{
		sha_variable_values(&sha_struct, TRUE);
		sha_fill_table(&sha_struct, &(sha_struct.blocks[i]));
		sha_main_loop(&sha_struct);
		sha_variable_values(&sha_struct, FALSE);
		i += 16;
	}
	out = bword2str(sha_struct.a, 16, 32);
	out = outputs_join(out, bword2str(sha_struct.b, 16, 32));
	out = outputs_join(out, bword2str(sha_struct.c, 16, 32));
	out = outputs_join(out, bword2str(sha_struct.d, 16, 32));
	out = outputs_join(out, bword2str(sha_struct.e, 16, 32));
	out = outputs_join(out, bword2str(sha_struct.f, 16, 32));
	out = outputs_join(out, bword2str(sha_struct.g, 16, 32));
	out = outputs_join(out, bword2str(sha_struct.h, 16, 32));
	return (out);
}

static void		free_struct(t_sha256 shsstruct)
{
	free(shsstruct.blocks);
}

char			*sha256(t_rstream rstream)
{
	uint64_t	bcount;
	uint32_t	*blocks;
	t_sha256	sha_struct;
	char		*ret;

	bcount = block_padding_be(rstream.buffer, &blocks, rstream.bytes);
	sha_struct.bits_count = bcount;
	sha_struct.blocks = blocks;
	ret = sha_algorithm(sha_struct);
	free_struct(sha_struct);
	return (ret);
}
