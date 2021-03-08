/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

int	init_game(int argc, t_game *game)
{
	int	i;

	game->players = 0;
	game->playerlist = (t_player**)malloc(2 * MAX_PLAYERS * sizeof(t_player));
	i = 0;
	while (i < MEM_SIZE)
	{
		game->memory[i] = 0;
		game->cols[i] = 0;
		i++;
	}
	game->last_alive = argc - 2;
	game->cycles = 0;
	game->lives = 0;
	game->cycles_to_die = CYCLE_TO_DIE;
	game->checks = 0;
	game->carriages = NULL;
	game->waiters = NULL;
	game->dump_cycle = -1;
	game->print = 0;
	game->live_print = 0;
	game->aff = 0;
	game->visual = 0;
	game->speed = 31;
	return (0);
}

int	print_usage(void)
{
	ft_putstr("Usage: ./corewar [-dump N] [[-n N] champion1.cor] ...\n");
	ft_putstr("\tmax players\t: ");
	ft_putnbr(MAX_PLAYERS);
	ft_putstr("\n\t-dump N\t\t: Dump memory after N cycles and exit\n");
	ft_putstr("\t-n N\t\t: Set the number of the next player\n");
	ft_putstr("\t-p\t\t: Show operations\n");
	ft_putstr("\t-a\t\t: Show aff output (hidden by default)\n");
	ft_putstr("\t-l\t\t: Show live executions\n");
	ft_putstr("\t-v\t\t: Visual mode\n");
	exit(0);
}

int	announce_winner(t_game *game)
{
	if (game->print)
		printf("Player %d (%s) won\n", -game->last_alive,
		game->playerlist[-(game->last_alive + 1)]->name);
	else
	{
		ft_putstr_fd("Player ", 1);
		ft_putnbr_fd(-game->last_alive, 1);
		ft_putstr_fd(" (", 1);
		ft_putstr_fd(game->playerlist[-(game->last_alive + 1)]->name, 1);
		ft_putstr_fd(") won\n", 1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	newgame;
	t_game	*game;
	int		i;

	if (argc < 2)
		return (print_usage());
	game = &newgame;
	init_game(argc, game);
	read_arguments(argv, game);
	arrange_players(game);
	i = 0;
	while (i < MAX_PLAYERS)
	{
		if (game->playerlist[i] != NULL)
			get_player(i, game->playerlist[i]->argu, game);
		i++;
	}
	first_carriages(game);
	print_players(game);
	play(game);
	return (0);
}
