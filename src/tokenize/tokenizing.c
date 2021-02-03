/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 16:55:10 by csphilli          #+#    #+#             */
/*   Updated: 2021/02/03 21:25:30 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		one_reg(char *line, int len, t_asm_oplist oplist, int arg_nbr)
{
	int i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < len)
	{
		if (line[i] == REG_CHAR)
			cnt++;
		i++;
	}
	if (cnt == 1 && oplist.arg_type[arg_nbr] & T_REG)
		return (1);
	return (0);
}

int		one_dir(char *line, int len, t_asm_oplist oplist, int arg_nbr)
{
	int i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < len)
	{
		if (line[i] == DIRECT_CHAR)
			cnt++;
		i++;
	}
	if (cnt == 1 && oplist.arg_type[arg_nbr] & T_DIR)
		return (1);
	return (0);
}

int		arg_count(char **arg)
{
	int i;

	i = 0;
	while (*arg++)
		i++;
	return (i);
}

void	clean_arg(char **line)
{
	char	*tmp;
	int		leading;
	int		len;

	tmp = ft_strdup(*line);
	ft_strdel(line);
	leading = leading_ws(tmp);
	len = len_sans_trailing_ws(&tmp[leading]);
	*line = ft_strnew(len);
	ft_memcpy(*line, &tmp[leading], sizeof(char) * len);
	ft_strdel(&tmp);
}

void	get_args(t_ins *ins, char *line, t_asm_oplist oplist)
{
	char	**args;
	int		i;

	i = 0;
	args = ft_strsplit(line, SEPARATOR_CHAR);
	printf(BGRN"----- INSTRUCTION %d -----\n"RESET, ins->index);
	while (args[i])
	{
		// printf(" Going in\n\tArg: %d | >%s<\n", i, args[i]);
		clean_arg(&args[i]);
		printf("Arg[%d]: >%s<\n", i, args[i]);
		i++;
	}
	free_strsplit(&args);
}

void	add_label(char **dst, char **src)
{
	*dst = ft_strdup(*src);
	ft_strdel(src);
	*src = NULL;
}

void	tokenizing(t_master *m, char *line)
{
	int				i;
	t_ins			*ins;
	t_asm_oplist	oplist;

	i = 0;
	if (!line || line[0] == 0 || line[0] == COMMENT_CHAR ||\
		line[0] == ALT_COMMENT_CHAR)
		return ;
	if ((i = is_label(m, line, opcode_len(line))) > 0)
	{
		ins = ft_memalloc(sizeof(t_ins));
		oplist = get_opcode(line, i);
		ins->index = m->ins_count;
		m->ins_count++;
		m->label ? add_label(&ins->label, &m->label) : 0;
		ins->opcode = oplist.opcode;
		ins->opname = ft_strdup(oplist.opname);
		ins->arg_count = oplist.arg_count;
		ins->t_dir_size = oplist.t_dir_size;
		ins->arg_type_code = oplist.arg_type_code;
		get_args(ins, &line[i], oplist);
		append_node(&m->list, ins);
	}
}
