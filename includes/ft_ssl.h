/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:00:57 by fherbine          #+#    #+#             */
/*   Updated: 2020/10/31 11:00:57 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "../libutils/libutils.h"
# define BUFFER 1024

typedef struct	s_config
{
	t_u8		print;
	t_u8		quiet;
	t_u8		reverse;
	t_u8		given_sum;
	t_u8		fd;
}				t_config;

char			*read_from_stdin(void);

char			*read_from_file(char *file_path);

#endif
