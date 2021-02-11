/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:20:35 by csphilli          #+#    #+#             */
/*   Updated: 2021/02/11 12:49:52 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	Used in conjuction with the get_node function found in handle_labels.c
**	Simply returns the result of string comparison between label names.
*/

int		compare_labels(t_labels *label, char *s2)
{
	return (ft_strcmp(label->label, s2));
}

void	save_label(t_master *m, char *line)
{
	t_labels	*label;
	int			i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t' || line[i] == LABEL_CHAR)
			break ;
		i++;
	}
	label = ft_memalloc(sizeof(t_labels));
	label->label = ft_strnew(i);
	ft_memcpy(label->label, line, sizeof(char) * i);
	append_node(&m->labels, label);
	m->line_cnt++;
}

int		is_label(char *line)
{
	int	i;

	i = 0;
	while (ft_strchr(LABEL_CHARS, line[i]))
		i++;
	if (line[i] == LABEL_CHAR)
		return (i + 1);
	return (0);
}
