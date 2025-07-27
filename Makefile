# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dansanc3 <dansanc3@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/14 16:23:22 by dansanc3          #+#    #+#              #
#    Updated: 2025/07/27 17:53:48 by dansanc3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the executable
NAME = push_swap

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -g3 -I$(PUSH_SWAP_DIR) -I$(LIBFT_DIR_INCLUDE) -I$(FT_PRINTF_DIR_INCLUDE)

# push_swap.h library path
PUSH_SWAP_DIR = include/
OBJ_DIR = obj
SRC_DIR = src

# Libft library path
LIBFT_DIR = include/libft/
LIBFT_DIR_INCLUDE = $(LIBFT_DIR)include
LIBFT = $(LIBFT_DIR)libft.a

# ft_printf library path
FT_PRINTF_DIR = include/ft_printf/
FT_PRINTF_DIR_INCLUDE = $(FT_PRINTF_DIR)include
FT_PRINTF = $(FT_PRINTF_DIR)libftprintf.a

# Source files
SRC = ft_split ft_atol main stack_init stack_utils check_syntax calculate_chunks operations \
ps_operations sort_short ps_operations2 destroy

# Object files
OBJS = $(addprefix obj/, $(addsuffix .o, $(SRC)))

SRCS = $(addsuffix .c, $(SRC))

OBJF =	.cache_exists

# Libraries
LIBS = -lXext -lX11 -lm

# Compilation rule
all: $(OBJF) $(LIBFT) $(FT_PRINTF) $(NAME)

# Regla para compilar los archivos objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(PUSH_SWAP_DIR)/push_swap.h | $(OBJF)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(FT_PRINTF) $(LIBS)

$(OBJF):
	@mkdir -p $(OBJ_DIR)/

# Rule to compile libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Rule to compile ft_printf
$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

# Rule to clean object files
clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

# Rule to clean all generated files
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

# Rule to recompile the entire project
re: fclean all

# Phony targets
.PHONY: all clean fclean re
