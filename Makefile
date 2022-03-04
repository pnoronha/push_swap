# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnoronha <pnoronha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 14:28:20 by pnoronha          #+#    #+#              #
#    Updated: 2022/03/04 15:37:59 by pnoronha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# project name
NAME		:=	push_swap

# setting all directories variables
BUILD_DIR	:=	./build
BIN_DIR		:=	$(BUILD_DIR)/bin
SRC_DIR		:=	./sources
OBJ_DIR		:=	$(BUILD_DIR)/objects
LIBFT_DIR	:=	./includes/libft

# setting files variables
BIN			:=	$(BIN_DIR)/$(NAME)
SOURCES		:=	$(SRC_DIR)/main.c			\
				$(SRC_DIR)/parse.c			\
				$(SRC_DIR)/list_utils.c		\
				$(SRC_DIR)/sorting.c		\
				$(SRC_DIR)/sorting_utils.c	\
				$(SRC_DIR)/push.c			\
				$(SRC_DIR)/swap.c			\
				$(SRC_DIR)/rotate.c			\
				$(SRC_DIR)/reverse_rotate.c	\
				$(SRC_DIR)/small_sort.c		\
				$(SRC_DIR)/big_sort.c

OBJECTS		:=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SOURCES))
LIBFT		:=	$(LIBFT_DIR)/libft.a

# comilation variables
CC			:=	gcc
CFLAGS		:=	-I./includes -I$(LIBFT_DIR) -Wall -Wextra -Werror -fsanitize=address

.PHONY: all clean fclean re

all:	$(NAME)

$(NAME): $(BIN)

# compiling binary executable file
$(BIN):	$(OBJECTS) | $(LIBFT) $(BIN_DIR)
		@$(CC) $(CFLAGS) -o $(@) $(^) -L$(LIBFT_DIR) -lft
		@echo "\033[32;1m\n>>	>>push_swap<<	<<\033[0m"

# compiling object files
$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c | $(BUILD_DIR)
		@$(CC) $(CFLAGS) -c $(^) -o $(@)

# library compilation
$(LIBFT):
		@make -C $(LIBFT_DIR)

# building binary and objects directories
$(BUILD_DIR):
		@mkdir -p $(BUILD_DIR)
		@mkdir -p $(OBJ_DIR) $(BIN_DIR)

clean:
		@rm -rf $(OBJ_DIR)

fclean:	clean
		@rm -rf $(BUILD_DIR)
		@make fclean -C $(LIBFT_DIR)

re:		fclean all
