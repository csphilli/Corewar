/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_fork.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2021/03/02 12:40:00 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

int		c_fork(t_carriage *carriage, t_game *game)
{
	int	position;
	int	value;
	int	new_spot;

	position = move_pos(1, carriage->position);
	value = get_two(position, game);
	new_spot = carriage->position + (value % IDX_MOD);
	if (game->print)
		ft_printf("P %4d | fork %d (%d)\n", carriage->nr, value, new_spot);
	new_spot = move_pos(0, new_spot);
	add_child_carriage(new_spot, carriage, game);
	return (0);
}
