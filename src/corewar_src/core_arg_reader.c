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

int	arg_error(int error)
{
	if (error == 1)
		ft_putstr("-dump N too large\n");
	else if (error == 2)
		ft_putstr("Error: -dump N not a valid number\n");
	else if (error == 3)
		ft_putstr("Error: -n flag\n");
	else if (error == 4)
		ft_putstr("Error: player number taken\n");
	else if (error == 5)
		ft_putstr("\nError: -dump has no number\n");
	else if (error == 6)
	{
		ft_putstr("Error: max ");
		ft_putnbr(MAX_PLAYERS);
		ft_putstr(" players\n");
	}
	else if (error == 7)
		ft_putstr("Error: -dump and -p flags not to be used with -v\n");
	system("leaks corewar");
	exit(0);
}

int	get_dump(char *arg, t_game *game)
{
	int		i;

	if (game->visual == 1)
		return (arg_error(7));
	i = 0;
	if (arg == NULL)
		return (arg_error(5));
	while (arg[i])
	{
		if (i == 9)
			return (arg_error(1));
		if (!(ft_isdigit(arg[i])))
			return (arg_error(2));
		i++;
	}
	game->dump_cycle = ft_atoi(arg);
	return (2);
}

int	check_n_flag_player(char **argv, int i, t_game *game)
{
	int		player_n;

	if (argv[i + 1] == NULL || argv[i + 1][1] != '\0' ||
	(!(ft_isdigit(argv[i + 1][0]))) || ft_atoi(argv[i + 1]) > MAX_PLAYERS ||
	ft_atoi(argv[i + 1]) == 0)
		return (arg_error(3));
	player_n = ft_atoi(argv[i + 1]);
	if (game->playerlist[player_n - 1] != NULL)
		return (arg_error(4));
	game->playerlist[player_n - 1] = (t_player*)malloc(sizeof(t_player));
	game->playerlist[player_n - 1]->argu = argv[i + 2];
	game->players++;
	if (game->players > MAX_PLAYERS)
		return (arg_error(6));
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
		return (arg_error(6));
	return (1);
}

int	read_arguments(char **argv, t_game *game)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (ft_strcmp(argv[i], "-dump") == 0)
			i += (get_dump(argv[i + 1], game));
		else if (ft_strcmp(argv[i], "-p") == 0)
		{
			game->print = 1;
			i++;
		}
		else if (ft_strcmp(argv[i], "-v") == 0)
		{
			game->visual = 1;
			i++;
		}
		else if (ft_strcmp(argv[i], "-n") == 0)
			i += (check_n_flag_player(argv, i, game));
		else
			i += (check_regular_player(argv, i, game));
		if ((game->print == 1 || game->dump_cycle != -1) && game->visual)
			return (arg_error(7));
	}
	return (0);
}
