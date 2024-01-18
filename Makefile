# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muhnal <muhnal@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 15:37:33 by muhnal            #+#    #+#              #
#    Updated: 2023/04/20 15:01:22 by muhnal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all server client clean fclean make-libft make-ft_printf re bonus

NAME = server
NAME2 = client
NAME3 = server_bonus
NAME4 = client_bonus

SRCS := src/server.c
SRCS2 := src/client.c
SRCS3 := bonus/src/server_bonus.c
SRCS4 := bonus/src/client_bonus.c bonus/src/error_code_handler_bonus.c

OBJECTS := $(SRCS:.c=.o)
OBJECTS2 := $(SRCS2:.c=.o)
OBJECTS3 := $(SRCS3:.c=.o)
OBJECTS4 := $(SRCS4:.c=.o)

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
NC = \033[0m

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -Ibonus/include

all: make-libft make-ft_printf $(NAME) $(NAME2)

bonus: make-libft make-ft_printf $(NAME3) $(NAME4)

make-libft:
	@echo "$(YELLOW)Compiling libft...$(NC)"
	@bash -c "make -s -C libs/libft"

make-ft_printf:
	@echo "$(YELLOW)Compiling ft_printf...$(NC)"
	@bash -c "make -s -C libs/ft_printf"

compile_obj = @cc $(CFLAGS) $^ libs/libft/libft.a libs/ft_printf/ft_printf.a -o $@
echo_compiled = @echo "$(GREEN)$@ compiled!$(NC)"

$(NAME): $(OBJECTS)
	$(compile_obj)
	$(echo_compiled)

$(NAME2): $(OBJECTS2)
	$(compile_obj)
	$(echo_compiled)

$(NAME3): $(OBJECTS3)
	$(compile_obj)
	$(echo_compiled)

$(NAME4): $(OBJECTS4)
	$(compile_obj)
	$(echo_compiled)

%.o: %.c
	@echo "$(CYAN)Compiling $<...$(NC)"
	@cc $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS) $(OBJECTS2) $(OBJECTS3) $(OBJECTS4)
	@echo "$(RED)Object files cleaned...$(NC)"

fclean: clean
	@rm -f $(NAME) $(NAME2) $(NAME3) $(NAME4)
	@echo "$(RED)Executable files cleaned...$(NC)"

re: fclean all
