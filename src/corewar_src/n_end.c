/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_end.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

void	n_game_over(int row, int col, int realend)
{
	int	i;

	i = 0;
	while (i < 3535)
	{
		printw(" ");
		i++;
		if (i % 101 == 0)
			move(row += 1, col += 0);
	}
	attron(A_BOLD);
	if (realend == 1)
	{
		move(row -= 31, col += 42);
		printw("G A M E   O V E R !");
	}
	else
	{
		move(row -= 31, col += 32);
		printw("Game interrupted. Current score:");
	}
	curs_set(0);
	refresh();
	napms(1200);
	attroff(A_BOLD);
}

int		n_winner(int realend, int row, int col, t_game *game)
{
	t_player	*winner;
	int			a;
	t_n_coor	spot;
	int			rows;

	spot.row = row;
	spot.col = col;
	winner = game->playerlist[-(game->last_alive + 1)];
	if (realend == 1)
		printw("WINNER: ");
	else
		printw("LEADER: ");
	refresh();
	napms(800);
	printw("Player %d, ", -(game->last_alive));
	a = 0;
	attrset(COLOR_PAIR(winner->color));
	attron(A_BOLD);
	rows = print_box(spot, 60, 20, winner->name);
	refresh();
	napms(1200);
	attroff(COLOR_PAIR(winner->color));
	attroff(A_BOLD);
	return (rows);
}

void	n_end_game(int realend, t_game *game)
{
	int			c;
	t_player	*winner;
	t_n_coor	spot;
	int			rows;

	winner = game->playerlist[-(game->last_alive + 1)];
	spot.row = 0;
	spot.col = 0;
	move(spot.row += 17, spot.col += 51);
	n_game_over(spot.row, spot.col, realend);
	move(spot.row += 7, spot.col += 3);
	rows = n_winner(realend, spot.row, spot.col, game) + 2;
	move(spot.row += rows, spot.col += 0);
	printw("\"");
	print_box(spot, 95, 50, winner->comment);
	printw("\"");
	while (1)
	{
		c = getch();
		printw("\r     \r");
		if (c == 'q')
			break ;
	}
	endwin();
	free_all_and_exit(0, game);
}
