/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:20:35 by csphilli          #+#    #+#             */
/*   Updated: 2021/02/09 10:16:41 by csphilli         ###   ########.fr       */
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

// subject to change since a label and instruction can be on the same line

int				is_label(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr(LABEL_CHARS, line[i]))
			break ;
		i++;
	}
	if (line[i] == LABEL_CHAR)
		return (1);
	return (0);
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

// subject to change given labels and instructions can be on the same line.

void	validate_label(t_master *m, char *line)
{
	int i;
	int	flag;

	i = 0;
	flag = 0;
	while (line[i] != LABEL_CHAR)
		i++;
	i++;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] == COMMENT_CHAR || line[i] == ALT_COMMENT_CHAR)
			flag = 1;
		if (line[i] != ' ' && line[i] != '\t' && flag == 0)
			ft_error_line("Error: Invalid label on line ", m->line_cnt);
		i++;
	}
	save_label(m, line);
}
