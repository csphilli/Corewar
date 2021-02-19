/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:32:36 by cphillip          #+#    #+#             */
/*   Updated: 2021/02/19 15:19:43 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	get_data_cont(t_master *m, char *line)
{
	if (line[0] == '.' && \
		!ft_strnstr(line, NAME_CMD_STRING, NAME_CMD_LEN) && \
		!ft_strnstr(line, COMMENT_CMD_STRING, COMMENT_CMD_LEN))
		ft_error_line("ERROR: Invalid command on line ", m->line_cnt + 1);
	else
		tokenizing(m, line);
}

/*
**	Either captures the name or comment or tokenizes an instruction line.
**	get_name_comment is in get_name_comment.c
*/

void	get_data(t_master *m, int fd)
{
	char	*line;
	char	*tmp;

	check_for_newline(m);
	while (get_next_line(fd, &line) > 0)
	{
		tmp = line;
		while ((*tmp == ' ' || *tmp == '\t') && *tmp != '\0')
			tmp++;
		if (ft_strnstr(tmp, NAME_CMD_STRING, NAME_CMD_LEN))
		{
			(m->champ->champ_name) ? \
			ft_error_line("ERROR: Multiple names. Line: ", m->line_cnt) : \
			get_name_comment(m, &m->champ->champ_name, line, fd);
		}
		else if (ft_strnstr(tmp, COMMENT_CMD_STRING, COMMENT_CMD_LEN))
		{
			(m->champ->champ_comment) ? \
			ft_error_line("ERROR: Multiple comments. Line: ", m->line_cnt) : \
			get_name_comment(m, &m->champ->champ_comment, line, fd);
		}
		else
			get_data_cont(m, tmp);
		ft_strdel(&line);
	}
}
