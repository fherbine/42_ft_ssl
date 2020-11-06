/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 10:57:48 by fherbine          #+#    #+#             */
/*   Updated: 2020/10/31 10:57:48 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

int	main(int argc, char **argv)
{
	t_config config;

	config = parse(argc, argv);
	//debug_print_config(config);
	if (!ft_strcmp(config.algorithm, "md5"))
		hash_inputs(&config, &md5);
	return (0);
}
