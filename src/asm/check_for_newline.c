/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_newline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:50:12 by osalmine          #+#    #+#             */
/*   Updated: 2021/03/11 12:00:59 by osalmine         ###   ########.fr       */
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

static void	end_check(char *lines, int last_ins)
{
	int		len;
	int		nl_count;

	len = 0;
	nl_count = 0;
	while (lines[len])
	{
		if (lines[len] == '\n')
			nl_count++;
		len++;
	}
	if (nl_count < last_ins)
		ft_errorexit("Syntax error - unexpected end of input \
(Perhaps you forgot to end with a newline ?)\n");
}

/*
**	Read the file to check if the input file has a newline at
**	the end of the last instruction.
*/

void		check_for_newline(t_master *m)
{
	int		fd;
	char	line[NL_CHECK_BUFF_SIZE + 1];
	char	*lines;
	int		ret;
	t_node	*tmp;

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
	tmp = ((t_list*)&m->instrux)->head;
	while (tmp && tmp->next)
		tmp = tmp->next;
	end_check(lines, tmp ? ((t_ins*)tmp->data)->line : 0);
	ft_strdel(&lines);
}
