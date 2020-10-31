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

intmax_t	ft_power(int number, unsigned int power);

uintmax_t	ft_absolute(intmax_t number);

char		*ft_strrev(char *str);

char		*ft_itoa(intmax_t number);

intmax_t	ft_atoi(char *number_str);

void		ft_putnbr(intmax_t number);

void		ft_putnbr_fd(intmax_t number, int fd);

char		*ft_strcat(char *s1, char *s2);

#endif
