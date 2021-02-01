/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:32:36 by cphillip          #+#    #+#             */
/*   Updated: 2021/02/01 21:19:05 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	get_data(t_master *m, int fd)
{
	char	*line;
	char	*tmp;

	while (get_next_line(fd, &line) > 0)
	{
		tmp = line;
		while ((*tmp == ' ' || *tmp == '\t') && *tmp != '\0')
			tmp++;
		if (ft_strnstr(tmp, NAME_CMD_STRING, NAME_CMD_LEN))
		{
			(m->champ->champ_name) ? \
			ft_error("ERROR: Multiple names.\n") : \
			get_name_comment(&m->champ->champ_name, line, fd);
		}
		else if (ft_strnstr(tmp, COMMENT_CMD_STRING, COMMENT_CMD_LEN))
		{
			(m->champ->champ_comment) ? \
			ft_error("ERROR: Multiple comments.\n") : \
			get_name_comment(&m->champ->champ_comment, line, fd);
		}
		else
			tokenizing(m, tmp);
		ft_strdel(&line);
	}
}
