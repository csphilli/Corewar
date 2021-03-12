/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

int	get_dump_flag(char *arg, t_game *game)
{
	int		i;

	if (game->visual == 1)
		return (arg_error(7, game));
	i = 0;
	if (arg == NULL)
		return (arg_error(5, game));
	while (arg[i])
	{
		if (i == 9)
			return (arg_error(1, game));
		if (!(ft_isdigit(arg[i])))
			return (arg_error(2, game));
		i++;
	}
	game->dump_cycle = ft_atoi(arg);
	return (2);
}

int	get_print_flag(int i, t_game *game)
{
	if (game->visual)
		return (arg_error(7, game));
	game->print = 1;
	return (i + 1);
}

int	get_visual_flag(int i, t_game *game)
{
	if (game->print || game->dump_cycle != -1 || game->aff || game->live_print)
		return (arg_error(7, game));
	game->visual = 1;
	return (i + 1);
}

int	get_aff_flag(int i, t_game *game)
{
	if (game->visual)
		return (arg_error(7, game));
	game->aff = 1;
	return (i + 1);
}

int	get_live_print_flag(int i, t_game *game)
{
	if (game->visual)
		return (arg_error(7, game));
	game->live_print = 1;
	return (i + 1);
}
