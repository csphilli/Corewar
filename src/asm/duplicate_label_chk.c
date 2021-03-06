/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_label_chk.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 08:23:25 by csphilli          #+#    #+#             */
/*   Updated: 2021/03/06 08:28:57 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	duplicate_label_error(char *label_name)
{
	ft_putstr_fd("ERROR: More than one label named '", 2);
	ft_putstr_fd(label_name, 2);
	ft_putstr_fd("' found in code.\n", 2);
	exit(0);
}

int		scan_instruction_labels(t_node *head, char *name)
{
	int cnt;

	cnt = 0;
	while (head)
	{
		if (ft_strequ(((t_labels*)head->data)->label, name))
			cnt++;
		head = head->next;
	}
	return (cnt);
}

int		scan_entire_instruction_set(t_master *m, char *name)
{
	int		cnt;
	t_node	*head;

	cnt = 0;
	head = ((t_list*)&m->instrux)->head;
	while (head)
	{
		if ((t_list*)&((t_ins*)head->data)->labels)
			cnt += scan_instruction_labels(((t_list*)&((t_ins*)\
			head->data)->labels)->head, name);
		head = head->next;
	}
	return (cnt);
}

void	label_dup_chk(t_master *m)
{
	t_node	*tmp;
	t_node	*inner;
	t_ins	*cur;
	int		cnt;

	cnt = 0;
	tmp = ((t_list*)&m->instrux)->head;
	while (tmp)
	{
		cur = node_name_helper(tmp);
		if (((t_list*)&cur->labels)->head)
		{
			inner = ((t_list*)&cur->labels)->head;
			while (inner)
			{
				cnt = scan_entire_instruction_set(m, \
				((t_labels*)inner->data)->label);
				if (cnt > 1)
					duplicate_label_error(((t_labels*)inner->data)->label);
				inner = inner->next;
			}
		}
		tmp = tmp->next;
	}
}
