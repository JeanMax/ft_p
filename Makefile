#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/29 13:16:03 by mcanal            #+#    #+#              #
#    Updated: 2015/07/15 12:44:32 by mcanal           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

C_NAME = Client
S_NAME = Server

C_SRC = c_main.c c_read.c c_signal.c client.c
S_SRC =	s_main.c s_read.c s_signal.c s_exec.c ft_cd.c server.c
SHARED_SRC = error.c send_recv.c

C_DIR = src/client
S_DIR = src/server
SHARED_DIR = src
VPATH =	src:src/client:src/server
O_DIR = obj

C_SRCC=$(addprefix $(C_DIR)/,$(C_SRC)) $(addprefix $(SHARED_DIR)/,$(SHARED_SRC))
S_SRCC=$(addprefix $(S_DIR)/,$(S_SRC)) $(addprefix $(SHARED_DIR)/,$(SHARED_SRC))
C_SRCO =$(C_SRC:%.c=$(O_DIR)/%.o) $(SHARED_SRC:%.c=$(O_DIR)/%.o)
S_SRCO =$(S_SRC:%.c=$(O_DIR)/%.o) $(SHARED_SRC:%.c=$(O_DIR)/%.o)

OBJS =	$(C_SRC:%.c=$(O_DIR)/%.o) \
		$(S_SRC:%.c=$(O_DIR)/%.o) \
		$(SHARED_SRC:%.c=$(O_DIR)/%.o)
DEPS =  $(OBJS:%.o=%.d)

LIB = libft/libft.a
I_DIR = -I inc/
CFLAGS = -Wall -Wextra -Werror
CC = clang
RM = rm -rf
MKDIR = mkdir -p

WHITE = \033[37;01m
RED = \033[31;01m
GREEN =  \033[32;01m
BLUE =  \033[34;01m
BASIC = \033[0m

.PHONY: all debug debug_lib me_cry client server clean fclean zclean re brute

all:
	@$(MAKE) -C libft
	@$(MAKE) $(C_NAME)
	@$(MAKE) $(S_NAME)

debug_lib:
	@$(MAKE) -C libft debug
	@$(MAKE) debug

debug: CFLAGS = -g 
debug: fclean $(C_NAME) $(S_NAME)

me_cry: CFLAGS += -Wpedantic -Wshadow -Wcast-qual -Wconversion -Wcast-align \
				  -Wstrict-prototypes -Wmissing-prototypes -Wunreachable-code \
				  -Winit-self -Wmissing-declarations -Wnonnull -Wuninitialized \
				  -Wfloat-equal -Wbad-function-cast -Wundef -Waggregate-return \
				  -Wstrict-overflow=5 -O2
me_cry: $(C_NAME) $(S_NAME)

-include $(DEPS)

$(S_NAME): $(S_SRCO) $(LIB)
	@echo "$(BLUE)$(S_SRCO) $(WHITE)->$(RED) $@ $(BASIC)"
	@echo "$(WHITE)flags:$(BASIC) $(CFLAGS)"
	@echo "$(WHITE)compi:$(BASIC) $(CC)"
	@$(CC) $(CFLAGS) $(I_DIR) $(S_SRCO) $(LIB) -o $@

$(C_NAME): $(C_SRCO) $(LIB)
	@echo "$(BLUE)$(C_SRCO) $(WHITE)->$(RED) $@ $(BASIC)"
	@echo "$(WHITE)flags:$(BASIC) $(CFLAGS)"
	@echo "$(WHITE)compi:$(BASIC) $(CC)"
	@$(CC) $(CFLAGS) $(I_DIR) $(C_SRCO) $(LIB) -o $@

$(O_DIR)/%.o: %.c
	@echo "$(WHITE)$<\t->$(BLUE) $@ $(BASIC)"
	@$(CC) $(CFLAGS) $(I_DIR) -MMD -c $< -o $@

$(OBJS): | $(O_DIR)

$(O_DIR):
	@$(MKDIR) $(O_DIR)

clean:
	@$(RM) $(O_DIR)

fclean: clean
	@$(RM) $(C_NAME)
	@$(RM) $(S_NAME)

zclean: fclean
	@make -C libft fclean

re: fclean all

brute: zclean all
