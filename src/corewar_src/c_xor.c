/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_xor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2021/03/02 12:40:00 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

int	xor(t_arguments args, t_carriage *carriage, t_game *game)
{
	int	value1;
	int	value2;
	int	res;
	int	reg;
	int	pos;

	pos = move_pos(2, carriage->position);
	value1 = get_value(args.arg[0], pos, carriage, game);
	pos = move_pos(arg_len(args.arg[0], 4), pos);
	value2 = get_value(args.arg[1], pos, carriage, game);
	pos = move_pos(arg_len(args.arg[1], 4), pos);
	reg = game->memory[pos] - 1;
	res = value1 ^ value2;
	carriage->regs[reg] = res;
	carriage->carry = 0;
	if (res == 0)
		carriage->carry = 1;
	if (game->print)
		ft_printf("P %4d | xor %d %d r%d\n",
		carriage->nr, value1, value2, reg + 1);
	return (0);
}
