
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./include
NAME = libft.a

SRC_DIR = src

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c \
ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c\
ft_tolower.c ft_toupper.c

SRCS := $(addprefix $(SRC_DIR)/, $(SRC))

OBJ = $(SRC:.c=.o)
OBJS := $(addprefix $(SRC_DIR)/, $(OBJ))

BNS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstadd_back_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstlast_bonus.c ft_lstsize_bonus.c \
ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS_BNS = $(BNS:.c=.o)
OBJS_BNS := $(addprefix $(SRC_DIR)/, $(OBJS_BNS))

all: $(NAME)

$(NAME): $(OBJS)
	ar -r $(NAME) $(OBJS)

bonus: $(OBJS) $(OBJS_BNS)
	ar -rcs $(NAME) $(OBJS) $(OBJS_BNS)

clean:
ifeq ($(OS),Windows_NT)
	if exist $(SRC_DIR)\*.o del /q $(SRC_DIR)\*.o
else
	rm -f $(OBJS) $(OBJS_BNS)
endif

fclean: clean
ifeq ($(OS),Windows_NT)
	if exist $(NAME) del /q $(NAME)
else
	rm -f $(NAME)
endif

re: fclean all

rebonus: fclean bonus

.PHONY: all NAME clean fclean re rebonus
