/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 22:10:11 by fherbine          #+#    #+#             */
/*   Updated: 2020/11/05 22:10:11 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

void	ft_bzero(void *s, size_t n)
{
	if (n > 0)
		s = ft_memset(s, 0, n);
}
