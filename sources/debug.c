/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:57:56 by fherbine          #+#    #+#             */
/*   Updated: 2020/11/02 19:57:56 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

static char		*binary_cast(void *number)
{
	return ((*((t_u8 *)number)) ? "True" : "False");
}

static char		*as_is(void *str)
{
	return (*((char **)str));
}

static char		*file_struct(void *chlst)
{
	char		*buf;
	t_file		*files;

	if (!(buf = (char *)malloc(sizeof(char) * 1)))
		return (NULL);
	buf = "";
	files = *((t_file **)chlst);
	if (!(files))
		return ("(null)");
	while (files)
	{
		buf = ft_strcat(buf, files->path);
		buf = ft_strcat(buf, " > ");
		files = files->next;
	}
	buf = ft_strcat(buf, "(null)");
	return (buf);
}

static void		print_struct_elem(char *type, char *name, void *value, \
									char *(*f)(void *))
{
	char		*final_value;

	final_value = (*f)(value);
	ft_putstr(type);
	ft_putchar('\t');
	ft_putstr(name);
	ft_putchar('\t');
	ft_putstr(final_value);
	ft_putchar('\n');
}

void			debug_print_config(t_config config)
{
	ft_putstr("======= CONFIG =======\n");
	print_struct_elem("t_u8", "print", &(config.print), &binary_cast);
	print_struct_elem("t_u8", "quiet", &(config.quiet), &binary_cast);
	print_struct_elem("t_u8", "reverse", &(config.reverse), &binary_cast);
	print_struct_elem("t_u8", "sum", &(config.given_sum), &binary_cast);
	print_struct_elem("char*", "given_str", &(config.given_str), &as_is);
	print_struct_elem("char*", "algorithm", &(config.algorithm), &as_is);
	print_struct_elem("t_file*", "files", &(config.files), &file_struct);
}

void			debug_512_block(uint32_t *block, int base, int bit_size)
{
	int			i;

	i = 0;
	while (i < bit_size)
	{
		ft_putstr("word(");
		ft_putnbr(i);
		ft_putstr("): ");
		ft_putstr(bword2str(block[i], base, 32));
		ft_putstr("\n");
		i++;
	}
}
