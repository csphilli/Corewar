/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

/*
**	-either set the witing time of a valid new instruction, or move one step
**	-if live instruction, a special carriage color is set in visual
**	for the next 50 cycles
*/

void	read_new_instruction(t_carriage *carriage, t_game *game)
{
	int		instruction;

	instruction = game->memory[carriage->pc];
	if (instruction >= 1 && instruction <= 16)
	{
		carriage->cur_instr = instruction;
		carriage->wait = g_op_tab[instruction - 1].dur;
	}
	else
	{
		if (game->visual)
			normal(0, carriage->pc, game);
		carriage->cur_instr = -1;
		carriage->pc = move_pos(1, carriage->pc);
	}
	if (game->visual)
	{
		if (instruction == 1)
			live_col(carriage->pc, game);
		else
			car_col(carriage->pc, game);
	}
}

/*
**	-check if the code following the instructions is valid
**	-if so, execute
**	-in any case get the correct length step to the next position
*/

int		handle_instruction(t_carriage *carr, t_game *game)
{
	if (game->visual)
		normal(0, carr->pc, game);
	check_and_execute_args(carr->cur_instr, carr, carr->pc, game);
	carr->pc = move_pos(carr->to_next, carr->pc);
	carr->cur_instr = -1;
	return (0);
}

/*
**	each carriage can
**	-	read a new instruction that jumped to on last round,
**		and set the wait cycles according to it
**	-	reduce the wait
**	-	if time, check rest of the instructions code and execute it if valid,
**		otherwise jump over it to the next instruction candidate
*/

int		cycle(t_game *game)
{
	t_carriage	*carriage;

	carriage = game->carriages;
	if (carriage == NULL)
		return (0);
	if (game->visual)
		check_waiters(game);
	while (carriage)
	{
		if (carriage->wait == 0)
			read_new_instruction(carriage, game);
		if (carriage->wait > 0)
			carriage->wait--;
		if (carriage->wait == 0 && carriage->cur_instr != -1)
			handle_instruction(carriage, game);
		if (game->visual && game->speed > 0)
			n_slow_case(game);
		carriage = carriage->next;
	}
	if (game->visual && game->speed <= 0)
		n_fast_case(game);
	return (1);
}

/*
**	-this loop keeps the game going as long as there are carriages left
**	-game cycles are interrupted every cycles_to_die to perform a check
**		to remove carriages that didn't perform live statements, and remove
**		all of them if cycles_to_die have gone down to zero or less
**	-when no more carriages, the last player said to be alive is the winner
*/

int		play(t_game *game)
{
	if (game->visual)
		n_start_game(game);
	game->cur_cycles = 0;
	while (cycle(game) == 1)
	{
		game->cycles++;
		if (game->cycles == 2147483647)
			end_too_large(game);
		game->cur_cycles++;
		if (game->cur_cycles >= game->cycles_to_die)
		{
			check(game);
			game->cur_cycles = 0;
		}
		if (game->cycles == game->dump_cycle)
			dump_game_and_exit(game);
	}
	if (game->visual)
		n_end_game(1, game);
	announce_winner(game);
	return (0);
}
