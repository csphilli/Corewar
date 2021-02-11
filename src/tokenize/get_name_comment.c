/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name_comment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 18:24:45 by csphilli          #+#    #+#             */
/*   Updated: 2021/02/11 12:45:31 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**  Takes final output and removes quotes from end.
*/

void	trailing_quote(char **ret)
{
	size_t		i;
	char		*tmp;

	i = 0;
	tmp = *ret;
	while (tmp[i] != '\"')
		i++;
	ft_strdel(ret);
	*ret = ft_strndup(tmp, i);
}

/*
**  Helper function for cont_reading
*/

void	new_strjoin(char **dst, char *src)
{
	char *tmp;

	tmp = *dst;
	ft_strdel(dst);
	*dst = ft_strjoin(tmp, src);
}

/*
**  For multi-line name/comment strings. Continues adding
**  to string until another double quote is found. First instance
**  of new double quote (which would be the closing quote)
**  cannot also be on a line that contains the NAME_CMD_STR or
**  COMMENT_CMD_STRING. Returns finalized string or errors out.
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
		return (1);
	}
	else
		ft_error_line("ERROR: Incomplete name/comment on line ", m->line_cnt);
	return (0);
}

char	*cont_reading(t_master *m, char *line, int fd)
{
	char	*new;
	int		flag;

	flag = 0;
	new = ft_strdup(line);
	while (get_next_line(fd, &line) > 0)
	{
		if (!ft_strchr(line, '\"'))
		{
			new_strjoin(&new, "\n");
			new_strjoin(&new, line);
		}
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
		trailing_quote(ret);
	}
	else
		ft_error("ERROR: Invalid name/comment.\n");
}
