/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:32:36 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/31 17:10:57 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	get_data(t_champ *champ, int fd)
{
	char	*line;
	char	*tmp;

	while (get_next_line(fd, &line) > 0)
	{
		tmp = line;
		while ((*tmp == ' ' || *tmp == '\t') && *tmp != '\0')
			tmp++;
		// printf("tmp: >%s< | addy: %p\n", tmp, tmp);
		if (ft_strnstr(tmp, NAME_CMD_STRING, NAME_CMD_LEN))
		{
			(champ->champ_name) ? ft_error("ERROR: Multiple names.\n") : \
			get_name_comment(&champ->champ_name, line, fd);
		}
		else if (ft_strnstr(tmp, COMMENT_CMD_STRING, COMMENT_CMD_LEN))
		{
			(champ->comment) ? ft_error("ERROR: Multiple comments.\n") : \
			get_name_comment(&champ->comment, line, fd);
		}
		else
			analyse_statement(tmp);
		ft_strdel(&line);
	}
}
