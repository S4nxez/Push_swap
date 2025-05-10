# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dansanc3 <dansanc3@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/14 16:23:22 by dansanc3          #+#    #+#              #
#    Updated: 2025/05/10 14:18:00 by dansanc3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the executable
NAME = push_swap

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address -I$(PUSH_SWAP_DIR) -I$(LIBFT_DIR_INCLUDE) -I$(PRINTF_DIR)

# Fractol.h library path
PUSH_SWAP_DIR = include/
OBJ_DIR = obj
SRC_DIR = src

# Ft_printf library path
PRINTF_DIR = include/ft_printf/include
PRINT = include/ft_printf/libftprintf.a

# Libft library path
LIBFT_DIR_INCLUDE = include/libft/include
LIBFT_DIR = include/libft
LIBFT = $(LIBFT_DIR)libft.a

# Source files
SRC = ft_split ft_atol

# Object files
OBJS = $(addprefix obj/, $(addsuffix .o, $(SRC)))

SRCS = $(addsuffix .c, $(SRC))

OBJF =	.cache_exists

# Libraries
LIBS = -lXext -lX11 -lm -Linclude/libft/ -lft -Linclude/ft_printf/ -lftprintf

# Compilation rule
all: $(OBJF) $(LIBFT) $(NAME)

# Regla para compilar los archivos objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(PUSH_SWAP_DIR)/push_swap.h | $(OBJF)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBS)

$(OBJF):
		@mkdir -p $(OBJ_DIR)/

# Rule to compile libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Rule to clean object files
clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

# Rule to clean all generated files
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Rule to recompile the entire project
re: fclean all

# Phony targets
.PHONY: all clean fclean re
