/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_lfork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

/*
**	-opcode 15
**	-with the arg (dir) value, calculates a new spot where to create a new
**		carriage
**	-new carriage will have the same carry, last live_cycle, registry contents
**		(and color), as the original one
**	-unlike fork, no IDX_MOD when getting the new spot
*/

int		c_lfork(t_carriage *carriage, t_game *game)
{
	int	position;
	int	value;
	int	new_spot;

	position = move_pos(1, carriage->pc);
	value = get_two(position, game);
	new_spot = carriage->pc + value;
	if (game->print)
		ft_printf("P %4d | lfork %d (%d)\n", carriage->nr, value, new_spot);
	new_spot = move_pos(0, new_spot);
	add_child_carriage(new_spot, carriage, game);
	return (0);
}
