/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name_comment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 18:24:45 by csphilli          #+#    #+#             */
/*   Updated: 2021/02/02 11:57:01 by csphilli         ###   ########.fr       */
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

char	*cont_reading(char *line, int fd)
{
	char	*nl;
	int		flag;

	flag = 0;
	nl = ft_strdup(line);
	while (get_next_line(fd, &line) > 0)
	{
		if (!ft_strchr(line, '\"'))
		{
			new_strjoin(&nl, "\n");
			new_strjoin(&nl, line);
		}
		else if (ft_strchr(line, '\"'))
		{
			flag = 1;
			new_strjoin(&nl, "\n");
			new_strjoin(&nl, line);
			ft_strdel(&line);
			break ;
		}
		ft_strdel(&line);
	}
	if (!flag)
		ft_error("ERROR: Invalid name/comment string\n");
	return (nl);
}

/*
**  Shared function. If str is one line, strdup it.
**  If not, go into cont_reading and create a whole string
**  or error if invalid input.
*/

void	get_name_comment(char **ret, char *line, int fd)
{
	int	i;

	i = 0;
	if (ft_strchr(line, '\"'))
	{
		while (line[i] != '\"')
			i++;
		if (ft_strchr(&line[++i], '\"'))
			*ret = ft_strdup(&line[i]);
		else
			*ret = cont_reading(&line[i], fd);
		trailing_quote(ret);
	}
	else
		ft_error("ERROR: Missing name/comment.\n");
}
