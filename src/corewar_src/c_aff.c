/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_aff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

int		aff(t_carriage *carriage, t_game *game)
{
	int	pos;
	int	reg;
	int	value;

	pos = move_pos(2, carriage->position);
	reg = game->memory[pos] - 1;
	value = carriage->regs[reg];
	value %= 256;
	printf("P %4d | aff %d\n", carriage->nr, value);
	return (0);
}
