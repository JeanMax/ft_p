#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/29 13:16:03 by mcanal            #+#    #+#              #
#    Updated: 2015/02/23 23:19:40 by mcanal           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC = main.c error.c
NAME = ft_p
O_DIR = obj
C_DIR = src
SRCC = $(SRC:%.c=$(C_DIR)/%.c)
SRCO = $(SRC:%.c=$(O_DIR)/%.o)
LIB = libft/libft.a
INC = inc/header.h
CFLAGS = -Wall -Werror -Wextra -I./inc/
CC = gcc
RM = rm -f

.PHONY: all clean fclean zclean re brute debug optimize

all:
	@make -C libft
	@$(MAKE) $(NAME)

$(NAME): $(SRCO) $(LIB) $(INC)
	@$(CC) $(CFLAGS) $(SRCO) $(LIB) -o $@

$(O_DIR)/%.o: $(C_DIR)/%.c
	@$(RM) $(NAME)
	@$(CC) $(CFLAGS) -c $^ -o $@

soft:
	@$(RM) $(NAME)
	@$(CC) $(SRCC) $(LIB) -o $(NAME)
	@./$(NAME)

debug: re
	@$(CC) $(CFLAGS) -ggdb $(SRCO) $(LIB) -o $(NAME)
	@gdb $(NAME)

optimize: re
	@$(CC) $(CFLAGS) -O2 $(SRCO) $(LIB) -o $(NAME)

clean:
	@$(RM) $(SRCO)

fclean: clean
	@$(RM) $(NAME)

zclean: fclean
	@make -C libft fclean

re: fclean all

brute: zclean all
