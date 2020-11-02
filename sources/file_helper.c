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

t_file		*new_file(char *path)
{
	t_file	*file;

	if (!(file = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	file->next = NULL;
	file->buffer = NULL;
	file->path = path;
	return (file);
}

void		add_file_to_lifo_list(t_file *file, t_file **list)
{
	file->next = *list;
	*list = file;
}

void		add_file_to_fifo_list(t_file *file, t_file **list)
{
	t_file	*tmp;

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