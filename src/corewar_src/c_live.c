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

/*
**	-opcode 1
**	-if the argument	(dir) is -(a player number), the specific player
**		is set to be the current winner
**	-carriage is kept alive if performs a live statement during cycles_to_die
**	-keeping track of all lives performed during the cycles for the next check
**	-l-flag outputs all player lives
*/

void	live_stat(int pl_nr, t_player *player)
{
	ft_putstr("A process shows that player ");
	ft_putnbr(pl_nr);
	ft_putstr(" (");
	ft_putstr(player->name);
	ft_putstr(") is alive\n");
}

int		live(t_carriage *carriage, t_game *game)
{
	int			position;
	int			value;
	t_player	*player;

	position = move_pos(1, carriage->pc);
	value = get_four(position, game);
	if (value <= -1 && value >= -(game->players))
	{
		game->last_alive = value;
		player = game->playerlist[-(value + 1)];
		player->lives++;
		if (player->lives == 2147483647)
			end_too_large(game);
		player->last_live = game->cycles + 1;
		if (game->live_print)
			live_stat(-value + 1, player);
	}
	carriage->last_live_cycle = game->cycles + 1;
	if (game->lives <= NBR_LIVE)
		game->lives++;
	if (game->print)
		ft_printf("P %4d | live %d\n", carriage->nr, value);
	return (0);
}
