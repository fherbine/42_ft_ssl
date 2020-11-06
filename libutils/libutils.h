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
# define EXIT_ERROR 1
# define EXIT_SUCCESS 0

typedef	unsigned char	t_u8;
typedef	unsigned short	t_u16;
typedef	unsigned long	t_u32;
typedef	signed char		t_s8;
typedef	signed short	t_s16;
typedef	signed long		t_s32;

void					ft_putchar(char character);

void					ft_putchar_fd(char character, int fd);

size_t					ft_strlen(const char *str);

void					ft_putstr(char *str);

void					ft_putstr_fd(char *str, int fd);

intmax_t				ft_power(int number, unsigned int power);

uintmax_t				ft_absolute(intmax_t number);

char					*ft_strrev(char *str);

char					*ft_itoa(intmax_t number);

intmax_t				ft_atoi(char *number_str);

void					ft_putnbr(intmax_t number);

void					ft_putnbr_fd(intmax_t number, int fd);

char					*ft_strcat(char *s1, char *s2);

char					*ft_strchr(const char *string, char c);

int						ft_strcmp(const char *s1, const char *s2);

char					*ft_strsub(const char *s, unsigned int start, \
									size_t len);

char					*ft_strdup(char *str);

char					*ft_itoa_base(uintmax_t n, uintmax_t base);

char					*bword2str(uintmax_t word, uint8_t base, \
									uint16_t word_len);

void					*ft_memcpy(void *dst, const void *src, size_t n);

void					ft_printmemory(void *ptr, size_t nbytes, \
										uint8_t word_size);

void					*ft_memset(void *b, int c, size_t len);

void					ft_bzero(void *s, size_t n);

void					*ft_memalloc(size_t size);

char					*ft_strjoin(char *s1, const char *s2);

int						ft_toupper(int c);

int						ft_tolower(int c);

char					*ft_lowerstr(char *str);

char					*ft_upperstr(char *str);

#endif
