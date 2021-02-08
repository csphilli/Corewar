/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:20:35 by csphilli          #+#    #+#             */
/*   Updated: 2021/02/08 12:30:11 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
}

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
			ft_error("Error: Invalid Label.\n");
		i++;
	}
	save_label(m, line);
}
