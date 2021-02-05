/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 20:39:12 by csphilli          #+#    #+#             */
/*   Updated: 2021/02/04 21:52:17 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_asm_oplist	get_opcode(char *line, int len)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strndup(line, len);
	while (!ft_strequ(str, g_oplist[i].opname))
		i++;
	ft_strdel(&str);
	str = NULL;
	return (g_oplist[i]);
}

int				is_label(t_master *m, char *line, int len)
{
	if (line[len - 1] != ':')
		return (len);
	else
	{
		m->label = ft_strnew(len - 1);
		ft_memcpy(m->label, line, sizeof(char) * len - 1);
		return (0);
	}
}

int				leading_ws(char *line)
{
	int i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	return (i);
}

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

int				opcode_len(char *line)
{
	int len;

	len = 0;
	while (line[len] != ' ' && line[len] != '\t' && \
			line[len] != '\n' && line[len] != '\0')
		len++;
	return (len);
}
