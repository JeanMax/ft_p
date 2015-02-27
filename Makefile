#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/29 13:16:03 by mcanal            #+#    #+#              #
#    Updated: 2015/02/27 07:14:11 by mcanal           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

C_SRC = c_main.c c_read.c c_signal.c client.c
S_SRC = s_main.c s_read.c s_signal.c s_exec.c ft_cd.c server.c
COMMON_SRC = error.c
C_NAME = Client
S_NAME = Server
O_DIR = obj
COMMON_DIR = src
C_DIR = src/client
S_DIR = src/server
VPATH =	src:src/client:src/server
C_SRCC = $(C_SRC:%.c=$(C_DIR)/%.c) $(COMMON_SRC:%.c=$(COMMON_DIR)/%.c)
C_SRCO = $(C_SRC:%.c=$(O_DIR)/%.o) $(COMMON_SRC:%.c=$(O_DIR)/%.o)
S_SRCC = $(S_SRC:%.c=$(S_DIR)/%.c) $(COMMON_SRC:%.c=$(COMMON_DIR)/%.c)
S_SRCO = $(S_SRC:%.c=$(O_DIR)/%.o) $(COMMON_SRC:%.c=$(O_DIR)/%.o)
LIB = libft/libft.a
INC = inc/header.h
CFLAGS = -Wall -Werror -Wextra -I./inc/
CC = gcc
RM = rm -f

.PHONY: all client server clean fclean zclean re brute

all:
	@make -C libft
	@$(MAKE) $(C_NAME)
	@$(MAKE) $(S_NAME)

$(S_NAME): $(S_SRCO) $(LIB) $(INC)
	$(CC) $(CFLAGS) $(S_SRCO) $(LIB) -o $@

$(C_NAME): $(C_SRCO) $(LIB) $(INC)
	$(CC) $(CFLAGS) $(C_SRCO) $(LIB) -o $@

$(O_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@$(RM) $(C_SRCO)
	@$(RM) $(S_SRCO)

fclean: clean
	@$(RM) $(C_NAME)
	@$(RM) $(S_NAME)

zclean: fclean
	@make -C libft fclean

re: fclean all

brute: zclean all
