# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dansanc3 <dansanc3@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/14 16:23:22 by dansanc3          #+#    #+#              #
#    Updated: 2025/07/27 13:13:50 by dansanc3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the executable
NAME = push_swap

# Compiler
CC = gcc

# Compiler flags
ifeq ($(OS),Windows_NT)
    CFLAGS = -Wall -Wextra -Werror -g3 -I$(PUSH_SWAP_DIR) -I$(LIBFT_DIR_INCLUDE) -I$(PRINTF_DIR)
else
    CFLAGS = -Wall -Wextra -Werror -g3  -I$(PUSH_SWAP_DIR) -I$(LIBFT_DIR_INCLUDE) -I$(PRINTF_DIR)
endif

# push_swap.h library path
PUSH_SWAP_DIR = include/
OBJ_DIR = obj
SRC_DIR = src

# Ft_printf library path
PRINTF_DIR = include/ft_printf/include
PRINT = include/ft_printf/libftprintf.a

# Libft library path
LIBFT_DIR_INCLUDE = include/libft/include
LIBFT_DIR = include/libft/
LIBFT = $(LIBFT_DIR)libft.a

# Source files
SRC = ft_split ft_atol main stack_init stack_utils free_argv check_syntax calculate_chunks operations \
ps_operations sort_short ps_operations2

# Object files
OBJS = $(addprefix obj/, $(addsuffix .o, $(SRC)))

SRCS = $(addsuffix .c, $(SRC))

OBJF =	.cache_exists

# Libraries
ifeq ($(OS),Windows_NT)
    LIBS = -lm
else
    LIBS = -lXext -lX11 -lm
endif

# Compilation rule
all: $(OBJF) $(LIBFT) $(PRINT) $(NAME)

# Regla para compilar los archivos objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(PUSH_SWAP_DIR)/push_swap.h | $(OBJF)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(PRINT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(PRINT) $(LIBS)

$(OBJF):
ifeq ($(OS),Windows_NT)
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
else
	@mkdir -p $(OBJ_DIR)/
endif

# Rule to compile libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Rule to compile ft_printf
$(PRINT):
	$(MAKE) -C include/ft_printf

# Rule to clean object files
clean:
ifeq ($(OS),Windows_NT)
	if exist $(OBJ_DIR) rmdir /s /q $(OBJ_DIR)
else
	rm -rf $(OBJ_DIR)
endif
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C include/ft_printf clean

# Rule to clean all generated files
fclean: clean
ifeq ($(OS),Windows_NT)
	if exist $(NAME) del /q $(NAME)
else
	rm -f $(NAME)
endif
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C include/ft_printf fclean

# Rule to recompile the entire project
re: fclean all

# Phony targets
.PHONY: all clean fclean re
