/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 17:29:14 by cphillip          #+#    #+#             */
/*   Updated: 2021/02/16 14:40:06 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"
# include "asm_oplist.h"
# include <stdio.h> // remove before submission
# define PROG_NAME_LENGTH	(128)
# define COMMENT_LENGTH		(2048)
# define COREWAR_EXEC_MAGIC	0xea83f3 // dec: 15369203

typedef struct		s_labels
{
	char			*label;
}					t_labels;

typedef struct		s_champ
{
	char			*champ_name;
	unsigned int	champ_size;
	char			*champ_comment;
}					t_champ;

typedef struct		s_ins
{
	t_list			labels;
	int				index;
	int				bytes;
	int				opcode;
	char			*opname;
	int				arg_count;
	int				arg_type[3];
	char			**arg_values;
	char			**orig_arg_values;
	int				t_dir_size;
	int				arg_type_code;
	int				line;
}					t_ins;

typedef struct		s_master
{
	t_champ			*champ;
	t_list			instrux;
	int				ins_count;
	t_list			labels;
	int				line_cnt;
}					t_master;

/*
**	TOKENIZING FUNCTIONS
*/

void				get_data(t_master *m, int fd);
void				get_name_comment(t_master *m, char **ret, \
					char *line, int fd);
int					label_len(char *line);
int					leading_ws(char *line);
int					is_label(char *line);
void				tokenizing(t_master *m, char *line);
t_asm_oplist		get_opcode(t_master *m, char *line);
void				print_instrux_list(t_ins *ins);
void				ft_error_line(char *error_msg, int line);
int					len_sans_trailing_ws(char *line);
void				get_args(t_master *m, t_ins *ins, char *line, \
					t_asm_oplist oplist);
void				handle_labels(t_master *m);
void				pre_split(char **line);
int					compare_labels(t_labels *label, char *s2);
void				print_ins_labels(t_labels *labels);
void				add_labels(t_master *m, t_ins *ins);
void				save_label(t_master *m, char *line);
int					type_parse(t_master *m, char *line);
int					extraneous(char *line);
t_ins				*node_name_helper(t_node *node);
char				*downsize(char *line);
char				*ft_charcat(char *dest, const char src);
int					end_of_label(char *line);
char				*new_str_from_label(t_ins *node, int arg_nbr, char *bytes);
char				*extract_label(char *line);
void				error_chk_labels(t_master *m);
void				error_arg_type(t_master *m, char *line);
void				label_not_found(char *error_msg, t_ins *node,\
					char *label);
int					valid_reg_def(char *line);
int					ft_pow(int n, int exp);
int					ft_hex_to_dec(char *hex_str);

/*
**	ENCODING FUNCTIONS
*/

void				encoding_parse(t_master *m);

#endif
