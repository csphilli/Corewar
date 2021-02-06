/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 16:55:10 by csphilli          #+#    #+#             */
/*   Updated: 2021/02/06 12:10:19 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	add_label(char **dst, char **src)
{
	*dst = ft_strdup(*src);
	ft_strdel(src);
	*src = NULL;
}

int		empty_line_chk(char *line)
{
	if (!line || line[0] == 0 || line[0] == COMMENT_CHAR ||\
		line[0] == ALT_COMMENT_CHAR)
		return (1);
	return (0);
}

void	tokenizing(t_master *m, char *line)
{
	int				i;
	t_ins			*ins;
	t_asm_oplist	oplist;

	i = 0;
	if (empty_line_chk(line))
		return ;
	if ((i = is_label(m, line, label_len(line))) > 0)
	{
		ins = ft_memalloc(sizeof(t_ins));
		ins->index = m->ins_count;
		m->ins_count++;
		oplist = get_opcode(ins, line, i);
		m->label ? add_label(&ins->label, &m->label) : 0;
		ins->opcode = oplist.opcode;
		ins->opname = ft_strdup(oplist.opname);
		ins->arg_count = oplist.arg_count;
		ins->t_dir_size = oplist.t_dir_size;
		ins->arg_type_code = oplist.arg_type_code;
		get_args(ins, &line[i], oplist);
		append_node(&m->instrux, ins);
	}
}
