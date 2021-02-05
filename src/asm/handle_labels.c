/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_labels.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 10:18:57 by csphilli          #+#    #+#             */
/*   Updated: 2021/02/05 20:09:38 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "ll.h"

// int		compare_label(char *name1, char *name2)
// {
// 	if (name1 && name2)
// 	{
// 		printf("comparing >%s< against sent >%s<\n", name1, name2);
// 		return(ft_strcmp(name1, name2));

// 	}
// 	else
// 		return (0);
// }

int		label_index(t_master *m, char *label)
{
	int		dst_index;
	int		i;
	t_node 	*tmp;

	dst_index = 0;
	i = 0;
	while (!ft_strchr(LABEL_CHARS, label[i]))
		i++;
	tmp = ((t_list*)&m->instrux)->head;
	while (tmp)
	{
		if (((t_ins*)tmp->data)->label && \
			ft_strequ(((t_ins*)tmp->data)->label, &label[i]))
			break ;
		tmp = tmp->next;
		dst_index++;
	}
	((t_list*)&m->instrux)->cur = tmp;
	return (dst_index);
}

int		byte_loc(t_master *m, char *label, int home)
{
	int	dst_index;
	int	i;
	int	neg;
	t_node *node;

	dst_index = label_index(m, label);
	node = ((t_list*)&m->instrux)->cur;
	neg = -1;
	printf("List Cur: >%s< @ index: %d\n", ((t_ins*)node->data)->opname, \
	 ((t_ins*)node->data)->index);
	printf("Label in instruction %d referring to index %d\n", home, dst_index);

}

char	modify_label(t_master *m, char **label, int index)
{
	char *tmp;
	int	bytes;

	tmp = *label;
	// ft_strdel(label);
	bytes = byte_loc(m, tmp, index);
	// printf("modifying %s at instruction %d\n", tmp, index);
}

void	handle_labels(t_master *m)
{
	t_node *tmp;
	int		i;

	printf("handling labels\n");
	tmp = ((t_list*)&m->instrux)->head;
	while (tmp)
	{
		i = 0;
		printf("--- Instruction %d ---\n", ((t_ins*)tmp->data)->index);
		while (i < ((t_ins*)tmp->data)->arg_count)
		{
			if (ft_strchr(((t_ins*)tmp->data)->arg_values[i], LABEL_CHAR))
			{

				modify_label(m, &((t_ins*)tmp->data)->arg_values[i], \
				((t_ins*)tmp->data)->index);
				printf("Found a label: %s\n", ((t_ins*)tmp->data)->arg_values[i]);
			}
				// ((t_ins*)tmp->data)->arg_values[i] = modify_label(m, tmp);
			i++;
		}
		// printf("tmp: %s\n", ((t_ins*)tmp->data)->opname);
		tmp = tmp->next;
	}


	
}