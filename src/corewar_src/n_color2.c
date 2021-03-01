/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_color2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

int		normal(int done, int pos, t_game *game)
{
	int cur;

	cur = game->cols[pos];
	if (cur == 1000)
	{
		game->cols[pos] = 0;
		print_car(pos, game);
		return (0);
	}
	if (done == 0 && cur > 99)
		return (0);
	if (cur == 0)
		return (0);
	while (cur >= 10)
		cur /= 10;
	if (cur < 0)
		cur = -cur;
	game->cols[pos] = cur;
	print_car(pos, game);
	return (0);
}

int		live_col(int pos, t_game *game)
{
	int cur;

	cur = game->cols[pos];
	if (cur > 99 || cur < 0)
		delete_wait(pos, game);
	if (cur < 0)
		cur = -cur;
	while (cur < 100)
		cur *= 10;
	game->cols[pos] = cur;
	add_waiter(pos, game);
	print_car(pos, game);
	return (0);
}

int		car_col(int pos, t_game *game)
{
	int cur;

	cur = game->cols[pos];
	if (cur > 99)
		return (0);
	if (cur >= 10)
		return (0);
	if (cur == 0)
	{
		game->cols[pos] = 1000;
		print_car(pos, game);
		return (0);
	}
	if (cur > 0)
		cur *= 10;
	else
	{
		delete_wait(pos, game);
		cur = -cur;
		cur *= 10;
	}
	game->cols[pos] = cur;
	print_car(pos, game);
	return (0);
}

int		highlight(int pos, t_carriage *carriage, t_game *game)
{
	int	cur;

	cur = game->cols[pos];
	if (cur > 99 && cur < 1000)
		return (0);
	else
	{
		delete_wait(pos, game);
		cur = -(carriage->col / 10);
	}
	game->cols[pos] = cur;
	add_waiter(pos, game);
	print_car(pos, game);
	return (0);
}
