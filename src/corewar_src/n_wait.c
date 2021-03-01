/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_wait.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

void	add_waiter(int position, t_game *game)
{
	t_waiter	*new_waiter;
	t_waiter	*temp;

	new_waiter = (t_waiter*)malloc(sizeof(t_waiter));
	new_waiter->position = position;
	new_waiter->wait = 50;
	temp = game->waiters;
	game->waiters = new_waiter;
	new_waiter->next = temp;
}

void	remove_waiter(t_waiter *last, t_waiter *temp, t_game *game)
{
	if (game->cols[temp->position] < 0 || game->cols[temp->position] > 99)
		normal(1, temp->position, game);
	if (last)
		last->next = temp->next;
	else
		game->waiters = temp->next;
	free(temp);
	temp = NULL;
}

void	check_waiters(t_game *game)
{
	t_waiter	*temp;
	t_waiter	*last;
	t_waiter	*temp2;

	last = NULL;
	temp = game->waiters;
	while (temp != NULL)
	{
		temp2 = temp->next;
		temp->wait -= 1;
		if (temp->wait == 0)
			remove_waiter(last, temp, game);
		else
			last = temp;
		temp = temp2;
	}
}

void	delete_wait(int position, t_game *game)
{
	t_waiter	*temp;
	t_waiter	*last;
	t_waiter	*temp2;

	last = NULL;
	temp = game->waiters;
	while (temp != NULL)
	{
		temp2 = temp->next;
		if (temp->position == position)
		{
			normal(1, temp->position, game);
			if (last)
				last->next = temp->next;
			else
				game->waiters = temp->next;
			free(temp);
			temp = NULL;
		}
		if (temp)
			last = temp;
		temp = temp2;
	}
}
