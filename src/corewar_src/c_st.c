/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_st.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

/*
**	-opcode 3
**	-take value from reg (arg1)
**	-put it to a registry (arg2/reg)
**	-OR write it to memory (arg2/ind)
*/

int	st(t_arguments args, t_carriage *carriage, t_game *game)
{
	int	reg;
	int	reg_content;
	int	dest_reg;
	int	memory_spot;
	int	pos;

	reg = game->memory[move_pos(2, carriage->pc)];
	reg_content = carriage->regs[reg - 1];
	pos = move_pos(3, carriage->pc);
	if (args.arg[1] == T_REG)
	{
		dest_reg = game->memory[pos];
		carriage->regs[dest_reg - 1] = reg_content;
		if (game->print)
			ft_printf("P %4d | st r%d %d\n", carriage->nr, reg, dest_reg);
	}
	else
	{
		memory_spot = get_two(pos, game);
		if (game->print)
			ft_printf("P %4d | st r%d %d\n", carriage->nr, reg, memory_spot);
		memory_spot = carriage->pc + (memory_spot % IDX_MOD);
		write_to_memory(reg_content, memory_spot, carriage, game);
	}
	return (0);
}
