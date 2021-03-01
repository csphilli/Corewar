/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_print_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

void	n_update_game_stats(t_game *game)
{
	int	row;
	int	col;
	int	until_check;

	row = 0;
	col = 0;
	until_check = game->cycles_to_die - game->cur_cycles;
	move(row += 10, col += 223);
	printw("%12d\n", game->cycles);
	move(row += 1, col += 0);
	printw("%12d\n", game->carrs_alive);
	move(row += 1, col += 0);
	printw("%4d", game->cycles_to_die);
	if (until_check < 100)
		attrset(COLOR_PAIR(22) | A_BOLD);
	printw("    %4d", until_check);
	if (until_check < 100)
		attroff(COLOR_PAIR(22) | A_BOLD);
	move(row += 1, col += 0);
	printw("%4d\n", CYCLE_DELTA);
	move(row += 1, col += 0);
	printw("%4d", NBR_LIVE);
	move(row += 1, col += 0);
	printw("%4d", MAX_CHECKS);
	printw("    %4d", game->checks);
}

void	n_update_player_stats(t_game *game)
{
	int			row;
	int			col;
	int			i;
	t_player	*player;

	i = 0;
	while (i < game->players)
	{
		player = game->playerlist[i];
		row = 0;
		col = 0;
		attrset(COLOR_PAIR(player->color));
		attron(A_BOLD);
		move(row += game->coor[i], col += 225);
		printw("%12d", player->lives);
		attroff(A_BOLD);
		attroff(COLOR_PAIR(player->color));
		move(row += 1, col += 0);
		printw("%12d", player->last_live);
		i++;
	}
	move(row -= row, col -= col);
	move(row += 70, col += 4);
	curs_set(0);
}

void	n_update_speed_bar(int row, int col, t_game *game)
{
	move(row += 2, col += 0);
	attrset(COLOR_PAIR(19));
	printw(" 1 2 3 4 5 6 7 TURBO ");
	attroff(COLOR_PAIR(19));
	move(row += 0, col += 0);
	attrset(COLOR_PAIR(21) | A_BOLD);
	if (game->speed == 41)
		printw(" 1");
	if (game->speed == 31)
		printw("   2");
	if (game->speed == 21)
		printw("     3");
	if (game->speed == 11)
		printw("       4");
	if (game->speed == 1)
		printw("         5");
	if (game->speed == 0)
		printw("           6");
	if (game->speed == -10)
		printw("             7");
	if (game->speed == -20)
		printw("               TURBO");
	attroff(COLOR_PAIR(21) | A_BOLD);
	move(row += 2, col += 0);
	printw("speed");
}

void	n_update_live_bar(t_game *game)
{
	int	row;
	int	col;
	int	i;

	row = 0;
	col = 0;
	i = 0;
	move(row += 19, col += 210);
	if (game->lives == 0)
	{
		attrset(COLOR_PAIR(18));
		printw(".....................");
		attroff(COLOR_PAIR(18));
	}
	attrset(COLOR_PAIR(17) | A_BOLD);
	i = 0;
	while (i < game->lives && i < NBR_LIVE)
	{
		printw("|");
		i++;
	}
	attroff(COLOR_PAIR(17) | A_BOLD);
	move(row += 2, col += 0);
	printw("live");
}
