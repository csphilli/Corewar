# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/16 14:26:38 by cphillip          #+#    #+#              #
#    Updated: 2021/03/02 12:30:23 by csphilli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_printf.a

CC = gcc
FLAGS = -Wall -Wextra -Werror

# LIBFT = libft/

INC = includes/

SRC_DIR = src/

PRINTF_SRC_DIR = ft_printf/
PRINTF_FILES = 	checking.c ft_printf.c get_numbers.c handle_max.c initializing.c\
				parse.c pre_staging.c print_alt.c print_c.c print_d.c print_f.c\
				print_o.c print_other.c print_p.c print_s.c print_u.c print_x.c\
				staging.c x_padding.c

PRINTF_SRC = $(addprefix $(PRINTF_SRC_DIR), $(PRINTF_FILES))


LIBFT_SRC_DIR = libft/
LIBFT_FILES =	ft_ftoa.c ft_isdigit.c ft_itoa_base.c ft_memset.c ft_nbr_size.c\
				ft_putchar.c ft_putnbrmax.c ft_putstr.c ft_s_toupper.c ft_strchr.c\
				ft_strcmp.c ft_strdup.c ft_strlen.c ft_strndup.c ft_bzero.c\
				ft_isalpha.c ft_itoa_uintmax.c ft_nbr_size_base.c ft_strjoin.c\
				ft_strnew.c ft_toupper.c ft_intlen_max.c ft_memalloc.c

LIBFT_SRC = $(addprefix $(LIBFT_SRC_DIR), $(LIBFT_FILES))

SRC_FILES = $(addprefix $(SRC_DIR), $(PRINTF_SRC))\
			$(addprefix $(SRC_DIR), $(LIBFT_SRC))

OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ_DIR = obj/

PRINTF_CTO = $(PRINTF_SRC:.c=.o)
PRINTF_OBJ = $(addprefix $(OBJ_DIR), $(PRINTF_CTO))

LIBFT_CTO = $(LIBFT_SRC:.c=.o)
LIBFT_OBJ = $(addprefix $(OBJ_DIR), $(LIBFT_CTO))

TARGET_DIR = $(OBJ_DIR)
TARGET_DIR += $(addprefix $(OBJ_DIR), $(PRINTF_SRC_DIR) $(LIBFT_SRC_DIR))

all: $(NAME)

$(TARGET_DIR):
	@mkdir -p $(TARGET_DIR)
	@echo "Compiling ft_printf...\nStatus: \c"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(FLAGS) -I $(INC) -o $@ -c $<
	@echo "#\c"

$(NAME): $(SRC_FILES) $(INC)/ft_printf.h $(TARGET_DIR) $(PRINTF_OBJ) $(LIBFT_OBJ)
	@echo "\nDone!\n"
	@ar rc $(NAME) $(PRINTF_OBJ) $(LIBFT_OBJ)
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
