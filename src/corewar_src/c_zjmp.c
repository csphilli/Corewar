/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_zjmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

int	zjmp(t_carriage *carriage, t_game *game)
{
	int	position;
	int	value;

	position = move_pos(1, carriage->pc);
	value = get_two(position, game);
	if (game->print)
		ft_printf("P %4d | zjmp %d ", carriage->nr, value);
	if (carriage->carry == 1)
	{
		if (game->print)
			ft_printf("OK\n");
		carriage->to_next = (value % IDX_MOD);
	}
	else if (game->print)
		ft_printf("FAILED\n");
	return (0);
}
