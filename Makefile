# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/25 09:12:39 by cphillip          #+#    #+#              #
#    Updated: 2021/02/23 18:15:55 by csphilli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# targets
# NAME = asm
ASM_EXEC = asm

# gcc settings
CC = gcc
CFLAGS = -Wall -Wextra -Wall -g
INCLUDES = -I includes/ $(LIBFT_INC)

# library
LIBFT = $(LIB_DIR)libft.a
LIB_DIR = libft/
LIBFT_INC = -I $(LIB_DIR)includes/
LINK_LIBFT = -L $(LIB_DIR) -lft

# object directories
OBJ_DIR = obj/
TGT_DIR = $(OBJ_DIR)
TGT_DIR += $(addprefix $(OBJ_DIR), $(ENC_DIR), $(TOKENIZE_DIR))

# files
SRC_DIR = src/

ENC_DIR = $(SRC_DIR)encoding/
ENC_FILES = 	ascii_to_hex.c\
				calc_arg_type.c\
				encode_ins.c\
				encoding.c\
				set_bytes.c\
				split_hex.c\
				write_to_file.c

ENC_SRC = $(addprefix $(ENC_DIR), $(ENC_FILES))

TOKENIZE_DIR = $(SRC_DIR)tokenize/
TOKEN_FILES =	arg_utils.c\
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
				type_parse.c\
				main.c

TOK_SRC = $(addprefix $(TOKENIZE_DIR), $(TOKEN_FILES))

# SRC_FILES = $(addprefix $(ENC_DIR), $(ENC_SRC))\
# 			$(addprefix $(SRC_DIR), $(SRC))\
# 			$(addprefix $(TOKENIZE_DIR), $(TOKEN_SRC))

# ASM_SRC = $(ENC_SRC) $(TOKEN_SRC)

ASM_ENC_OBJ = $(ENC_SRC:.c=.o)
# ASM_ENC_OBJ = $(addprefix $(OBJ_DIR), $(ASM_ENC_CTO))

ASM_TOK_OBJ = $(TOK_SRC:.c=.o)
# ASM_TOK_OBJ = $(addprefix $(OBJ_DIR), $(ASM_TOK_CTO))

ASM_OBJ = $(ASM_ENC_OBJ) $(ASM_TOK_OBJ)

# INC = ./includes/
# INC_H = *.h
$(OBJ_DIR)/%.o: $(ENC_SRC)%.c $(TOK_SRC)%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -o -c $@ $<

# all: $(NAME)
all: $(ASM_EXEC)

# $(NAME): $(SRC_FILES) $(addprefix $(INC), $(INC_H))
# 	@if git submodule status | egrep -q '^[-]' ; then \
# 		echo "INFO: Initializing git submodules"; \
# 		git submodule update --init --recursive; \
# 	fi
# 	@make -C $(LIBFT)
# 	@echo "Compiling $(NAME)..."
# 	@gcc $(FLAGS) -o $(NAME) $(SRC_FILES) -I$(INC) $(LINK_LIBFT)

$(ASM_EXEC): $(TGT_DIR) $(LIBFT) $(ASM_OBJ)
	@echo "\nCompiling the assembler"
	@$(CC) $(CFLAGS) $(INCLUDES) $(LINK_LIBFT) -o $@ $(ASM_OBJ)
	@echo "Done!"
	
	


$(LIBFT):
	@if git submodule status | egrep -q '^[-]' ; then \
	echo "INFO: Initializing git submodules"; \
	git submodule update --init --recursive; \
	fi
	@make -C $(LIB_DIR)

$(TGT_DIR):
	@mkdir -p $(TGT_DIR)

clean:
	@make clean -C $(LIB_DIR)
	@rm -rf $(ASM_ENC_OBJ)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make fclean -C $(LIB_DIR)

re: fclean all

.PHONY: all clean fclean re
