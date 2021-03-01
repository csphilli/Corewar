/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_sti.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

/*
**	-	take a value (arg2/ reg | ind | dir)
**	-	take another value (arg3/ reg | dir)
**	-	add these to get a memory spot
**	-	get a value from a registry (arg1) and write it to the memory
*/

int	sti(t_arguments args, t_carriage *carriage, t_game *game)
{
	int	reg;
	int	memory1;
	int	memory2;
	int	memory_spot;
	int	pos;

	pos = move_pos(2, carriage->position);
	reg = game->memory[pos];
	pos = move_pos(3, carriage->position);
	memory1 = get_value(args.arg[1], pos, carriage, game);
	pos = move_pos(arg_len(args.arg[1], 2), pos);
	memory2 = get_value(args.arg[2], pos, carriage, game);
	memory_spot = carriage->position + ((memory1 + memory2) % IDX_MOD);
	if (game->print)
	{
		printf("P %4d | sti r%d %d %d\n", carriage->nr, reg, memory1, memory2);
		printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
		memory1, memory2, memory1 + memory2, memory_spot);
	}
	write_to_memory(carriage->regs[reg - 1], memory_spot, carriage, game);
	return (0);
}
