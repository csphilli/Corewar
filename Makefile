# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/25 09:12:39 by cphillip          #+#    #+#              #
#    Updated: 2021/03/02 12:29:49 by csphilli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# targets
# NAME = asm
ASM_EXEC = asm
COR_EXEC = corewar

# gcc settings
CC = gcc
CFLAGS = -Wall -Wextra -Wall
INCLUDES = -I includes/ $(LIBFT_INC) $(FT_PRINTF_INC)

# library
LIB_DIR = libft/
LIBFT = $(LIB_DIR)libft.a
LIBFT_INC = -I $(LIB_DIR)includes/
LINK_LIBFT = -L $(LIB_DIR) -lft

# ft_printf
FT_PRINTF_DIR = ft_printf/
FT_PRINTF = $(FT_PRINTF_DIR)libft_printf.a
FT_PRINTF_INC = -I $(FT_PRINTF_DIR)includes/
LINK_FT_PRINTF = -L $(FT_PRINTF_DIR) -lft_printf

# object directories
OBJ_DIR = obj/
TGT_DIR = $(OBJ_DIR)
TGT_DIR += $(addprefix $(OBJ_DIR), $(ASM_DIR))
TGT_DIR += $(addprefix $(OBJ_DIR), $(COR_DIR))

# files
SRC_DIR = src/

# includes
INC_DIR = includes/
INC_FILES = asm_oplist.h\
			asm.h\
			op.h\
			core.h\
			cop.h

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
				asm.c

ASM_SRC = $(addprefix $(ASM_DIR), $(ASM_FILES))

# assembler objects
ASM_CTO = $(ASM_SRC:.c=.o)
ASM_OBJ = $(addprefix $(OBJ_DIR), $(ASM_CTO))

# corewar
COR_DIR = corewar_src/

COR_FILES =     core.c\
                core_arg_reader.c\
                core_players.c\
                core_players2.c\
                core_carriage.c\
                core_play.c\
                core_code_handler.c\
                core_check.c\
                core_execute.c\
                core_tools.c\
                core_values.c\
                core_dump.c\
                c_live.c\
                c_ld.c\
                c_st.c\
                c_add.c\
                c_sub.c\
                c_and.c\
                c_or.c\
                c_xor.c\
                c_zjmp.c\
                c_ldi.c\
                c_sti.c\
                c_fork.c\
                c_lld.c\
                c_lldi.c\
                c_lfork.c\
                c_aff.c\
                n_arena.c\
                n_cases.c\
                n_color.c\
                n_color2.c\
                n_end.c\
                n_keys.c\
                n_print_update.c\
                n_wait.c

COR_SRC = $(addprefix $(COR_DIR), $(COR_FILES))

# corewar objects
COR_CTO = $(COR_SRC:.c=.o)
COR_OBJ = $(addprefix $(OBJ_DIR), $(COR_CTO))

all: $(ASM_EXEC) $(COR_EXEC)

$(TGT_DIR): $(SUBMODS)
	@mkdir -p $(TGT_DIR)


$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<
	@echo "#\c"

$(SUBMODS):
	@if git submodule status | egrep -q '^[-]' ; then \
	echo "INFO: Initializing git submodules"; \
	git submodule update --init --recursive; \
	fi	

$(LIBFT):
	@make -C $(LIB_DIR)

$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR)

$(ASM_EXEC): $(TGT_DIR) $(LIBFT) $(FT_PRINTF) $(ASM_OBJ) $(INC_SRC)
	@echo "\nASM files compiled"
	@$(CC) $(CFLAGS) $(INCLUDES) $(LINK_LIBFT) $(LINK_FT_PRINTF) -o $@ $(ASM_OBJ)
	@echo "Done linking ASM\n"

$(COR_EXEC): $(TGT_DIR) $(LIBFT) $(FT_PRINTF) $(COR_OBJ) $(INC_SRC)
	@echo "\nCOREWAR files compiled"
	@$(CC) $(CFLAGS) $(INCLUDES) $(LINK_LIBFT) $(LINK_FT_PRINTF) -o $@ $(COR_OBJ) -std=c99 -lncurses
	@echo "Done linking COREWAR!"

clean:
	@make clean -C $(LIB_DIR)
	@make clean -C $(FT_PRINTF_DIR)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make fclean -C $(LIB_DIR)
	@make fclean -C $(FT_PRINTF_DIR)
	@rm -rf $(ASM_EXEC)
	@rm -rf $(COR_EXEC)

re: fclean all

.PHONY: all clean fclean re
