/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_arena.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

int		n_print_player_name(int row, int col, t_player *player)
{
	int	a;
	int	rows;

	rows = 1;
	a = 0;
	attrset(COLOR_PAIR(player->color));
	while (player->name[a] != '\0')
	{
		printw("%c", player->name[a]);
		a++;
		if (a % 33 == 0)
		{
			move(row += 1, col += 0);
			rows++;
		}
	}
	attroff(COLOR_PAIR(player->color));
	return (rows);
}

void	n_print_players(t_game *game)
{
	int			row;
	int			col;
	int			i;
	t_player	*player;
	int			rows;

	row = 0;
	col = 0;
	move(row += 30, col += 204);
	i = 0;
	while (i < game->players)
	{
		player = game->playerlist[i];
		printw("____PLAYER %d_____________________", i + 1);
		move(row += 1, col += 0);
		rows = n_print_player_name(row, col, player);
		move(row += rows, col += 0);
		game->coor[i] = row;
		printw("Lives:               ");
		move(row += 1, col += 0);
		printw("Last live:           ");
		i++;
		move(row += 4, col += 0);
	}
	n_update_player_stats(game);
}

void	n_print_arena(t_game *game)
{
	int row;
	int col;

	row = 0;
	col = 0;
	move(row += 10, col += 206);
	printw("CYCLE:");
	move(row += 1, col += 0);
	printw("PROCESSES:");
	move(row += 1, col += 0);
	printw("CYCLE_TO_DIE:");
	move(row += 1, col += 0);
	printw("CYCLE_DELTA:");
	move(row += 1, col += 0);
	printw("NBR_LIVE:");
	move(row += 1, col += 0);
	printw("MAX_CHECKS:");
	move(row += 5, col += 0);
	n_update_game_stats(game);
	n_update_live_bar(game);
	n_update_speed_bar(21, 210, game);
	n_print_players(game);
	refresh();
}

void	print_car(int position, t_game *game)
{
	int	row;
	int	col;
	int	color;

	row = 3;
	col = 6;
	move(row += position / 64, col += position % 64 * 3);
	color = set_color(game->cols[position]);
	attrset(COLOR_PAIR(color));
	if (color > 8 && color != 17 && color != 19)
		attron(A_BOLD);
	printw("%02x", game->memory[position]);
	attroff(COLOR_PAIR(color));
	if (color > 8 && color != 17 && color != 19)
		attroff(A_BOLD);
}

void	n_draw_arena(t_game *game)
{
	int row;
	int col;
	int color;
	int i;

	row = 0;
	col = 0;
	i = 0;
	move(row += 3, col += 6);
	while (i < MEM_SIZE)
	{
		color = game->cols[i];
		if (color == 0)
			color = 17;
		attrset(COLOR_PAIR(color));
		printw("%02x", game->memory[i]);
		attroff(COLOR_PAIR(color));
		i++;
		if (i % 64 == 0)
			move(row += 1, col = 6);
		else
			move(row += 0, col += 3);
	}
	move(row += 1, col += 0);
	printw("            [space] START/PAUSE      [q] QUIT     [a/d] SPEED");
}
