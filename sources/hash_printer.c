/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_printer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 10:20:25 by fherbine          #+#    #+#             */
/*   Updated: 2020/11/06 10:20:25 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void			print_output(t_config *config, char *dgt, char *tag, t_u8 quote)
{
	if (!config->quiet && !config->reverse)
	{
		ft_putstr(ft_upperstr(config->algorithm));
		ft_putstr((quote) ? " (\"" : " (");
		ft_putstr(tag);
		ft_putstr((quote) ? "\") = " : ") = ");
	}
	putstrfree(dgt);
	if (!config->quiet && config->reverse)
	{
		ft_putstr((quote) ? " \"" : " ");
		ft_putstr(tag);
		ft_putstr((quote) ? "\"" : "");
	}
	ft_putstr("\n");
}

static void		handle_stdin_buff(t_config *config, char *(*hash_f)(t_rstream))
{
	t_rstream	alt_buffer;

	alt_buffer = read_from_stdin();
	ft_putstr((config->print) ? alt_buffer.buffer : "");
	putstrfree((*hash_f)(alt_buffer));
	free(alt_buffer.buffer);
	ft_putstr("\n");
}

void			hash_inputs(t_config *config, char *(*hash_func)(t_rstream))
{
	t_file		*files;
	t_rstream	alt_buffer;

	files = config->files;
	if ((!files && !config->given_str) || config->print)
		handle_stdin_buff(config, hash_func);
	if (config->given_str)
	{
		alt_buffer.buffer = config->given_str;
		alt_buffer.bytes = ft_strlen(config->given_str);
		print_output(config, (*hash_func)(alt_buffer), \
			config->given_str, TRUE);
	}
	while (files)
	{
		files->rstream = read_from_file(files->path, config);
		if (files->rstream.buffer)
		{
			print_output(config, (*hash_func)(files->rstream), \
				files->path, 0);
			free(files->rstream.buffer);
		}
		files = files->next;
	}
	free_file_list(config->files);
}
