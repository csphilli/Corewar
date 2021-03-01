/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_players2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

int	player_error(char *arg, int error)
{
	if (error == 0)
	{
		ft_putstr("Error: can't read player \"");
		ft_putstr(arg);
		ft_putstr("\"\n");
	}
	else
	{
		ft_putstr("Error: File ");
		ft_putstr(arg);
		if (error == 1)
			ft_putstr(" has an invalid header\n");
		else if (error == 2)
			ft_putstr(": name is too long");
		else if (error == 3)
			ft_putstr(": comment is too long");
	}
	system("leaks corewar");
	exit(0);
}

int	print_players(t_game *game)
{
	t_player	*player;
	int			i;

	ft_putendl_fd("Introducing contestants...", 1);
	i = 0;
	while (i < game->players)
	{
		player = game->playerlist[i];
		ft_putstr_fd("* Player ", 1);
		ft_putnbr_fd(i + 1, 1);
		ft_putstr_fd(", weighing ", 1);
		ft_putnbr_fd(player->size, 1);
		ft_putstr_fd(" bytes, \"", 1);
		ft_putstr_fd(player->name, 1);
		ft_putstr_fd("", 1);
		ft_putstr_fd("\" (\"", 1);
		ft_putstr_fd(player->comment, 1);
		ft_putendl_fd("\") !", 1);
		i++;
	}
	return (0);
}

int	replace_regular_players(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		if (game->playerlist[i] == NULL)
		{
			j = i;
			while (game->playerlist[j] == NULL && j <= MAX_PLAYERS)
			{
				j++;
				if (j == MAX_PLAYERS)
					return (0);
			}
			game->playerlist[i] = game->playerlist[j];
			game->playerlist[j] = NULL;
		}
		i++;
	}
	return (0);
}

int	arrange_players(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = MAX_PLAYERS;
	while (i < MAX_PLAYERS * 2 && game->playerlist[j] != NULL)
	{
		if (game->playerlist[i] == NULL)
		{
			game->playerlist[i] = game->playerlist[j];
			game->playerlist[j] = NULL;
			j++;
		}
		i++;
	}
	replace_regular_players(game);
	return (0);
}
