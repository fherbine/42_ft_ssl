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

void	set_default_config(t_config *config)
{
	config->algorithm = "";
	config->fd = 0;
	config->given_sum = FALSE;
	config->print = FALSE;
	config->quiet = FALSE;
	config->reverse = FALSE;
}
