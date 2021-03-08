/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_carriage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

void	fill_registries(int i, t_carriage *carr)
{
	int		a;

	carr->regs[0] = -i;
	a = 1;
	while (a < REG_NUMBER)
	{
		carr->regs[a] = 0;
		a++;
	}
}

int		first_carriages(t_game *game)
{
	int			i;
	t_carriage	*newcarriage;
	t_carriage	*temp;

	i = 1;
	while (i <= game->players)
	{
		newcarriage = (t_carriage*)malloc(sizeof(t_carriage));
		newcarriage->nr = i;
		newcarriage->carry = 0;
		newcarriage->cur_instr = 0;
		newcarriage->last_live_cycle = game->cycles;
		newcarriage->wait = 0;
		newcarriage->pc = game->playerlist[i - 1]->start;
		newcarriage->to_next = 0;
		fill_registries(i, newcarriage);
		newcarriage->col = i * 10;
		temp = game->carriages;
		game->carriages = newcarriage;
		newcarriage->next = temp;
		i++;
	}
	game->carr_count = game->players;
	game->carrs_alive = game->carr_count;
	return (0);
}

int		check_limit(t_game *game)
{
	if (game->carr_count == 2147483647)
		end_too_large(game);
	return (0);
}

int		add_child_carriage(int position, t_carriage *old_car, t_game *game)
{
	int			a;
	t_carriage	*newcarriage;
	t_carriage	*temp;

	newcarriage = (t_carriage*)malloc(sizeof(t_carriage));
	newcarriage->nr = game->carr_count + 1;
	newcarriage->carry = old_car->carry;
	newcarriage->last_live_cycle = old_car->last_live_cycle;
	newcarriage->wait = 0;
	newcarriage->pc = position;
	newcarriage->col = old_car->col;
	newcarriage->to_next = 0;
	a = 0;
	while (a < REG_NUMBER)
	{
		newcarriage->regs[a] = old_car->regs[a];
		a++;
	}
	temp = game->carriages;
	game->carriages = newcarriage;
	newcarriage->next = temp;
	game->carr_count++;
	game->carrs_alive++;
	check_limit(game);
	return (0);
}
