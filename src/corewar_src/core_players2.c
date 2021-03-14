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

int	check_size(char *arg, int code_length, t_player *player, t_game *game)
{
	if (code_length != player->size)
		return (player_error(arg, 5, game));
	if (player->size > CHAMP_MAX_SIZE)
		return (player_error(arg, 7, game));
	return (0);
}

int	player_error(char *arg, int error, t_game *game)
{
	if (error == 0)
	{
		ft_putstr_fd("Error: can't read player \"", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("\"\n", 2);
	}
	else
	{
		ft_putstr_fd("Error: File ", 2);
		ft_putstr_fd(arg, 2);
		if (error == 1)
			ft_putstr_fd(" has an invalid header\n", 2);
		else if (error == 2)
			ft_putstr_fd(": name is too long\n", 2);
		else if (error == 3)
			ft_putstr_fd(": comment is too long\n", 2);
		else if (error == 4)
			ft_putstr_fd(" is too small to be a champion\n", 2);
		else if (error == 5)
			ft_putstr_fd(": code size different from what header says\n", 2);
		else if (error == 7)
			ft_printf(" has too large code\n");
	}
	return (free_all_and_exit(game));
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

/*
**	move all players towards first position so that no empty spots are
**	left between first and last player
*/

int	compress_playerlist(t_game *game)
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

/*
**	move players with no chosen place to empty positions on playerlist
*/

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
	compress_playerlist(game);
	return (0);
}
