/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_st.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2021/03/02 12:40:00 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

/*
**	-	take value from reg (arg1)
**	-	put it to a registry (arg2/reg)
**	-	OR write it to memory (arg2/ind)
*/

int	st(t_arguments args, t_carriage *carriage, t_game *game)
{
	int	reg;
	int	reg_content;
	int	destination_reg;
	int	memory_spot;
	int	pos;

	reg = game->memory[move_pos(2, carriage->position)];
	reg_content = carriage->regs[reg - 1];
	pos = move_pos(3, carriage->position);
	if (args.arg[1] == T_REG)
	{
		destination_reg = game->memory[pos];
		carriage->regs[destination_reg - 1] = reg_content;
		if (game->print)
			ft_printf("P %4d | st r%d %d\n", carriage->nr, reg, destination_reg);
	}
	else
	{
		memory_spot = get_two(pos, game);
		if (game->print)
			ft_printf("P %4d | st r%d %d\n", carriage->nr, reg, memory_spot);
		memory_spot = carriage->position + (memory_spot % IDX_MOD);
		write_to_memory(reg_content, memory_spot, carriage, game);
	}
	return (0);
}
