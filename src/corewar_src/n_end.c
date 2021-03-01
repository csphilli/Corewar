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

void	n_game_over(int row, int col)
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
	move(row -= 31, col += 42);
	attron(A_BOLD);
	printw("G A M E   O V E R !");
	curs_set(0);
	refresh();
	napms(1200);
	attroff(A_BOLD);
}

void	n_winner(int row, int col, t_game *game)
{
	t_player	*winner;
	int			a;

	winner = game->playerlist[-(game->last_alive + 1)];
	printw("WINNER: ");
	refresh();
	napms(800);
	printw("Player %d, ", -(game->last_alive));
	a = 0;
	attrset(COLOR_PAIR(winner->color));
	attron(A_BOLD);
	while (winner->name[a] != '\0')
	{
		printw("%c", winner->name[a]);
		a++;
		refresh();
		napms(50);
		if (a % 60 == 0)
			move(row += 1, col += 0);
	}
	attroff(COLOR_PAIR(winner->color));
	attroff(A_BOLD);
}

void	n_winner_message(int row, int col, t_player *winner)
{
	int	a;
	int	chars;

	a = 0;
	chars = 1;
	while (winner->comment[a] != '\0')
	{
		if (winner->comment[a] == '\n')
		{
			printw(" / ");
			chars += 2;
		}
		else
			printw("%c", winner->comment[a]);
		chars++;
		if (chars % 95 == 0)
		{
			move(row += 1, col += 0);
			chars = 0;
		}
		a++;
		refresh();
		napms(50);
	}
}

void	n_end_game(t_game *game)
{
	int			row;
	int			col;
	int			c;
	t_player	*winner;

	winner = game->playerlist[-(game->last_alive + 1)];
	row = 0;
	col = 0;
	move(row += 17, col += 51);
	n_game_over(row, col);
	move(row += 7, col += 3);
	n_winner(row, col, game);
	move(row += 4, col -= col);
	move(row += 0, col += 54);
	printw("\"");
	n_winner_message(row, col, winner);
	printw("\"");
	while (1)
	{
		c = getch();
		printw("\r     \r");
		if (c == 'q')
			break ;
	}
}
