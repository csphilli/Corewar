/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_and.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

/*
**	-opcode 6
**	-stores the result of arg1 (reg/ind/dir) & arg2 (reg/ind/dir) in reg arg3
**	-modifies the carry
*/

int	and(t_arguments args, t_carriage *carriage, t_game *game)
{
	int	value1;
	int	value2;
	int	res;
	int	reg;
	int	pos;

	pos = move_pos(2, carriage->pc);
	value1 = get_value(args.arg[0], pos, carriage, game);
	pos = move_pos(arg_len(args.arg[0], 4), pos);
	value2 = get_value(args.arg[1], pos, carriage, game);
	pos = move_pos(arg_len(args.arg[1], 4), pos);
	reg = game->memory[pos] - 1;
	res = value1 & value2;
	carriage->regs[reg] = res;
	carriage->carry = 0;
	if (res == 0)
		carriage->carry = 1;
	if (game->print)
		ft_printf("P %4d | and %d %d r%d\n",
		carriage->nr, value1, value2, reg + 1);
	return (0);
}
