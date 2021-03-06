/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_lld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

/*
**	-opcode 13
**	-get a value form reg or ind (arg1)
**	-unlike ld, does not use IDX_MOD when getting ind value
**	-put to a registry (arg2)
**	-modify carry
*/

int	lld(t_arguments args, t_carriage *carriage, t_game *game)
{
	int	value;
	int	dest_reg;
	int	pos;

	pos = move_pos(2, carriage->pc);
	value = get_value(args.arg[0], pos, carriage, game);
	pos = move_pos(arg_len(args.arg[0], 4), pos);
	dest_reg = game->memory[pos] - 1;
	carriage->regs[dest_reg] = value;
	carriage->carry = 0;
	if (value == 0)
		carriage->carry = 1;
	if (game->print)
		ft_printf("P %4d | lld %d r%d\n", carriage->nr, value, dest_reg + 1);
	return (0);
}
