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
	game->live_print = 1;
	game->aff = 0;
	game->visual = 0;
	game->speed = 31;
	return (0);
}

int	print_usage(void)
{
	ft_putstr("\nUsage: ./corewar [champion.cor]\n\n");
	ft_putstr("\tmax players\t: ");
	ft_putnbr(MAX_PLAYERS);
	ft_putstr("\n\n\tflags:\n\t");
	ft_putstr("-dump [number]\t: Dump memory after number cycles and exit\n");
	ft_putstr("\t-n [number]\t: Set the number of the next player\n");
	ft_putstr("\t-p\t\t: Show operations\n");
	ft_putstr("\t-a\t\t: Show aff output (hidden by default)\n");
	ft_putstr("\t-l\t\t: Hide live executions (displayed by default)\n");
	ft_putstr("\t-v\t\t: Visual mode\n\n");
	exit(0);
}

int	announce_winner(t_game *game)
{
	if (game->print)
		ft_printf("Player %d (%s) won\n", -game->last_alive,
		game->playerlist[-(game->last_alive + 1)]->name);
	else
	{
		ft_putstr("Player ");
		ft_putnbr(-game->last_alive);
		ft_putstr(" (");
		ft_putstr(game->playerlist[-(game->last_alive + 1)]->name);
		ft_putstr(") won\n");
	}
	return (0);
}

/*
**	-	validate args, gather flags and players in read_arguments
**	-	rearrange players in case n-flags were used to choose player positions
**	-	read each players file and write them to memory in get_player loop
**	-	set carriages
**	-	introduce players and start game
*/

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
	while (i < game->players)
	{
		get_player(i, game->playerlist[i]->argu, game);
		i++;
	}
	first_carriages(game);
	if (!game->visual)
		print_players(game);
	play(game);
	free_all_and_exit(game);
}
