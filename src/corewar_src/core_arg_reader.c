/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_arg_reader.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

int	arg_error(int error, t_game *game)
{
	if (error == 1)
		ft_putstr_fd("-dump N too large\n", 2);
	else if (error == 2)
		ft_putstr_fd("Error: -dump N not a valid number\n", 2);
	else if (error == 3)
		ft_putstr_fd("Error: -n flag missing player or valid number\n", 2);
	else if (error == 4)
		ft_putstr_fd("Error: player number taken\n", 2);
	else if (error == 5)
		ft_putstr_fd("\nError: -dump has no number\n", 2);
	else if (error == 6)
	{
		ft_putstr_fd("Error: max ", 2);
		ft_putnbr_fd(MAX_PLAYERS, 2);
		ft_putstr_fd(" players\n", 2);
	}
	else if (error == 7)
		ft_putstr_fd("Error: -dump, -p, -a flags not in use with -v\n", 2);
	else if (error == 8)
		ft_putstr_fd("Error: battle values getting too large\n", 2);
	else if (error == 9)
		ft_putstr_fd("Error: -v in use with max 4 players\n", 2);
	else if (error == 10)
		ft_putstr_fd("Error: no players found\n", 2);
	return (free_all_and_exit(1, game));
}

int	check_n_flag_player(char **argv, int i, t_game *game)
{
	int		player_n;

	if (argv[i + 1] == NULL || argv[i + 1][1] != '\0' || argv[i + 2] == NULL ||
	(!(ft_isdigit(argv[i + 1][0]))) || ft_atoi(argv[i + 1]) > MAX_PLAYERS ||
	ft_atoi(argv[i + 1]) == 0)
		return (arg_error(3, game));
	player_n = ft_atoi(argv[i + 1]);
	if (game->playerlist[player_n - 1] != NULL)
		return (arg_error(4, game));
	game->playerlist[player_n - 1] = (t_player*)malloc(sizeof(t_player));
	game->playerlist[player_n - 1]->argu = argv[i + 2];
	game->players++;
	if (game->players > MAX_PLAYERS)
		return (arg_error(6, game));
	return (3);
}

int	check_regular_player(char **argv, int i, t_game *game)
{
	int	a;

	a = MAX_PLAYERS;
	while (a < MAX_PLAYERS * 2 && game->playerlist[a] != NULL)
		a++;
	game->playerlist[a] = (t_player*)malloc(sizeof(t_player));
	game->playerlist[a]->argu = argv[i];
	game->players++;
	if (game->players > MAX_PLAYERS)
		return (arg_error(6, game));
	return (1);
}

/*
**	-collect and validate flags
**	-n-flag players with chosen position are put their places on playerlist
**	-other players are put on the end side of the list to wait for placing
*/

int	read_arguments(char **argv, t_game *game)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (ft_strcmp(argv[i], "-dump") == 0)
			i += (get_dump_flag(argv[i + 1], game));
		else if (ft_strcmp(argv[i], "-p") == 0)
			i = get_print_flag(i, game);
		else if (ft_strcmp(argv[i], "-v") == 0)
			i = get_visual_flag(i, game);
		else if (ft_strcmp(argv[i], "-a") == 0)
			i = get_aff_flag(i, game);
		else if (ft_strcmp(argv[i], "-l") == 0)
			i = get_no_live_print_flag(i, game);
		else if (ft_strcmp(argv[i], "-n") == 0)
			i += (check_n_flag_player(argv, i, game));
		else
			i += (check_regular_player(argv, i, game));
	}
	if (game->players > 4 && game->visual)
		return (arg_error(9, game));
	if (game->players == 0)
		return (arg_error(10, game));
	return (0);
}
