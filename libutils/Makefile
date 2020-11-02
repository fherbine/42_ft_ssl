SRCS = ft_putchar.c ft_putchar_fd.c ft_strlen.c ft_putstr.c ft_putstr_fd.c \
		ft_absolute.c ft_strrev.c ft_itoa.c ft_power.c ft_atoi.c ft_putnbr.c \
		ft_putnbr_fd.c ft_strcat.c ft_strchr.c ft_strcmp.c ft_strsub.c
NAME = libutils.a
INCLUDE = ./
FLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
CC = gcc

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -I $(INCLUDE) -c $? -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re