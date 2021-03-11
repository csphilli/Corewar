/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

int		get_four(int position, t_game *game)
{
	int	value;
	int	pos2;
	int	pos3;
	int	pos4;

	pos2 = move_pos(1, position);
	pos3 = move_pos(2, position);
	pos4 = move_pos(3, position);
	value = (game->memory[position] << 24) |
	(game->memory[pos2]) << 16 |
	(game->memory[pos3] << 8) |
	(game->memory[pos4]);
	return (value);
}

int		get_two(int position, t_game *game)
{
	unsigned int			value1;
	unsigned int			value2;
	unsigned int			value;
	int						shorty;
	int						pos2;

	pos2 = move_pos(1, position);
	value1 = game->memory[position];
	value2 = game->memory[pos2];
	value = value1 << 8 | value2;
	shorty = (short)value;
	return (shorty);
}

int		move_pos(int steps, int pos)
{
	pos += steps;
	if (pos >= MEM_SIZE)
		pos %= MEM_SIZE;
	while (pos < 0)
		pos += MEM_SIZE;
	return (pos);
}

void	write_to_memory(int value, int pos, t_carriage *car, t_game *game)
{
	unsigned char			res;
	int						i;

	i = 24;
	pos = move_pos(0, pos);
	while (i >= 0)
	{
		res = value >> i;
		game->memory[pos] = res;
		if (game->visual)
			highlight(pos, car, game);
		pos = move_pos(1, pos);
		i -= 8;
	}
}

int		arg_len(int arg_type, int dir_size)
{
	if (arg_type == T_REG)
		return (1);
	if (arg_type == T_IND)
		return (2);
	if (arg_type == T_DIR)
	{
		if (dir_size == 0 || dir_size == 4)
			return (4);
		else
			return (2);
	}
	return (0);
}
