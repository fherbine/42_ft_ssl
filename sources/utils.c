/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:19:49 by fherbine          #+#    #+#             */
/*   Updated: 2020/11/03 12:19:49 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void		print_help(char *algorithm)
{
	if (!ft_strcmp(algorithm, "md5") || !ft_strcmp(algorithm, "sha256"))
	{
		ft_putstr("Usage: ");
		ft_putstr(algorithm);
		ft_putstr(" [-p -q -r -s <string>] [file...]\n");
	}
	else
		ft_putstr("Usage: <algorithm> [-p -q -r -s <string>] [file...]\n");
	ft_putstr("file...\tfiles to digest (default is stdin)\n");
	ft_putstr("-help\tDisplay this summary\n");
	ft_putstr("-p\techo STDIN to STDOUT and append the checksum to STDOUT\n");
	ft_putstr("-q\tquiet mode\n");
	ft_putstr("-r\treverse the format of the output\n");
	ft_putstr("-s str\tprint the sum of the `str`\n");
	exit(EXIT_SUCCESS);
}

void		putstrfree(char *str)
{
	ft_putstr(str);
	free(str);
}
