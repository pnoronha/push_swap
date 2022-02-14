# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 14:28:20 by pnoronha          #+#    #+#              #
#    Updated: 2022/02/13 10:02:50 by pnoronha         ###   ########.fr        #
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
SOURCES		:=	$(wildcard $(SRC_DIR)/*.c)
OBJECTS		:=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SOURCES))
LIBFT		:=	$(LIBFT_DIR)/libft.a

# comilation variables
CC			:=	gcc
CFLAGS		:=	-I./includes -I$(LIBFT_DIR) -Wall -Wextra -Werror -O0


.PHONY: all clean fclean re

# compiling binary executable file
$(BIN):	$(OBJECTS) | $(LIBFT) $(BIN_DIR)
		$(CC) $(CFLAGS) -o $(@) $(<) -L$(LIBFT_DIR) -lft

all:	$(BIN)

# compiling object files
$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c | $(BUILD_DIR)
		$(CC) $(CFLAGS) -c $(^) -o $(@)

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
