# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/25 09:12:39 by cphillip          #+#    #+#              #
#    Updated: 2021/02/13 09:24:28 by osalmine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

FLAGS = -Wall -Wextra -g

LIBFT = ./libft/
LINK_LIBFT = -L $(LIBFT) -lft -I$(LIBFT)/includes

# FT_PRINTF = ./ft_printf/
# LINK_FT_PRINTF = -L $(FT_PRINTF) -lft_printf -I$(FT_PRINTF)/includes

SRC = *.c
SRC_DIR = ./src/

ENC_DIR = $(SRC_DIR)encoding/
TOKENIZE_DIR = $(SRC_DIR)tokenize/

SRC_FILES = $(addprefix $(ENC_DIR), $(SRC))\
			$(addprefix $(SRC_DIR), $(SRC))\
			$(addprefix $(TOKENIZE_DIR), $(SRC))

OBJ_FILES = $(SRC:.c=.o)

INC = ./includes/
INC_H = *.h

all: $(NAME)

$(NAME): $(SRC_FILES) $(addprefix $(INC), $(INC_H))
	@if git submodule status | egrep -q '^[-]' ; then \
		echo "INFO: Initializing git submodules"; \
		git submodule update --init --recursive; \
	fi
	@make -C $(LIBFT)
	@echo "Compiling $(NAME)..."
	@gcc $(FLAGS) -o $(NAME) $(SRC_FILES) -I$(INC) $(LINK_LIBFT)

clean:
	@rm -rf obj/
	@rm -rf $(LIBFT)/obj

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)/libft.a

re: fclean all

.PHONY: all clean fclean re
