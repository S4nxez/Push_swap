# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dansanc3 <dansanc3@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 16:14:41 by dansanc3          #+#    #+#              #
#    Updated: 2025/07/27 20:03:22 by dansanc3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
INCLUDE		= include
SRC_DIR		= src/
OBJ_DIR		= obj/
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I./include
RM			= rm -f
AR			= ar rc

# Colors (no se usan aquí pero puedes usarlos para mensajes de log)

#Sources
SRC_FILES	= ft_printf ft_putchar ft_putstr ft_putnbr ft_putunbr ft_puthex
SRC			= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

norm:
	@norminette $(SRC) $(INCLUDE) | grep -v Norme -B1 || true

.PHONY: all clean fclean re norm
