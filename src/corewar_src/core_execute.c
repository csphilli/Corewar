/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

int	execute_2(int code, t_arguments args, t_carriage *carriage, t_game *game)
{
	if (code == 11)
		sti(args, carriage, game);
	if (code == 12)
		c_fork(carriage, game);
	if (code == 13)
		lld(args, carriage, game);
	if (code == 14)
		lldi(args, carriage, game);
	if (code == 15)
		c_lfork(carriage, game);
	if (code == 16)
		aff(carriage, game);
	return (0);
}

int	execute_code(int code, t_arguments args, t_carriage *carriage, t_game *game)
{
	if (code == 1)
		live(carriage, game);
	else if (code == 2)
		ld(args, carriage, game);
	else if (code == 3)
		st(args, carriage, game);
	else if (code == 4)
		add(carriage, game);
	else if (code == 5)
		sub(carriage, game);
	else if (code == 6)
		and(args, carriage, game);
	else if (code == 7)
		or(args, carriage, game);
	else if (code == 8)
		xor(args, carriage, game);
	else if (code == 9)
		zjmp(carriage, game);
	else if (code == 10)
		ldi(args, carriage, game);
	else
		execute_2(code, args, carriage, game);
	return (0);
}
