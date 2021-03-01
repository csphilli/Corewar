/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_sub.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

int	sub(t_carriage *carriage, t_game *game)
{
	int	value;
	int	reg1;
	int	reg2;
	int	reg3;
	int	pos;

	pos = move_pos(2, carriage->position);
	reg1 = game->memory[pos];
	pos = move_pos(3, carriage->position);
	reg2 = game->memory[pos];
	pos = move_pos(4, carriage->position);
	reg3 = game->memory[pos];
	value = carriage->regs[reg1 - 1] - carriage->regs[reg2 - 1];
	carriage->regs[reg3 - 1] = value;
	carriage->carry = 0;
	if (value == 0)
		carriage->carry = 1;
	if (game->print)
		printf("P %4d | sub r%d r%d r%d\n", carriage->nr, reg1, reg2, reg3);
	return (0);
}
