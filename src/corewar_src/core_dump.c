/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_dump.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

void	dump_game_and_exit(t_game *game)
{
	int		i;
	int		a;

	i = 0;
	while (i < MEM_SIZE)
	{
		a = 0;
		while (a < 32)
		{
			ft_printf("%02x ", game->memory[i]);
			a++;
			i++;
		}
		ft_printf("\n");
	}
	free_all_and_exit(game);
}

void	free_players(t_game *game)
{
	int	i;
	int	max;

	max = MAX_PLAYERS * 2;
	i = 0;
	while (i < max)
	{
		free(game->playerlist[i]);
		game->playerlist[i] = NULL;
		i++;
	}
}

int		free_all_and_exit(t_game *game)
{
	t_carriage	*car;
	t_carriage	*tmp_car;
	t_waiter	*wait;
	t_waiter	*tmp_wait;

	car = game->carriages;
	while (car)
	{
		tmp_car = car->next;
		free(car);
		car = NULL;
		car = tmp_car;
	}
	wait = game->waiters;
	while (wait)
	{
		tmp_wait = wait->next;
		free(wait);
		wait = NULL;
		wait = tmp_wait;
	}
	free_players(game);
	exit(0);
}
