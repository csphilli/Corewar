/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

void	remove_car(t_carriage *last, t_carriage *temp, t_game *game)
{
	if (game->visual)
		normal(1, temp->pc, game);
	if (last)
		last->next = temp->next;
	else
		game->carriages = temp->next;
	free(temp);
	temp = NULL;
	game->carrs_alive -= 1;
}

/*
**	-if a carriage has not performed a live statement during the last
**		cycles_to_die, it will be removed
**	-if cycles_to_die is zero or less, all carriages are removed (->game ends)
*/

void	remove_dead_carriages(t_game *game)
{
	t_carriage	*last;
	t_carriage	*temp;
	t_carriage	*temp2;

	last = NULL;
	temp = game->carriages;
	while (temp)
	{
		temp2 = temp->next;
		if (game->cycles - temp->last_live_cycle >= game->cycles_to_die ||
			game->cycles_to_die <= 0)
			remove_car(last, temp, game);
		else
			last = temp;
		temp = temp2;
	}
}

int		reset_player_lives(t_game *game)
{
	int			i;
	t_player	*player;

	i = 0;
	while (i < game->players)
	{
		player = game->playerlist[i];
		player->lives = 0;
		i++;
	}
	return (0);
}

/*
**	-reduce cycles_to_die if amount of all lives during the last cycles_to_die
**		is NBR_LIVES or more or if it has been less for MAX_CHECKS checks
**	-individual player lives per round are counted for the visual mode
*/

int		check(t_game *game)
{
	remove_dead_carriages(game);
	if (game->lives >= NBR_LIVE)
	{
		game->cycles_to_die -= CYCLE_DELTA;
		game->checks = 0;
	}
	else
	{
		game->checks++;
		if (game->checks == MAX_CHECKS)
		{
			game->cycles_to_die -= CYCLE_DELTA;
			game->checks = 0;
		}
	}
	game->lives = 0;
	reset_player_lives(game);
	return (0);
}
