/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_labels.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 10:18:57 by csphilli          #+#    #+#             */
/*   Updated: 2021/02/26 08:00:33 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	This function finds the target label within a node.
**	The get_node function is part of the library function set for lists.
**	It can be found in libft/srcs/ft_lstfuncs.c. The header file,
**	found in libft/includes/ll.h, contains information on how the function
**	is used. A compare_labels function is passed as an argument
**	which can be specific for any need of comparison. In this case
**	compare_labels compares the argument label vs each label in a linked
**	list of an instruction node. Recall that multiple labels can be applied
**	to a single instruction. That is why in the compare_labels func
**	that the comparison is being made between label->label and s2. If the
**	label is not found, NULL is returned which will result in an error
**	for unfound label.
**	compare_labels is found in label_utils.c
*/

t_node		*get_target(t_master *m, char *label)
{
	int		i;
	t_node	*tmp;
	t_node	*fnd;

	i = 0;
	fnd = NULL;
	while (!ft_strchr(LABEL_CHARS, label[i]))
		i++;
	tmp = ((t_list*)&m->instrux)->head;
	while (tmp)
	{
		fnd = get_node(&((t_ins*)tmp->data)->labels, \
			(int (*)(void*, void*))compare_labels, &label[i]);
		if (fnd != NULL)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

/*
**	Calculates the number of bytes from the start node, up to but not
**	including the end node.
*/

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

/*
**	Calculates the number of bytes from instruction to label.
**	The parent node is the location of the instruction set which
**	contains the label to be altered. Tgt is the node which contains
**	the location of the label being searched for.
**	Each node contains an index which helps assist ID if the tgt node
**	is before or after the parent node. That comparison will determine
**	which ordering of arguments are passed to the bytes_to_label func.
**	get_target is above.
**	bytes_to_label is above.
*/

char		*bytes_to_string(t_master *m, char *line, t_node *parent)
{
	t_node	*tgt;
	int		bytes;
	char	*label;

	bytes = 0;
	label = extract_label(line);
	tgt = get_target(m, label);
	if (tgt == NULL)
		label_not_found("ERROR: Invalid Label.", ((t_ins*)parent->data), label);
	if (((t_ins*)parent->data)->index < ((t_ins*)tgt->data)->index)
		bytes = bytes_to_label(parent, tgt);
	else
	{
		bytes = bytes_to_label(tgt, parent);
		bytes *= -1;
	}
	ft_strdel(&label);
	return (ft_itoa(bytes));
}

/*
**	Converts the labels to a number which corresponds to the number of bytes
**	to get to the respective label. It loops through all args converting
**	converting all labels.
**	bytes_to_string is above.
**	new_str_from_label is above.
*/

char		*convert_string(t_master *m, char *line, t_node *parent)
{
	int		i;
	char	*new;
	char	*value;

	i = 0;
	new = ft_strnew(50);
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] == LABEL_CHAR)
		{
			value = bytes_to_string(m, &line[i], parent);
			ft_strncat(new, value, ft_strlen(value));
			i += end_of_label(&line[i]);
			ft_strdel(&value);
		}
		else
			ft_charcat(new, line[i]);
		i++;
	}
	new = downsize(new);
	return (new);
}

void		handle_labels(t_master *m)
{
	t_node	*tmp;
	int		i;
	char	*bytes;
	t_ins	*ins;

	tmp = ((t_list*)&m->instrux)->head;
	while (tmp)
	{
		i = 0;
		ins = node_name_helper(tmp);
		ins->orig_arg_values = ft_memalloc(sizeof(char*) * ins->arg_count);
		while (i < ins->arg_count)
		{
			ins->orig_arg_values[i] = ft_strdup(ins->arg_values[i]);
			if (ins->arg_type[i] != T_REG)
			{
				bytes = convert_string(m, ins->arg_values[i], tmp);
				ft_strdel(&ins->arg_values[i]);
				ins->arg_values[i] = ft_strdup(bytes);
				ft_strdel(&bytes);
			}
			i++;
		}
		tmp = tmp->next;
	}
}
