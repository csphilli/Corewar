/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_ldi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2021/03/02 12:40:00 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

/*
**	-	take a value (arg1/ reg | ind | dir)
**	-	take another value (arg2/ reg | dir)
**	-	add them to get a memory spot
**	-	get a value from the memory spot an
**		put it in a registry (arg3)
*/

int		ldi(t_arguments args, t_carriage *carriage, t_game *game)
{
	int	destination_reg;
	int	memory1;
	int	memory2;
	int	memory_spot;
	int	pos;

	pos = move_pos(2, carriage->position);
	memory1 = get_value(args.arg[0], pos, carriage, game);
	pos = move_pos(arg_len(args.arg[0], 2), pos);
	memory2 = get_value(args.arg[1], pos, carriage, game);
	pos = move_pos(arg_len(args.arg[1], 2), pos);
	destination_reg = game->memory[pos];
	memory_spot = carriage->position + ((memory1 + memory2) % IDX_MOD);
	if (game->print)
	{
		ft_printf("P %4d | ldi %d %d r%d\n",
		carriage->nr, memory1, memory2, destination_reg);
		ft_printf("       | -> load from %d + %d = %d ",
		memory1, memory2, memory1 + memory2);
		ft_printf("(with pc and mod %d)\n", memory_spot);
	}
	memory_spot = move_pos(0, memory_spot);
	memory_spot = get_four(memory_spot, game);
	carriage->regs[destination_reg - 1] = memory_spot;
	return (0);
}
