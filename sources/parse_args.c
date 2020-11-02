/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 12:35:47 by fherbine          #+#    #+#             */
/*   Updated: 2020/11/01 12:35:47 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

static void		parse_flag(char *flag_str, t_config *config)
{
	if (!(ft_strcmp(flag_str, "-p")))
		config->print = TRUE;
	else if (!(ft_strcmp(flag_str, "-q")))
		config->quiet = TRUE;
	else if (!(ft_strcmp(flag_str, "-r")))
		config->reverse = TRUE;
	else if (!(ft_strcmp(flag_str, "-s")))
		config->given_sum = TRUE;
	else
	{
		ft_putstr_fd("ft_ssl: ", STDERR);
		ft_putstr_fd(config->algorithm, STDERR);
		ft_putstr_fd(": Unrecognized flag ", STDERR);
		ft_putstr_fd(clean_flag(flag_str), STDERR);
		ft_putchar_fd('\n', STDERR);
		ft_putstr_fd("ft_ssl: ", STDERR);
		ft_putstr_fd(config->algorithm, STDERR);
		ft_putstr_fd(": Use -help for summary.", STDERR);
		ft_putchar_fd('\n', STDERR);
		exit(EXIT_ERROR);
	}
}

static void		add_file_to_config(char *path, t_config *config)
{
	t_file		*file;

	file = new_file(path);
	add_file_to_list(file, &(config->files));
}

t_config		parse(int argc, char **argv)
{
	t_config	config;
	int			i;
	t_u8		get_options;

	i = 0;
	get_options = TRUE;
	set_default_config(&config);
	while (i < argc)
	{
		if (argv[i][0] == '-' && get_options)
			parse_flag(argv[i], &config);
		else
		{
			add_file_to_config(argv[i], &config);
			get_options = FALSE;
		}
		i++;
	}
	return (config);
}
