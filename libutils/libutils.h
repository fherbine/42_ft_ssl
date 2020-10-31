/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libutils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 10:44:50 by fherbine          #+#    #+#             */
/*   Updated: 2020/10/31 10:44:56 by fherbine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUTILS_H
# define LIBUTILS_H
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define TRUE 1
# define FALSE 0

void		ft_putchar(char character);

void		ft_putchar_fd(char character, int fd);

size_t		ft_strlen(char *str);

void		ft_putstr(char *str);

void		ft_putstr_fd(char *str, int fd);

uintmax_t	ft_absolute(intmax_t number);

char		*ft_strrev(char *str);

char		*ft_itoa(intmax_t number);

#endif
