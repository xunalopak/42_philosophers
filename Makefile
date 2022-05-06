# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchampli <rchampli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 20:50:26 by rchampli          #+#    #+#              #
#    Updated: 2022/05/06 18:19:36 by rchampli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

HEADER = philo.h

CC = gcc

FLAGS = -Werror -Wall -Wextra -O3 -pthread

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
%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean :
		@rm -fr $(OBJS)

fclean : clean
		@rm -fr $(NAME)

re : fclean all

.PHONY: re fclean clean all