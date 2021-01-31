/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 17:29:14 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/31 19:19:48 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"
#include <stdio.h> // remove before submission

typedef struct 		s_input
{
	int				index;
	char 			*line;
}					t_input;

typedef struct		s_champ
{
	char			*champ_name;
	unsigned int	champ_size;
	char			*comment;
	unsigned int	magic;
}					t_champ;

typedef int(*t_dir_size)(char *opcode, char *symb);

typedef struct 		s_ins
{
	char			*opcode;
	char			*label;
	int				bytecount;
	int				arg_code[8];
	char			arg1[1];
	char			arg2[1];
	char			arg3[1];
	t_dir_size		*dir_size;

}					t_ins;


void	 	get_data(t_champ *champ, int fd);
void		get_name_comment(char **ret, char *line, int fd);
void	    analyse_statement(char *line);
// t_node		*get_node_at_index(t_list *list, int index);

#endif