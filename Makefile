# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 14:28:20 by pnoronha          #+#    #+#              #
#    Updated: 2022/02/10 18:14:11 by pnoronha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

exe			:=	push_swap

build_dir	:=	./bin
program		:=	$(build_dir)/$(exe)

sources_dir	:=	./sources
sources		:=	$(wildcard $(sources_dir)/*.c)

objects_dir	:=	./$(build_dir)/objects
objects		:=	$(patsubst $(sources_dir)*.c, $(objects_dir)*.o, $(sources))

libft_dir	:=	./includes/libft

CFLAGS		:=	-I./includes -I$(libft_dir) -Wall -Wextra -Werror


$(program):		$(objects) | $(build_dir)
		gcc $(CFLAGS) -o $(@) $(^) -L$(libft_dir) -lft

all:			$(program)

$(objects_dir)/%.o:	$(sources_dir)/%.c
		gcc $(CFLAGS) -c $(^) -o $(build_dir)/$(@)

$(build_dir):
		@mkdir -p $(build_dir)
		@mkdir -p $(objects_dir)

clean:
		@rm -rf $(build_dir)

fclean:
		@make fclean -C $(libft_dir)

re:
		fclean all

.PHONY: all build clean fclean re
