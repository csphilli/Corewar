/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:22:22 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/26 16:22:38 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
