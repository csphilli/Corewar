# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 15:59:38 by cphillip          #+#    #+#              #
#    Updated: 2021/03/02 12:34:03 by csphilli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC_DIR = srcs/
OBJ_DIR = obj/

INCLUDES = includes/
INC_FILES = colors.h libft.h ll.h

LIB_FILES = 	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
		ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c\
		ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c\
		ft_strstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c\
		ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
		ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c\
		ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c\
		ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c\
		ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c\
		ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c\
		ft_putendl_fd.c ft_putnbr_fd.c ft_lword.c ft_nbr_size.c ft_nbw.c\
		ft_strncpy.c ft_isspace.c ft_strnstr.c \
		ft_lstadd.c ft_lstfuncs.c ft_error.c\
		ft_nbr_size_base.c ft_revstr.c\
		ft_strndup.c ft_intlen_max.c ft_ftoa.c ft_itoa_uintmax.c\
		ft_putnbrmax.c ft_itoa_base.c ft_atoimax.c\
		ft_s_inlower.c ft_s_inupper.c ft_s_toupper.c\
		ft_free_strsplit.c ft_is_str_nbr.c ft_nbrstrcmp.c\
		get_next_line.c ft_error_exit.c ft_handle_error.c

SRC_FILES = $(addprefix $(SRC_DIR), $(LIB_FILES))

SRC_CTO = $(LIB_FILES:.c=.o)
SRC_OBJ = $(addprefix $(OBJ_DIR), $(SRC_CTO))

TARGET_DIR = $(OBJ_DIR)

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling library...\nStatus: \c"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(FLAGS) -I $(INCLUDES) -o $@ -c $<
	@echo "#\c"

$(NAME): $(OBJ_DIR) $(SRC_FILES) $(INCLUDES) $(SRC_OBJ) 
	@echo "\nDone!\n"
	@ar rc $(NAME) $(SRC_OBJ)
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re test
