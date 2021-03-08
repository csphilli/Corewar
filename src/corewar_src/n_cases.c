/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_cases.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

void		n_start_game(t_game *game)
{
	int c;

	initscr();
	timeout(1);
	n_init_colors();
	n_draw_arena(game);
	n_print_arena(game);
	refresh();
	while (1)
	{
		c = getch();
		printw("\r     \r");
		if (c == ' ')
			break ;
		if (c == 'q')
		{
			endwin();
			exit(0);
		}
	}
	printw("\r     \r");
}

int			n_slow_case(t_game *game)
{
	int c;

	n_update_game_stats(game);
	n_update_live_bar(game);
	n_update_player_stats(game);
	refresh();
	c = getch();
	n_keys(c, game);
	napms(game->speed);
	return (0);
}

int			n_fast_case(t_game *game)
{
	int c;

	n_update_game_stats(game);
	n_update_live_bar(game);
	n_update_player_stats(game);
	refresh();
	c = getch();
	n_keys(c, game);
	if (game->speed == 0)
		napms(2 + game->carrs_alive % 1000);
	if (game->speed == -10)
		napms(3);
	if (game->speed == -20)
		napms(0);
	return (0);
}

t_n_writer	n_print_box2(char *str, t_n_writer writer)
{
	if (str[writer.cur] == '\n')
	{
		printw(" / ");
		writer.len += 2;
	}
	else
		printw("%c", str[writer.cur]);
	if (str[writer.cur] == '\t')
		writer.len += 3;
	writer.len++;
	writer.cur++;
	return (writer);
}

int			print_box(t_n_coor spot, int size, int speed, char *str)
{
	t_n_writer writer;

	writer.cur = 0;
	writer.len = 0;
	writer.rows = 0;
	while (str[writer.cur] != '\0')
	{
		writer = n_print_box2(str, writer);
		if (writer.len >= size)
		{
			move(spot.row += 1, spot.col += 0);
			writer.len = 0;
			writer.rows++;
		}
		refresh();
		napms(speed);
	}
	return (writer.rows);
}
