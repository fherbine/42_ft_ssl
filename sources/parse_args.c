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
	else if (!(ft_strcmp(flag_str, "-help")))
		print_help(config->algorithm);
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
	add_file_to_fifo_list(file, &(config->files));
}

static int		get_algorithm(char **args, t_config *config, int len)
{
	if (!ft_strcmp(args[0], "-help"))
		print_help(NULL);
	else if (!ft_strcmp(args[0], "sha"))
	{
		if (len < 2 || ft_strcmp(args[1], "-sha256"))
		{
			ft_putstr_fd("ft_ssl: sha: must be associated w/an algo.", STDERR);
			exit(EXIT_ERROR);
		}
		config->algorithm = ft_strdup("sha256");
		return (3);
	}
	else if (ft_strcmp(args[0], "md5") && ft_strcmp(args[0], "sha256"))
	{
		ft_putstr_fd("ft_ssl: ", STDERR);
		ft_putstr_fd(args[0], STDERR);
		ft_putstr_fd(": No such algorithm.\n", STDERR);
		ft_putstr_fd("ft_ssl: ", STDERR);
		ft_putstr_fd(args[0], STDERR);
		ft_putstr_fd(": Use -help for summary.\n", STDERR);
		exit(EXIT_ERROR);
	}
	config->algorithm = args[0];
	return (2);
}

static void		too_few_args(void)
{
	ft_putstr_fd("ft_ssl: Too few arguments.\n", STDERR);
	ft_putstr_fd("ft_ssl: Use -help for summary.\n", STDERR);
	exit(EXIT_ERROR);
}

t_config		parse(int argc, char **argv)
{
	t_config	config;
	int			i;
	t_u8		get_options;

	i = 2;
	get_options = TRUE;
	set_default_config(&config);
	if (argc < i)
		too_few_args();
	i = get_algorithm(&(argv[1]), &config, argc - 1);
	while (i < argc)
	{
		if (!ft_strcmp(argv[i - 1], "-s") && get_options && !config.given_str)
			config.given_str = argv[i];
		else if (argv[i][0] == '-' && get_options)
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
