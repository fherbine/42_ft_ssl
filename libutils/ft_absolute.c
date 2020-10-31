/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absolute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:57:15 by fherbine          #+#    #+#             */
/*   Updated: 2020/10/31 11:57:15 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libutils.h"

uintmax_t	ft_absolute(intmax_t number)
{
	return ((uintmax_t)((number < 0) ? number * -1 : number));
}
