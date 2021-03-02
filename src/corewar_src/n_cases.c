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

void	n_start_game(t_game *game)
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

int		n_slow_case(t_game *game)
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

int		n_fast_case(t_game *game)
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
