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

typedef struct		s_file
{
	char			*path;
	char			*buffer;
	struct s_file	*next;
}					t_file;

typedef struct		s_config
{
	t_u8			print;
	t_u8			quiet;
	t_u8			reverse;
	t_u8			given_sum;
	t_u8			fd;
	char			*algorithm;
	t_file			*files;
}					t_config;

char				*read_from_stdin(void);

char				*read_from_file(char *file_path);

void				set_default_config(t_config *config);

char				*clean_flag(char *raw_flag);

t_file				*new_file(char *path);

void				add_file_to_list(t_file *file, t_file **list);

t_config			parse(int argc, char **argv);

#endif
