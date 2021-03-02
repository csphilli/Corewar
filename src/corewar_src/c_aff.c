/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_aff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2021/03/02 12:40:00 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

int		aff(t_carriage *carriage, t_game *game)
{
	int	pos;
	int	reg;
	int	value;

	pos = move_pos(2, carriage->position);
	reg = game->memory[pos] - 1;
	value = carriage->regs[reg];
	value %= 256;
	ft_printf("P %4d | aff %d\n", carriage->nr, value);
	return (0);
}
