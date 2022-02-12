# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 14:28:20 by pnoronha          #+#    #+#              #
#    Updated: 2022/02/12 14:07:55 by pnoronha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	push_swap

BUILD_DIR	:=	./build
BIN_DIR		:=	$(BUILD_DIR)/bin
SRC_DIR		:=	./sources
OBJ_DIR		:=	$(BUILD_DIR)/objects
LIBFT_DIR	:=	./includes/libft

BIN			:=	$(BIN_DIR)/$(NAME)
SOURCES		:=	$(wildcard $(SRC_DIR)/*.c)
OBJECTS		:=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SOURCES))
LIBFT		:=	$(LIBFT_DIR)/libft.a

CFLAGS		:=	-I./includes -I$(LIBFT_DIR) -Wall -Wextra -Werror -O0


.PHONY: all build clean fclean re

$(BIN):	$(OBJECTS) | $(LIBFT) $(BIN_DIR)
		gcc $(CFLAGS) -o $(@) $(<) -L$(LIBFT_DIR) -lft

all:	$(BIN)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c | $(BUILD_DIR)
		gcc $(CFLAGS) -c $(^) -o $(@)

$(LIBFT):
		@make -C $(LIBFT_DIR)

$(BUILD_DIR):
		@mkdir -p $(BUILD_DIR)
		@mkdir -p $(OBJ_DIR) $(BIN_DIR)

clean:
		@rm -rf $(BUILD_DIR)

fclean:
		@make fclean -C $(LIBFT_DIR)

re:		fclean all
