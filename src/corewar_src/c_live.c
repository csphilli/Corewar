/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_live.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

int	live(t_carriage *carriage, t_game *game)
{
	int	position;
	int	value;

	position = move_pos(1, carriage->pc);
	value = get_four(position, game);
	if (value <= -1 && value >= -(game->players))
	{
		game->last_alive = value;
		game->playerlist[-(value + 1)]->lives++;
		game->playerlist[-(value + 1)]->last_live = game->cycles + 1;
		if (LIVE == 1 && game->visual == 0 && game->print == 0)
		{
			ft_putstr("A process shows that player ");
			ft_putnbr(-game->last_alive);
			ft_putstr(" (");
			ft_putstr(game->playerlist[-(game->last_alive + 1)]->name);
			ft_putstr(") is alive\n");
		}
	}
	carriage->last_live_cycle = game->cycles + 1;
	game->lives++;
	if (game->print)
		ft_printf("P %4d | live %d\n", carriage->nr, value);
	return (0);
}
