/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name_comment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 18:24:45 by csphilli          #+#    #+#             */
/*   Updated: 2021/03/10 16:15:53 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**  First tests if there is any characters after the last trailing quote.
**	If so, errors out. Otherwise, returns a string sans trailing quote.
**	extraneous is in the name_comment_utils.c file.
*/

void	trailing_quote(t_master *m, char **ret)
{
	size_t		i;
	char		*tmp;

	i = 0;
	tmp = ft_strdup(*ret);
	while (tmp[i] != '\"')
		i++;
	if (!extraneous(&tmp[i]))
	{
		ft_strdel(ret);
		*ret = ft_strndup(tmp, i);
	}
	else
		ft_error_line("ERROR: Extraneous info after command \
on line ", m->line_cnt);
	ft_strdel(&tmp);
}

/*
**  Helper function for cont_reading.
*/

void	new_strjoin(char **dst, char *src)
{
	char *new;

	new = ft_strjoin(*dst, src);
	ft_strdel(dst);
	*dst = new;
}

/*
**  For multi-line name/comment strings. Continues adding
**  to string until another double quote is found. First instance
**  of new double quote (which would be the closing quote)
**  cannot also be on a line that contains the NAME_CMD_STR or
**  COMMENT_CMD_STRING. Returns finalized string or errors out.
*/

void	cont_reading_helper(char **dst, char *line)
{
	new_strjoin(dst, "\n");
	new_strjoin(dst, line);
}

char	*cont_reading(t_master *m, char *line, int fd)
{
	char	*new;
	int		flag;

	flag = 0;
	new = ft_strdup(line);
	m->line_cnt++;
	while (get_next_line(fd, &line) > 0)
	{
		if (!ft_strchr(line, '\"'))
			cont_reading_helper(&new, line);
		else if (ft_strchr(line, '\"') && unfinished(m, &new, line, flag))
		{
			flag = 1;
			ft_strdel(&line);
			break ;
		}
		ft_strdel(&line);
		m->line_cnt++;
	}
	if (flag == 0)
		ft_error("ERROR: Missing closing double-quote for name/comment.\n");
	return (new);
}

/*
**  Shared function. If str is one line, strdup it.
**  If not, go into cont_reading and create a whole string
**  or error if invalid input.
*/

void	get_name_comment(t_master *m, char **ret, char *line, int fd)
{
	int	i;

	i = 0;
	if (ft_strchr(line, '\"'))
	{
		while (line[i] != '\"')
			i++;
		if (ft_strchr(&line[++i], '\"'))
		{
			*ret = ft_strdup(&line[i]);
			m->line_cnt++;
		}
		else
			*ret = cont_reading(m, &line[i], fd);
		trailing_quote(m, ret);
		len_chk(m->champ);
	}
	else
		ft_error("ERROR: Invalid name/comment.\n");
}
