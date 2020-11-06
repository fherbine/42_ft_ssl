/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input_buffer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 20:02:45 by fherbine          #+#    #+#             */
/*   Updated: 2020/10/31 20:02:45 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

static int			catbuffer(char **s1, char *s2, int sz1, int sz2)
{
	*s1 = ft_memjoin(*s1, s2, sz1, sz2);
	return (sz1 + sz2);
}

static t_rstream	read_buffer(int fd)
{
	char			*buf;
	char			*result;
	int				bz;
	int				rbz;
	t_rstream		rstream;

	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER + 1))))
		return ((t_rstream){.bytes = 0});
	if (!(result = (char *)malloc(sizeof(char) * 1)))
		return ((t_rstream){.bytes = 0});
	result[0] = '\0';
	rbz = 0;
	while ((bz = read(fd, buf, BUFFER)) > 0)
	{
		rbz = catbuffer(&result, buf, rbz, bz);
	}
	free(buf);
	rstream.buffer = result;
	rstream.bytes = rbz;
	return (rstream);
}

t_rstream			read_from_stdin(void)
{
	return (read_buffer(STDIN));
}

t_rstream			read_from_file(char *file_path)
{
	int				fd;
	t_rstream		result;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("ft_ssl: ", STDERR);
		ft_putstr_fd(file_path, STDERR);
		ft_putstr_fd(": No such file or directory\n", STDERR);
		return ((t_rstream){.bytes = 0});
	}
	result = read_buffer(fd);
	if (close(fd) == -1)
		return ((t_rstream){.bytes = 0});
	return (result);
}
