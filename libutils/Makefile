SRCS = ft_putchar.c ft_putchar_fd.c
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