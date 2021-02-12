/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 20:39:12 by csphilli          #+#    #+#             */
/*   Updated: 2021/02/12 08:45:00 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	Returns the opcode if found, otherwise errors out. The oplist that it's
**	searching in is found in includes/asm_oplist.h
*/

t_asm_oplist	get_opcode(t_master *m, char *line)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (ft_strchr(OPNAME_CHAR, line[len]))
		len++;
	str = strndup(line, sizeof(char) * len);
	while (i < OP_COUNT)
	{
		if (ft_strequ(str, g_oplist[i].opname))
			break ;
		i++;
	}
	if (i == OP_COUNT)
		ft_error_line("ERROR: Invalid Opname. Line ", m->line_cnt - 1);
	ft_strdel(&str);
	str = NULL;
	return (g_oplist[i]);
}

/*
**	Returns the starting position of a label/instruction without the leading
**	whitespaces.
*/

int				leading_ws(char *line)
{
	int i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	return (i);
}

/*
**	Calculates the length of a string without trailing whitespaces.
*/

int				len_sans_trailing_ws(char *line)
{
	int		cnt;
	char	*tmp;

	tmp = line;
	cnt = 0;
	while (*tmp)
	{
		if (*tmp == COMMENT_CHAR || *tmp == ALT_COMMENT_CHAR \
			|| *tmp == ' ' || *tmp == '\t')
			break ;
		tmp++;
		cnt++;
	}
	return (cnt);
}
