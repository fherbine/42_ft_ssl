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
# include "md5.h"
# include "sha256.h"
# define BUFFER 1024
# define MASK_8 0xff
# define MASK_16 0xff00
# define MASK_24 0xff0000
# define MASK_32 0xff000000
# define MASK_40 0xff00000000
# define MASK_48 0xff0000000000
# define MASK_56 0xff000000000000
# define MASK_64 0xff00000000000000

typedef struct		s_rstream
{
	char			*buffer;
	uint64_t		bytes;
}					t_rstream;

typedef struct		s_file
{
	char			*path;
	t_rstream		rstream;
	struct s_file	*next;
}					t_file;

typedef struct		s_config
{
	t_u8			print;
	t_u8			quiet;
	t_u8			reverse;
	t_u8			given_sum;
	t_u8			fd;
	char			*given_str;
	char			*algorithm;
	t_file			*files;
}					t_config;

t_rstream			read_from_stdin(void);

t_rstream			read_from_file(char *file_path, t_config *config);

void				set_default_config(t_config *config);

char				*clean_flag(char *raw_flag);

t_file				*new_file(char *path);

void				add_file_to_lifo_list(t_file *file, t_file **list);

void				add_file_to_fifo_list(t_file *file, t_file **list);

void				free_file_list(t_file *files);

t_config			parse(int argc, char **argv);

void				debug_print_config(t_config config);

void				print_help(char *algorithm);

void				debug_block(uint32_t *block, int base, int bit_size);

uint32_t			block_padding(char *str, uint32_t **block_ptr, uint64_t bz);
uint32_t			block_padding_be(char *str, \
										uint32_t **block_ptr, uint64_t bz);

uint32_t			leftrotate(uint32_t to_rotate, uint8_t n);

uint32_t			reverse_edianness_32(uint32_t input);
uint64_t			reverse_edianness_64(uint64_t input);

char				*md5(t_rstream rstream);

void				hash_inputs(t_config *config, \
									char *(*hash_func)(t_rstream));

void				putstrfree(char *str);

char				*outputs_join(char *s1, char *s2);

char				*sha256(t_rstream rstream);

#endif
