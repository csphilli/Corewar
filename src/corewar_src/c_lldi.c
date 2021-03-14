/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_lldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

/*
**	-opcode 14
**	-take a value (arg1/ reg | ind | dir)
**	-take another value (arg2/ reg | dir)
**	-add them to get a memory spot
**	-get a value from the memory spot an
**		put it in a registry (arg3)
**	-modify carry
*/

int	lldi(t_arguments args, t_carriage *carriage, t_game *game)
{
	int	reg;
	int	mem1;
	int	mem2;
	int	memory_spot;
	int	pos;

	pos = move_pos(2, carriage->pc);
	mem1 = get_value(args.arg[0], pos, carriage, game);
	pos = move_pos(arg_len(args.arg[0], 2), pos);
	mem2 = get_value(args.arg[1], pos, carriage, game);
	pos = move_pos(arg_len(args.arg[1], 2), pos);
	memory_spot = carriage->pc + mem1 + mem2;
	reg = game->memory[pos];
	if (game->print)
	{
		ft_printf("P %4d | lldi %d %d r%d\n", carriage->nr, mem1, mem2, reg);
		ft_printf("       | -> load from %d + %d = %d (with pc %d)\n",
		mem1, mem2, mem1 + mem2, memory_spot);
	}
	memory_spot = get_four(move_pos(0, memory_spot), game);
	carriage->regs[reg - 1] = memory_spot;
	carriage->carry = 0;
	if (carriage->regs[reg - 1] == 0)
		carriage->carry = 1;
	return (0);
}
