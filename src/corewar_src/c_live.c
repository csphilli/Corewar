/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_live.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2021/03/02 12:40:00 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

int	live(t_carriage *carriage, t_game *game)
{
	int	position;
	int	value;

	position = move_pos(1, carriage->position);
	value = get_four(position, game);
	if (value <= -1 && value >= -(game->players))
	{
		game->last_alive = value;
		game->playerlist[-(value + 1)]->lives++;
		game->playerlist[-(value + 1)]->last_live = game->cycles + 1;
	}
	carriage->last_live_cycle = game->cycles + 1;
	game->lives++;
	if (game->print)
		ft_printf("P %4d | live %d\n", carriage->nr, value);
	return (0);
}
