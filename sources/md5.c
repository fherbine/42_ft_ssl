/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:27:32 by fherbine          #+#    #+#             */
/*   Updated: 2020/11/03 16:27:32 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

static void		initialize_md5(t_md5 *md5_struct)
{
	md5_struct->a = MD5_H0;
	md5_struct->b = MD5_H1;
	md5_struct->c = MD5_H2;
	md5_struct->d = MD5_H3;
}

void			md5_main_loop(t_md5 *ms, uint32_t *buffer)
{
	uint32_t	i;
	uint32_t	fg[2];

	i = 0;
	while (i < 64)
	{
		if (i <= 15)
			md5_helper_1(&i, ms->vars, fg);
		else if (i >= 16 && i <= 31)
			md5_helper_2(&i, ms->vars, fg);
		else if (i >= 32 && i <= 47)
			md5_helper_3(&i, ms->vars, fg);
		else
			md5_helper_4(&i, ms->vars, fg);
		fg[0] = fg[0] + ms->vars[0] + g_cst_md5[i] + buffer[fg[1]];
		ms->vars[0] = ms->vars[3];
		ms->vars[3] = ms->vars[2];
		ms->vars[2] = ms->vars[1];
		ms->vars[1] = ms->vars[1] + leftrotate(fg[0], g_shift_md5[i]);
		i++;
	}
}

char			*md5(t_md5 md5_struct)
{
	uint64_t	i;
	char		*out;

	i = 0;
	initialize_md5(&md5_struct);
	while (i * 32 < md5_struct.bits_count)
	{
		md5_struct.vars[0] = md5_struct.a;
		md5_struct.vars[1] = md5_struct.b;
		md5_struct.vars[2] = md5_struct.c;
		md5_struct.vars[3] = md5_struct.d;
		md5_main_loop(&md5_struct, &(md5_struct.blocks[i]));
		md5_struct.a += md5_struct.vars[0];
		md5_struct.b += md5_struct.vars[1];
		md5_struct.c += md5_struct.vars[2];
		md5_struct.d += md5_struct.vars[3];
		i += 16;
	}
	out = ft_strdup(bword2str(to_little_endian(md5_struct.a), 16, 32));
	out = ft_strjoin(out, bword2str(to_little_endian(md5_struct.b), 16, 32));
	out = ft_strjoin(out, bword2str(to_little_endian(md5_struct.c), 16, 32));
	out = ft_strjoin(out, bword2str(to_little_endian(md5_struct.d), 16, 32));
	return (out);
}
