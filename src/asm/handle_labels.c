/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_labels.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 10:18:57 by csphilli          #+#    #+#             */
/*   Updated: 2021/02/06 12:10:51 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*new_str_from_label(t_ins *node, int arg_nbr, char *bytes)
{
	int		len;
	char	*new;

	len = 0;
	if (node->arg_values[arg_nbr])
		ft_strdel(&node->arg_values[arg_nbr]);
	if (node->arg_type[arg_nbr] == T_DIR)
		len++;
	len += ft_strlen(bytes);
	new = ft_strnew(len);
	if (node->arg_type[arg_nbr] == T_DIR)
		new[0] = '%';
	ft_strcat(new, bytes);
	return (new);
}

t_node		*get_target(t_master *m, char *label)
{
	int		i;
	t_node	*tmp;

	i = 0;
	while (!ft_strchr(LABEL_CHARS, label[i]))
		i++;
	tmp = ((t_list*)&m->instrux)->head;
	while (tmp)
	{
		if (((t_ins*)tmp->data)->label && \
			ft_strequ(((t_ins*)tmp->data)->label, &label[i]))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int			bytes_to_label(t_node *start, t_node *end)
{
	t_node	*tmp;
	int		bytes;

	tmp = start;
	bytes = 0;
	while (tmp)
	{
		if (tmp == end)
			break ;
		bytes += ((t_ins*)tmp->data)->bytes;
		tmp = tmp->next;
	}
	return (bytes);
}

char		*bytes_to_string(t_master *m, char **label, t_node *parent)
{
	t_node	*tgt;
	int		bytes;

	bytes = 0;
	tgt = get_target(m, *label);
	if (tgt == NULL)
		ft_error_line("ERROR: Could not find label in instruction ", \
			((t_ins*)parent->data)->index + 1);
	if (((t_ins*)parent->data)->index < ((t_ins*)tgt->data)->index)
		bytes = bytes_to_label(parent, tgt);
	else
	{
		bytes = bytes_to_label(tgt, parent);
		bytes *= -1;
	}
	return (ft_itoa(bytes));
}

void		handle_labels(t_master *m)
{
	t_node	*tmp;
	int		i;
	char	*bytes;

	tmp = ((t_list*)&m->instrux)->head;
	while (tmp)
	{
		i = 0;
		while (i < ((t_ins*)tmp->data)->arg_count)
		{
			if (ft_strchr(((t_ins*)tmp->data)->arg_values[i], LABEL_CHAR))
			{
				bytes = bytes_to_string(m, \
					&((t_ins*)tmp->data)->arg_values[i], tmp);
				((t_ins*)tmp->data)->arg_values[i] = \
					new_str_from_label(((t_ins*)tmp->data), i, bytes);
				ft_strdel(&bytes);
			}
			i++;
		}
		tmp = tmp->next;
	}
}
