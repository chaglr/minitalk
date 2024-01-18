# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muhnal <muhnal@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/02 18:17:49 by muhnal            #+#    #+#              #
#    Updated: 2023/04/13 10:30:51 by muhnal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#variables
NAME = ft_printf.a

SRC_DIR = src/
OBJ_DIR = obj/

SRCS = ft_printf.c ft_utils.c ft_libprintf.c
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

CC = cc
RM = rm -f
CFLAGS =-Wall -Wextra -Werror -c

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
NC = \033[0m

#rules
all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(YELLOW)compiling.. printf$(NC)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) -rf $(OBJ_DIR)
	@echo "$(YELLOW)object files cleaned...printf$(NC)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(YELLOW)executable files cleaned..printf$(NC)"

re: fclean all

.PHONY: all clean fclean re
