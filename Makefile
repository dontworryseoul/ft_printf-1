# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seungyel <seungyel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/08 21:21:01 by seungyel          #+#    #+#              #
#    Updated: 2021/03/12 23:34:47 by seungyel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a
TEST = ft_printf.out
SRCS = ft_printf.c \
			ft_putchar.c \
			ft_putnbr_fd.c \
			ft_putchar_fd.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strlen.c \
			ft_strlcpy.c \
			ft_itoa.c \
			ft_isdigit.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SRCS)
	ar rc $(NAME) *.o

make: $(NAME)
	@gcc -g -L. -lftprintf $(SRCS) -o $(TEST)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all
