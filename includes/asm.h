/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 17:29:14 by cphillip          #+#    #+#             */
/*   Updated: 2021/02/05 14:01:39 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
// # include "ll.h"
# include "op.h"
# include "asm_oplist.h"

# include <stdio.h> // remove before submission

# define PROG_NAME_LENGTH	(128)
# define COMMENT_LENGTH		(2048)
# define COREWAR_EXEC_MAGIC	0xea83f3 // dec: 15369203

typedef struct		s_champ
{
	char			*champ_name;
	unsigned int	champ_size;
	char			*champ_comment;
	unsigned int	magic;
}					t_champ;

typedef struct		s_ins
{
	char			*label;
	int				index;
	int				bytes;
	int				opcode;
	char			*opname;
	int				arg_count;
	int				arg_type[3];
	char			**arg_values;
	int				t_dir_size;
	int				arg_type_code;
}					t_ins;

typedef struct		s_master
{
	t_champ			*champ;
	t_list			instrux;
	int				ins_count;
	char			*label;
}					t_master;

void				get_data(t_master *master, int fd);
void				get_name_comment(char **ret, char *line, int fd);
int					opcode_len(char *line);
int					leading_ws(char *line);
void				del_leading_ws(char **line);
int					is_label(t_master *master, char *line, int len);
void				tokenizing(t_master *master, char *line);
t_asm_oplist		get_opcode(char *line, int len);
void				print_instrux_list(t_ins *ins);
void				ft_error_line(char *error_msg, int line);
int					len_sans_trailing_ws(char *line);
void				get_args(t_ins *ins, char *line, t_asm_oplist oplist);
void				handle_labels(t_master *m);

#endif
