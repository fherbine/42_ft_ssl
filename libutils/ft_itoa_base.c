/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:53:44 by fherbine          #+#    #+#             */
/*   Updated: 2020/11/03 14:53:44 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

static size_t	ft_nlen(uintmax_t *nb, uintmax_t n, uintmax_t base)
{
	size_t		len;
	uintmax_t	tmp;

	len = 0;
	*nb = n;
	tmp = *nb;
	while (tmp >= base)
	{
		tmp = tmp / base;
		len++;
	}
	len++;
	return (len);
}

char			*ft_itoa_base(uintmax_t n, uintmax_t base)
{
	char		*ret;
	char		*b;
	size_t		len;
	size_t		i;
	uintmax_t	nb;

	nb = 0;
	b = ft_strdup("0123456789abcdef");
	i = 0;
	len = ft_nlen(&nb, n, base);
	if ((ret = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (nb >= base)
	{
		ret[i] = b[nb % base];
		i++;
		nb = nb / base;
	}
	ret[i] = b[nb];
	ret[len] = '\0';
	if (len > 1)
		ft_strrev(ret);
	free(b);
	return (ret);
}
