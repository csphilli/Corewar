/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfuncs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 22:15:37 by cphillip          #+#    #+#             */
/*   Updated: 2021/02/09 09:22:12 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	init_list(t_list *list)
{
	list->head = NULL;
	list->tail = NULL;
	list->cur = NULL;
}

void	delete_node(t_list *list, t_node *node)
{
	t_node *tmp;

	if (list->head && list->head == node)
	{
		if (!list->head->next)
		{
			list->head = NULL;
			list->tail = NULL;
		}
		else
			list->head = list->head->next;
	}
	else
	{
		tmp = list->head;
		while (tmp && tmp->next != node)
			tmp = tmp->next;
		if (tmp)
			tmp->next = node->next;
	}
	free(node);
}

void	*get_node(t_list *list, t_compare compare, void *data)
{
	t_node *tmp;

	tmp = list->head;
	while (tmp)
	{
		if (compare(tmp->data, data) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	display_list(t_list *list, t_display display)
{
	t_node *tmp;

	tmp = list->head;
	while (tmp)
	{
		display(tmp->data);
		tmp = tmp->next;
	}
}
