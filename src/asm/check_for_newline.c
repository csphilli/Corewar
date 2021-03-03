/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_newline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:50:12 by osalmine          #+#    #+#             */
/*   Updated: 2021/03/03 13:22:48 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	str_append(char **lines, char *append)
{
	char *tmp;

	if (!*lines)
		tmp = ft_strdup(append);
	else
		tmp = ft_strjoin(*lines, append);
	ft_memdel((void**)lines);
	*lines = ft_strdup(tmp);
	ft_strdel(&tmp);
}

static void	end_check(char *lines)
{
	int		len;

	len = ft_strlen(lines) - 1;
	while (lines[len] != '\n')
	{
		if (!ft_isspace(lines[len]))
			ft_errorexit("Syntax error - unexpected end of input \
(Perhaps you forgot to end with a newline ?)\n");
		len--;
	}
}

/*
**	Read the file to check if the input file has a newline at
**	end of it. The input file can have spaces and tabs after
**	the final newline
*/

void		check_for_newline(t_master *m)
{
	int		fd;
	char	line[NL_CHECK_BUFF_SIZE + 1];
	char	*lines;
	int		ret;

	fd = 0;
	lines = NULL;
	if ((fd = open(m->filename, fd, O_RDONLY)) < 0)
		ft_errorexit("Error on reading input file\n");
	while ((ret = read(fd, line, NL_CHECK_BUFF_SIZE)) > 0)
	{
		line[ret] = '\0';
		str_append(&lines, line);
	}
	if (ret < 0 || !lines)
		ft_errorexit("ERROR: Read error");
	end_check(lines);
	ft_strdel(&lines);
}
