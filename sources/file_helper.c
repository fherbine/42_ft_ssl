/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:41:05 by fherbine          #+#    #+#             */
/*   Updated: 2020/11/02 19:41:05 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

t_file			*new_file(char *path)
{
	t_file		*file;
	t_rstream	default_rs;

	if (!(file = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	default_rs.buffer = NULL;
	default_rs.bytes = 0;
	file->next = NULL;
	file->rstream = default_rs;
	file->path = path;
	return (file);
}

void			add_file_to_lifo_list(t_file *file, t_file **list)
{
	file->next = *list;
	*list = file;
}

void			add_file_to_fifo_list(t_file *file, t_file **list)
{
	t_file		*tmp;

	if (!(*list))
	{
		add_file_to_lifo_list(file, list);
		return ;
	}
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = file;
}

void			free_file_list(t_file *files)
{
	t_file		*tmp;
	while (files)
	{
		tmp = files;
		files = files->next;
		free(tmp);
	}
}
