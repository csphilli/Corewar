# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/25 09:12:39 by cphillip          #+#    #+#              #
#    Updated: 2021/01/09 17:07:12 by cphillip         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

FLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/
LINK_LIBFT = -L $(LIBFT) -lft -I$(LIBFT)/includes

# FT_PRINTF = ./ft_printf/
# LINK_FT_PRINTF = -L $(FT_PRINTF) -lft_printf -I$(FT_PRINTF)/includes

SRC = *.c
SRC_DIR = ./src/
ASM_DIR = $(SRC_DIR)asm/
ASM_INC = asm.h


SRC_FILES = $(addprefix $(SRC_DIR), $(SRC))\
			$(addprefix $(ASM_DIR), $(SRC))


OBJ_FILES = $(SRC:.c=.o)

INC = ./includes/
ASM_INC = $(addprefix $(INC), $(ASM_INC))

all: $(NAME)

$(NAME): $(SRC_FILES) $(ASM_INC)
	@if git submodule status | egrep -q '^[-]' ; then \
		echo "INFO: Initializing git submodules"; \
		git submodule update --init --recursive; \
	fi
	@make -C $(LIBFT)
	# @make -C $(FT_PRINTF)
	@echo "Compiling $(NAME)..."
	@gcc $(FLAGS) -o $(NAME) $(SRC_FILES) -I$(INC) $(LINK_LIBFT)	

clean:
	@rm -rf obj/
	@rm -rf $(LIBFT)/obj
	# @rm -rf $(FT_PRINTF)/obj
	# @rm -rf $(FT_PRINTF)/libft/obj

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)/libft.a
	# @rm -rf $(FT_PRINTF)/libft_printf.a

re: fclean all

.PHONY: all clean fclean re
