/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_comment_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:49:14 by csphilli          #+#    #+#             */
/*   Updated: 2021/02/23 16:50:08 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

/*
**	Helper function for trailing_quote in get_name_comment.c file.
**	Parses line to identify if there is additional characters after the
**	closing quote of a name/comment. Returns 1 if so, otherwise 0.
*/

int		extraneous(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\"')
		i++;
	i++;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] == ' ' || line[i] == '\t')
			i++;
		else
			return (1);
	}
	return (0);
}

/*
**	This function ensures that if there is a closing quote that there
**	isn't also a .name or .comment command which would signal an ambiguous
**	quote. If so, the program will error out.
*/

int		unfinished(t_master *m, char **new, char *line, int flag)
{
	char	*tmp;

	tmp = NULL;
	if (flag == 0 && (!ft_strstr(line, COMMENT_CMD_STRING) &&\
		!ft_strstr(line, NAME_CMD_STRING)))
	{
		new_strjoin(new, "\n");
		new_strjoin(new, line);
		m->line_cnt++;
		return (1);
	}
	else
		ft_error_line("ERROR: Incomplete name/comment on line ", m->line_cnt);
	return (0);
}

void	len_chk(t_champ *c)
{
	if (c->champ_name && ft_strlen(c->champ_name) > PROG_NAME_LENGTH)
		ft_errorexit("ERROR: Champ name exceeds allowable \
size of 128 bytes.\n");
	if (c->champ_comment && ft_strlen(c->champ_comment) > COMMENT_LENGTH)
		ft_errorexit("ERROR: Champ comment exceeds allowable size of \
2048 bytes.\n");
}
