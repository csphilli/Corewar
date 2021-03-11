/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

int	reg_value(int pos, t_carriage *carriage, t_game *game)
{
	int	value;
	int	reg;

	reg = game->memory[pos];
	value = carriage->regs[reg - 1];
	return (value);
}

int	ind_value(int pos, t_carriage *carriage, t_game *game)
{
	int	value;
	int	jump;
	int	new_position;

	jump = get_two(pos, game);
	new_position = carriage->pc + (jump % IDX_MOD);
	new_position = move_pos(0, new_position);
	value = get_four(new_position, game);
	return (value);
}

int	ind_value_no_mod(int pos, t_carriage *car, t_game *game)
{
	int	value;
	int	jump;
	int	new_position;

	jump = get_two(pos, game);
	new_position = car->pc + jump;
	new_position = move_pos(0, new_position);
	value = get_two(new_position, game);
	return (value);
}

int	get_value(int arg_type, int pos, t_carriage *car, t_game *game)
{
	int	instr;

	if (arg_type == T_REG)
		return (reg_value(pos, car, game));
	if (arg_type == T_IND)
	{
		instr = car->cur_instr;
		if (instr == 13)
			return (ind_value_no_mod(pos, car, game));
		else
			return (ind_value(pos, car, game));
	}
	else
	{
		if (g_op_tab[car->cur_instr - 1].dir_bytes == 1)
			return (get_two(pos, game));
		else
			return (get_four(pos, game));
	}
}
