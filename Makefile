# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/25 09:12:39 by cphillip          #+#    #+#              #
#    Updated: 2021/02/20 22:35:27 by csphilli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

FLAGS = -Wall -Wextra -Wall -g

LIBFT = ./libft/
LINK_LIBFT = -L $(LIBFT) -lft -I$(LIBFT)/includes

SRC_DIR = ./src/
SRC = main.c

ENC_DIR = $(SRC_DIR)encoding/
ENC_SRC = 	ascii_to_hex.c\
			calc_arg_type.c\
			encode_ins.c\
			encoding.c\
			set_bytes.c\
			split_hex.c\
			write_to_file.c

TOKENIZE_DIR = $(SRC_DIR)tokenize/
TOKEN_SRC =	arg_utils.c\
			check_for_newline.c\
			check_for_s.c\
			error_chk_labels.c\
			errors.c\
			ft_pow.c\
			get_args.c\
			get_data.c\
			get_name_comment.c\
			handle_labels.c\
			hex_to_dec_utils.c\
			hex_to_dec.c\
			label_calcs.c\
			label_utils.c\
			label_utils2.c\
			name_comment_utils.c\
			printing.c\
			simp_signs.c\
			token_utils.c\
			tokenizing.c\
			type_parse.c

SRC_FILES = $(addprefix $(ENC_DIR), $(ENC_SRC))\
			$(addprefix $(SRC_DIR), $(SRC))\
			$(addprefix $(TOKENIZE_DIR), $(TOKEN_SRC))


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
