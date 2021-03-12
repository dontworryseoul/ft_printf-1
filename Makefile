# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seungyel <seungyel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/08 21:21:01 by seungyel          #+#    #+#              #
#    Updated: 2021/03/08 21:42:35 by seungyel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a
TEST = ft_printf.out
SRCS = ft_printf.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SRCS)
	ar rc $(NAME) *.o

test: $(NAME)
	@gcc -g -L. -lftprintf $(SRCS) main.c -o $(TEST)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all
