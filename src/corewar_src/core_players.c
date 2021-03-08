/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

int	name(char *arg, unsigned char *buf, t_player *player)
{
	int			i;

	i = 0;
	while ((int)buf[i] != 0)
	{
		player->name[i] = buf[i];
		i++;
		if (i > PROG_NAME_LENGTH)
			return (player_error(arg, 2));
	}
	player->name[i] = '\0';
	return (0);
}

int	comment(char *arg, unsigned char *buf, t_player *player)
{
	int			i;

	i = 0;
	while ((int)buf[i] != 0)
	{
		player->comment[i] = buf[i];
		i++;
		if (i > COMMENT_LENGTH)
			return (player_error(arg, 3));
	}
	player->comment[i] = '\0';
	return (0);
}

int	code(unsigned char *buf, size_t file_size, int pl_nr, t_game *game)
{
	size_t	i;
	int		start;
	int		meazure;

	i = PROG_NAME_LENGTH + COMMENT_LENGTH + 16;
	meazure = 0;
	start = MEM_SIZE / game->players * (pl_nr);
	game->playerlist[pl_nr]->start = start;
	while (i < file_size)
	{
		game->memory[start] = buf[i];
		game->cols[start] = pl_nr + 1;
		start++;
		meazure++;
		i++;
	}
	return (meazure);
}

int	size(unsigned char *buf, t_player *player)
{
	int			value;
	int			spot;

	spot = PROG_NAME_LENGTH + 8;
	value = (buf[spot] << 24) | (buf[spot + 1]) << 16 |
		(buf[spot + 2] << 8) | (buf[spot + 3]);
	player->size = value;
	return (0);
}

int	get_player(int player_nr, char *arg, t_game *game)
{
	int						fd;
	unsigned char			buf[4096];
	size_t					file_size;
	unsigned int			magic;
	int						code_length;

	fd = open(arg, O_RDWR);
	if (fd == -1)
		return (player_error(arg, 0));
	file_size = read(fd, buf, 4096);
	magic = (buf[0] << 24) | (buf[1]) << 16 | (buf[2] << 8) | (buf[3]);
	if (magic != COREWAR_EXEC_MAGIC)
		return (player_error(arg, 1));
	name(arg, &buf[4], game->playerlist[player_nr]);
	comment(arg, &buf[PROG_NAME_LENGTH + 12], game->playerlist[player_nr]);
	size(buf, game->playerlist[player_nr]);
	code_length = code(buf, file_size, player_nr, game);
	check_size(arg, code_length, game->playerlist[player_nr]);
	game->playerlist[player_nr]->color = player_nr + 1;
	game->playerlist[player_nr]->last_live = 0;
	game->playerlist[player_nr]->lives = 0;
	game->last_alive = -(player_nr + 1);
	return (0);
}
