/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:44:19 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/25 20:26:35 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		name_exists(t_node *node)
{
	int		a;
	int		i;
	int		j;

	a = 0;
	i = 0;
	j = 0;

	if (ft_strncmp(((t_input*)node->data)->line, ".name", \
	sizeof(char) * 5) == 0)
	{
		while (((t_input*)node->data)->line[i] != '\n')
		{
			if (((t_input*)node->data)->line[i] == '"')
			{
				if (j == 0)
					j = i;
				a++;
			}
			i++;
		}
	}
	if (a == 2)
		return (j);
	return (0);
}

t_node	*get_node_at_index(t_list *list, int index)
{
	t_node *tmp;

	tmp = list->head;
	while (tmp)
	{
		if (((t_input*)tmp->data)->index == index)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int		get_name(t_list *list, t_champ *champ, int i)
{
	t_node *node;
	int j;

	node = get_node_at_index(list, i);
	printf("node: %s", ((t_input*)node->data)->line);
	if ((j = name_exists(node)) > 0)
		printf("name exists: %d\n", j);
	return (j);
}
