/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_aff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

/*
**	-opcode 16
**	-in use with -a flag
**	-displays (char)(the argument registrys content % 256)
*/

int		aff(t_carriage *carriage, t_game *game)
{
	int		pos;
	int		reg;
	int		value;
	char	result;

	pos = move_pos(2, carriage->pc);
	reg = game->memory[pos] - 1;
	value = carriage->regs[reg];
	value = value % 256;
	result = (char)(value);
	if (game->aff)
		ft_printf("Aff: %c\n", result);
	return (0);
}
