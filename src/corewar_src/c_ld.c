/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_ld.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

/*
**	-	get a value form reg or ind (arg2)
**	-	put to a registry (arg1)
**	-	modify carry
*/

int	ld(t_arguments args, t_carriage *carriage, t_game *game)
{
	int	value;
	int	dest_reg;
	int	pos;

	pos = move_pos(2, carriage->position);
	value = get_value(args.arg[0], pos, carriage, game);
	pos = move_pos(arg_len(args.arg[0], 4), pos);
	dest_reg = game->memory[pos];
	carriage->regs[dest_reg - 1] = value;
	carriage->carry = 0;
	if (value == 0)
		carriage->carry = 1;
	if (game->print)
		printf("P %4d | ld %d r%d\n", carriage->nr, value, dest_reg);
	return (0);
}
