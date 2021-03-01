/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_color.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

void	n_init_color_pairs(void)
{
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, COLOR_YELLOW);
	init_pair(6, COLOR_BLACK, COLOR_GREEN);
	init_pair(7, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(8, COLOR_BLACK, COLOR_BLUE);
	init_pair(9, COLOR_YELLOW, COLOR_BLACK);
	init_pair(10, COLOR_GREEN, COLOR_BLACK);
	init_pair(11, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(12, COLOR_BLUE, COLOR_BLACK);
	init_pair(13, COLOR_WHITE, COLOR_YELLOW);
	init_pair(14, COLOR_WHITE, COLOR_GREEN);
	init_pair(15, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(16, COLOR_WHITE, COLOR_BLUE);
	init_pair(17, COLOR_CYAN, COLOR_BLACK);
	init_pair(18, COLOR_CYAN, COLOR_CYAN);
	init_pair(19, COLOR_BLACK, COLOR_CYAN);
	init_pair(21, COLOR_RED, COLOR_CYAN);
	init_pair(22, COLOR_RED, COLOR_BLACK);
}

void	n_init_colors(t_game *game)
{
	if (has_colors())
	{
		if (start_color() == OK)
		{
			init_color(COLOR_GREEN, 100, 266, 139);
			init_color(COLOR_MAGENTA, 300, 0, 430);
			init_color(COLOR_YELLOW, 645, 650, 0);
			init_color(COLOR_CYAN, 150, 150, 150);
			init_color(COLOR_WHITE, 600, 600, 600);
			n_init_color_pairs();
		}
		else
		{
			addstr("Cannot start colours\n");
			game->visual = 0;
			refresh();
		}
	}
	else
	{
		addstr("Not colour capable\n");
		game->visual = 0;
		refresh();
	}
}

int		set_color2(int i)
{
	if (i == -1)
		return (9);
	if (i == -2)
		return (10);
	if (i == -3)
		return (11);
	if (i == -4)
		return (12);
	if (i == 100)
		return (13);
	if (i == 200)
		return (14);
	if (i == 300)
		return (15);
	if (i == 400)
		return (16);
	if (i == 1000)
		return (19);
	return (0);
}

int		set_color(int i)
{
	if (i == 0)
		return (17);
	if (i == 1)
		return (1);
	if (i == 2)
		return (2);
	if (i == 3)
		return (3);
	if (i == 4)
		return (4);
	if (i == 10)
		return (5);
	if (i == 20)
		return (6);
	if (i == 30)
		return (7);
	if (i == 40)
		return (8);
	return (set_color2(i));
}
