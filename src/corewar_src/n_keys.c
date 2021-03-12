/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_keys.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

void	n_change_speed(char c, t_game *game)
{
	printw("\r       \r");
	if (c == 'a' && game->speed < 40)
	{
		if (game->speed == 0)
			game->speed = 1;
		else
			game->speed += 10;
	}
	else if (c == 'd' && game->speed > -20)
	{
		if (game->speed == 1)
			game->speed = 0;
		else
			game->speed -= 10;
	}
	printw("\r       \r");
	n_update_speed_bar(21, 210, game);
}

int		n_pause(t_game *game)
{
	int c;

	while (1)
	{
		c = getch();
		if (c == ' ')
		{
			printw("\r                                \r");
			break ;
		}
		else if (c == 'q')
		{
			printw("\r                                \r");
			n_end_game(0, game);
		}
		if (c == 'a' || c == 'd')
		{
			printw("\r                                \r");
			n_change_speed(c, game);
			n_print_arena(game);
		}
		printw("\r                  PAUSED\r");
	}
	return (0);
}

int		n_keys(int c, t_game *game)
{
	printw(" ");
	if (c == 'q')
	{
		endwin();
		return (free_all_and_exit(game));
	}
	else if (c == ' ')
		return (n_pause(game));
	else
		n_change_speed(c, game);
	return (0);
}
