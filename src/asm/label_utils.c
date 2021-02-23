/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:20:35 by csphilli          #+#    #+#             */
/*   Updated: 2021/02/23 16:50:08 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

/*
**	Used in conjuction with the get_node function found in handle_labels.c
**	Simply returns the result of string comparison between label names.
*/

int		compare_labels(t_labels *label, char *s2)
{
	return (ft_strcmp(label->label, s2));
}

/*
**	Helper function to reduce the amount of typecasting when using generic
**	data sources. Instead of having to type ((t_ins*)tmp->data)->a_struct_field
**	this returns a pointer to the t_ins struct. Instead it would just be
**	ins->a_struct_field.
*/

t_ins	*node_name_helper(t_node *node)
{
	return (((t_ins*)node->data));
}

/*
**	Used to reduce the size of a string after label and hex conversions.
**	Originally the str size is set to the original string such as
**	:loop + 0xae05. After conversion that could be 7+44549 which is less
**	in str size than the original. To save space, a downsizing is performed.
*/

char	*downsize(char *line)
{
	char	*tmp;

	tmp = line;
	if (line)
		ft_strdel(&line);
	line = ft_strdup(tmp);
	return (line);
}

/*
**	Saves the label to m->labels.
*/

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

/*
**	Checks whether or not the line is a label
*/

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
