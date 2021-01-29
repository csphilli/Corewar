/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name_comment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 18:24:45 by csphilli          #+#    #+#             */
/*   Updated: 2021/01/29 18:27:26 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		trailing_spaces(char *line)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (line[i] != '\"')
	{
		if (line[i] != ' ' && line[i] != '\t')
			c = 0;
		i++;
		c++;
	}
	return (i - c + 1);
}

void	ws_name_comment(char **ret)
{
	size_t		i;
	size_t		start;
	char		*tmp;

	i = 0;
	start = 0;
	tmp = *ret;
	ft_strdel(ret);
	while (tmp[start] == ' ' || tmp[start] == '\t')
		start++;
	i = start;
	i = trailing_spaces(&tmp[i]);
	*ret = ft_strndup(&tmp[start], i);
}

void	new_strjoin(char **dst, char *src)
{
	char *tmp;

	tmp = *dst;
	ft_strdel(dst);
	*dst = ft_strjoin(tmp, src);
	ft_strdel(&src);
}

char	*cont_reading(char *line, int fd)
{
	char	*tmp;
	char	*nl;
	int		flag;

	flag = 0;
	nl = ft_strdup(line);
	while (get_next_line(fd, &line) > 0)
	{
		if (!ft_strchr(line, '\"'))
			new_strjoin(&nl, line);
		else if (ft_strchr(line, '\"') && \
		(!ft_strnstr(line, NAME_CMD_STRING, NAME_CMD_LEN) && \
		!ft_strnstr(line, COMMENT_CMD_STRING, COMMENT_CMD_LEN)))
		{
			flag = 1;
			new_strjoin(&nl, line);
			break ;
		}
		else
			ft_error("ERROR: Invalid name/comment string\n");
	}
	if (!flag)
		ft_error("ERROR: Invalid name/comment string\n");
	return (nl);
}

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
		ws_name_comment(ret);
	}
	else
		ft_error("ERROR: Missing name/comment.\n");
}
