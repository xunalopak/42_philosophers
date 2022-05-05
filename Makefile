# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 20:50:26 by rchampli          #+#    #+#              #
#    Updated: 2022/05/05 20:59:16 by rchampli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

HEADER = philo.h

CC = gcc

FLAGS = -Werror -Wall -Wextra -g -pthread

SRCS = game.c\
		init_and_parse.c\
		lib_utils.c\
		main.c\
		phil_utils.c\
		thread.c\

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(HEADER)
		@$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean :
		@rm -fr $(OBJS)

fclean : clean
		@rm -fr $(NAME)

re : fclean all

.PHONY: re fclean clean all