/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_comment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:21:53 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/26 16:26:06 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:44:19 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/26 09:25:03 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		comment_exists(t_node *node)
{
	int		a;
	int		i;
	int		j;

	a = 0;
	i = 0;
	j = 0;
	if (ft_strncmp(((t_input*)node->data)->line, ".comment", \
	sizeof(char) * 8) == 0)
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

int		get_comment(t_list *list, t_champ *champ, int i)
{
	t_node	*node;
	int		j;
	int		x;

	x = 0;
	node = get_node_at_index(list, i);
	if ((j = comment_exists(node)) > 0)
	{
		while (((t_input*)node->data)->line[j] != '"' && x < COMMENT_LENGTH)
		{
			champ->comment[x] = ((t_input*)node->data)->line[j];
			x++;
			j++;
		}
		while (x < COMMENT_LENGTH)
		{
			champ->comment[x] = '0';
			x++;
		}
		champ->comment[x] = '\0';
	}
	else
		ft_handle_error("ERROR: Name not defined.\n", 1);
	i++;
	return (i);
}
