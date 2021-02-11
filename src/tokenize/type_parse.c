/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:45:57 by csphilli          #+#    #+#             */
/*   Updated: 2021/02/11 12:50:48 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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

void	extract_label(t_master *m, char *line)
{
	int i;

	i = 0;
	while (ft_strchr(LABEL_CHARS, line[i]))
		i++;
	if (line[i] != LABEL_CHAR)
		ft_error_line("ERROR: Invalid label name on line ", m->line_cnt);
	save_label(m, line);
}

int		label_and_ins(t_master *m, char *line)
{
	if (!one_label(m, line))
	{
		extract_label(m, line);
		return (1);
	}
	return (0);
}

int		type_parse(t_master *m, char *line)
{
	if (one_label(m, line))
		return (0);
	else if (one_instruction(line))
		return (1);
	else if (label_and_ins(m, line))
		return (1);
	else
		ft_error_line("ERROR: Invalid label/instruction on line ", m->line_cnt);
	return (0);
}
