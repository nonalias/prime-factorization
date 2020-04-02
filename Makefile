# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taehkim <taehkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/01 19:59:41 by taehkim           #+#    #+#              #
#    Updated: 2020/04/03 00:01:34 by taehkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	factorization
CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror
SRCS	=	factorization.c
OBJS	=	$(SRCS:%.c=%.o)
BIN_PATH = /usr/local/bin

all	:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CC) -o $(NAME) $(OBJS)
	@sudo cp $(NAME) $(BIN_PATH)

%.o	:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	rm -f $(OBJS)

fclean	:	clean
	rm -f $(NAME)
	@sudo rm -f $(BIN_PATH)/$(NAME)

re	:	fclean all
