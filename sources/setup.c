/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:24:40 by fherbine          #+#    #+#             */
/*   Updated: 2020/11/02 18:24:40 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void		set_default_config(t_config *config)
{
	config->algorithm = "";
	config->fd = 0;
	config->files = NULL;
	config->given_sum = FALSE;
	config->print = FALSE;
	config->quiet = FALSE;
	config->reverse = FALSE;
}

char		*clean_flag(char *raw_flag)
{
	t_u8	dash_count;
	size_t	i;

	dash_count = 0;
	i = 0;
	while(dash_count < 2 && raw_flag[i])
	{
		if (raw_flag[i] == '-')
			dash_count++;
		else
			break;
		i++;
	}
	return (&raw_flag[i]);
}
