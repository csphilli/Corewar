# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/25 09:12:39 by cphillip          #+#    #+#              #
#    Updated: 2021/02/25 19:55:47 by csphilli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# targets
# NAME = asm
ASM_EXEC = asm

# gcc settings
CC = gcc
CFLAGS = -Wall -Wextra -Wall
INCLUDES = -I includes/ $(LIBFT_INC)

# library
LIBFT = $(LIB_DIR)libft.a
LIB_DIR = libft/
LIBFT_INC = -I $(LIB_DIR)includes/
LINK_LIBFT = -L $(LIB_DIR) -lft

# object directories
OBJ_DIR = obj/
TGT_DIR = $(OBJ_DIR)
TGT_DIR += $(addprefix $(OBJ_DIR), $(ASM_DIR))

# files
SRC_DIR = src/

# includes
INC_DIR = includes/
INC_FILES = asm_oplist.h\
			asm.h\
			op.h

INC_SRC = $(addprefix $(INC_DIR), $(INC_FILES))

# assembler
ASM_DIR = asm/
ASM_FILES = 	ascii_to_hex.c\
				calc_arg_type.c\
				encode_ins.c\
				encoding.c\
				set_bytes.c\
				split_hex.c\
				write_to_file.c\
				arg_utils.c\
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

ASM_SRC = $(addprefix $(ASM_DIR), $(ASM_FILES))

# assembler objects
ASM_CTO = $(ASM_SRC:.c=.o)
ASM_OBJ = $(addprefix $(OBJ_DIR), $(ASM_CTO))

PROG_BAR = "."

all: $(ASM_EXEC)

$(TGT_DIR):
	@mkdir -p $(TGT_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(LIBFT):
	@if git submodule status | egrep -q '^[-]' ; then \
	echo "INFO: Initializing git submodules"; \
	git submodule update --init --recursive; \
	fi
	@make -C $(LIB_DIR)
	@echo "Compiling into object files"

$(ASM_EXEC): $(TGT_DIR) $(LIBFT) $(ASM_OBJ) $(INC_SRC) 
	@echo "ASM object files prepared"
	@$(CC) $(CFLAGS) $(INCLUDES) $(LINK_LIBFT) -o $@ $(ASM_OBJ)
	@echo "Linking the Assembler"
	@echo "Done!"

clean:
	@make clean -C $(LIB_DIR)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make fclean -C $(LIB_DIR)
	@rm -rf $(ASM_EXEC)

re: fclean all

.PHONY: all clean fclean re
