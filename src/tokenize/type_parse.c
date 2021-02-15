/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:45:57 by csphilli          #+#    #+#             */
/*   Updated: 2021/02/15 22:55:28 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	Helper function for type_parse below.
**	Identifies if the line only has 1 label. If so, saves it to the master
**	struct until an instruction will claim in and returns 1 else 0.
*/

int		one_label(t_master *m, char *line)
{
	int i;
	int	s;

	i = 0;
	s = 0;
	while (ft_strchr(LABEL_CHARS, line[i]))
		i++;
	if (line[i] == LABEL_CHAR)
		s = 1;
	i++;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (0);
		i++;
	}
	if (s == 1)
	{
		save_label(m, line);
		return (1);
	}
	return (0);
}

/*
**	Helper function to type_parse below.
**	Identifies if there is only one instruction on the line.
**	Performs validation against g_oplist found in asm_oplist.h
**	Returns 1 if found matching opname else 0.
*/

int		one_instruction(char *line)
{
	int		i;
	int		j;
	int		ret;
	char	*tmp;

	i = 0;
	j = 0;
	ret = 0;
	while (ft_strchr(OPNAME_CHAR, line[i]))
		i++;
	if (line[i] == LABEL_CHAR || ft_strchr(LABEL_CHARS, line[i]))
		return (0);
	tmp = ft_strnew(i);
	ft_memcpy(tmp, line, sizeof(char) * i);
	while (j < OP_COUNT)
	{
		if (ft_strequ(tmp, g_oplist[j].opname))
		{
			ret = 1;
			break ;
		}
		j++;
	}
	ft_strdel(&tmp);
	return (ret);
}

/*
**	Used in conjuction with type_parse below.
**	If there is both a label and instruction on one line, this extracts
**	the label and saves it to master to be applied towards the instruction.
**	The one_label above checks if there's just one label in the line. Since
**	this function is checking for both label and instruction, there has to
**	be more information than just a label on the line which is why to
**	save the label, the one_label func must return false.
*/

int		label_and_ins(t_master *m, char *line)
{
	int i;

	i = 0;
	if (!one_label(m, line))
	{
		while (ft_strchr(LABEL_CHARS, line[i]))
			i++;
		if (line[i] != LABEL_CHAR)
			return (0);
		save_label(m, line);
		return (1);
	}
	return (0);
}

/*
**	Simple type parse function to save labels/instructions
**	All functions used are above.
*/

int		type_parse(t_master *m, char *line)
{
	int	ret;

	ret = 0;
	if (one_label(m, line))
		ret = 0;
	else if (one_instruction(line))
		ret = 1;
	else if (label_and_ins(m, line))
		ret = 1;
	else
		ft_error_line("ERROR: Invalid label/instruction on line ",\
		m->line_cnt + 1);
	m->line_cnt++;
	return (ret);
}
