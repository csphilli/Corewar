/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 16:55:10 by csphilli          #+#    #+#             */
/*   Updated: 2021/03/15 09:43:59 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	add_labels(t_master *m, t_ins *ins)
{
	if (((t_list*)&m->labels)->head)
	{
		init_list(&ins->labels);
		while (((t_list*)&m->labels)->head)
		{
			append_node(&ins->labels, ((t_list*)&m->labels)->head->data);
			delete_node(&m->labels, ((t_list*)&m->labels)->head);
		}
	}
	else
		ins->labels.head = NULL;
}

/*
**	Simply checks for an empty line. Returns 1 if it's an empty line.
*/

int		empty_line_chk(char *line)
{
	if (!line || line[0] == 0 || line[0] == COMMENT_CHAR ||\
		line[0] == ALT_COMMENT_CHAR)
		return (1);
	return (0);
}

/*
**	Preps a line so that the opname can be separate from the argument.
**	Since arg_count will count the number of arguments, this function
**	is a validation assistant.
*/

char	*prep_line(char *line)
{
	int		i;
	int		ws;
	char	*new;

	if ((i = is_label(line)) > 0)
	{
		ws = leading_ws(&line[i]);
		new = ft_strdup(&line[ws + i]);
		return (new);
	}
	else
		return (ft_strdup(line));
}

/*
**	An extension to the tokenizing function. Simply carries out the rest
**	of the instructions due to the limiting norm requirements.
**	get_args is in the get_args.c file.
**	append_node is part of the libft functions and is found in
**	libft/srcs/ft_lstadd.c
*/

void	tokenizing_cont(t_master *m, t_ins *ins, \
		t_asm_oplist oplist, char *line)
{
	ins->opcode = oplist.opcode;
	ins->opname = ft_strdup(oplist.opname);
	ins->arg_count = oplist.arg_count;
	ins->t_dir_size = oplist.t_dir_size;
	ins->arg_type_code = oplist.arg_type_code;
	get_args(m, ins, &line[ft_strlen(ins->opname)], oplist);
	append_node(&m->instrux, ins);
	ins->line = m->line_cnt;
	m->ins_count++;
}

/*
**	Handles the tokenization of each line.
**	empty_line_chk is above.
**	type_parse is in the type_parse.c file.
**	add_labels is above.
**	tokenizing_cont is above.
**	get_opcode is in token_utils.c
*/

void	tokenizing(t_master *m, char *line)
{
	int				i;
	t_ins			*ins;
	t_asm_oplist	oplist;
	char			*tmp;

	i = 0;
	tmp = NULL;
	if (empty_line_chk(line))
	{
		m->line_cnt++;
		return ;
	}
	if (type_parse(m, line))
	{
		tmp = prep_line(line);
		ins = ft_memalloc(sizeof(t_ins));
		ins->index = m->ins_count;
		oplist = get_opcode(m, tmp);
		add_labels(m, ins);
		tokenizing_cont(m, ins, oplist, tmp);
		ft_strdel(&tmp);
	}
}
