/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:44:19 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/26 16:24:34 by cphillip         ###   ########.fr       */
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
		return (j + 1);
	return (0);
}



int		get_name(t_list *list, t_champ *champ, int i)
{
	t_node	*node;
	int		j;
	int		x;

	x = 0;
	node = get_node_at_index(list, i);
	if ((j = name_exists(node)) > 0)
	{
		while (((t_input*)node->data)->line[j] != '"' && x < PROG_NAME_LENGTH)
		{
			champ->prog_name[x] = ((t_input*)node->data)->line[j];
			x++;
			j++;
		}
		while (x < PROG_NAME_LENGTH)
		{
			champ->prog_name[x] = '0';
			x++;
		}
		champ->prog_name[x] = '\0';
	}
	else
		ft_handle_error("ERROR: Name not defined.\n", 1);
	i++;
	return (i);
}
