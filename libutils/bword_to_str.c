/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bword_to_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:58:04 by fherbine          #+#    #+#             */
/*   Updated: 2020/11/03 14:58:04 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

static uint16_t	get_word_len(uint16_t word_len, uint8_t base)
{
	if (base == 2)
		return (word_len);
	else if (base == 16)
		return (word_len / 4);
	return (-1);
}

static void		add_padding(char **buf, size_t start, size_t end, char c)
{
	while (start < end)
	{
		(*buf)[start] = c;
		start++;
	}
}

char			*bword2str(uintmax_t word, uint8_t base, uint16_t word_len)
{
	char		*ret;
	char		*b;
	size_t		i;

	if (base != 2 && base != 16)
		return (ft_itoa_base(word, (uintmax_t)base));
	word_len = get_word_len(word_len, base);
	b = ft_strdup("0123456789abcdef");
	i = 0;
	if ((ret = (char *)malloc(sizeof(char) * (word_len + 1))) == NULL)
		return (NULL);
	while (word >= base)
	{
		ret[i] = b[word % base];
		i++;
		word = word / base;
	}
	ret[i] = b[word];
	add_padding(&ret, ++i, word_len, '0');
	ret[word_len] = '\0';
	ft_strrev(ret);
	free(b);
	return (ret);
}
