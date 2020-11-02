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

static char	*catbuffer(char *s1, char *s2)
{
	char	*dst;

	dst = ft_strcat(s1, s2);
	free(s1);
	return (dst);
}

static char	*read_buffer(int fd)
{
	char	*buf;
	char	*result;
	int		bz;

	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER + 1))))
		return (NULL);
	if (!(result = (char *)malloc(sizeof(char) * 1)))
		return (NULL);
	result[0] = '\0';
	while ((bz = read(fd, buf, BUFFER)) > 0)
	{
		buf[bz] = '\0';
		result = catbuffer(result, buf);
	}
	free(buf);
	return (result);
}

char		*read_from_stdin(void)
{
	return (read_buffer(STDIN));
}

char		*read_from_file(char *file_path)
{
	int		fd;
	char	*result;

	fd = open(file_path, O_RDONLY);
	result = read_buffer(fd);
	if (close(fd) == -1)
		return (NULL);
	return (result);
}
