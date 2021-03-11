/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_code_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

int	bin2(int i)
{
	int	bins[16];

	bins[0] = 0;
	bins[1] = 1;
	bins[2] = 2;
	bins[3] = 3;
	bins[4] = 0;
	bins[5] = 1;
	bins[6] = 2;
	bins[7] = 3;
	bins[8] = 0;
	bins[9] = 1;
	bins[10] = 2;
	bins[11] = 3;
	bins[12] = 0;
	bins[13] = 1;
	bins[14] = 2;
	bins[15] = 3;
	return (bins[i]);
}

int	bin1(int i)
{
	int	bins[16];

	bins[0] = 0;
	bins[1] = 0;
	bins[2] = 0;
	bins[3] = 0;
	bins[4] = 1;
	bins[5] = 1;
	bins[6] = 1;
	bins[7] = 1;
	bins[8] = 2;
	bins[9] = 2;
	bins[10] = 2;
	bins[11] = 2;
	bins[12] = 3;
	bins[13] = 3;
	bins[14] = 3;
	bins[15] = 3;
	return (bins[i]);
}

int	wrong_arg_type(int instruction, int index, int argument)
{
	int	a;

	a = 0;
	while (a < 3)
	{
		if (g_op_tab[instruction].argtypes[index][a] == argument)
			return (0);
		a++;
	}
	return (1);
}

int	is_valid_args(int code, t_arguments args, t_carriage *car, t_game *game)
{
	int	valid_code;
	int	i;
	int	jump;
	int	pos;

	pos = move_pos(1 + g_op_tab[code - 1].acb, car->pc);
	valid_code = 1;
	car->to_next = 1 + g_op_tab[code - 1].acb;
	i = 0;
	while (i < g_op_tab[code - 1].args)
	{
		if (args.arg[i] == 1 && (!(game->memory[pos] >= 1
		&& game->memory[pos] <= 16)))
			valid_code = 0;
		jump = arg_len(args.arg[i], g_op_tab[code - 1].dir_bytes);
		pos = move_pos(jump, pos);
		car->to_next += jump;
		if (wrong_arg_type(code - 1, i, args.arg[i]) == 1)
			valid_code = 0;
		i++;
	}
	return (valid_code);
}

int	check_and_execute_args(int code, t_carriage *car, int pos, t_game *game)
{
	int			bytecode;
	int			next_pos;
	t_arguments	args;

	if (g_op_tab[code - 1].acb == 1)
	{
		next_pos = move_pos(1, pos);
		bytecode = game->memory[next_pos];
		args.arg[0] = bin1((int)(bytecode / 16));
		args.arg[1] = bin2((int)(bytecode / 16));
		args.arg[2] = bin1((int)(bytecode % 16));
	}
	else
	{
		args.arg[0] = 2;
		args.arg[1] = 0;
		args.arg[2] = 0;
	}
	if (is_valid_args(code, args, car, game) == 1)
		execute_code(code, args, car, game);
	return (0);
}
