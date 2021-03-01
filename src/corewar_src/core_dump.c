/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_dump.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/core.h"

int	dump_game(t_game *game)
{
	int		i;
	int		a;

	i = 0;
	while (i < MEM_SIZE)
	{
		printf("0x%04x : ", i);
		a = 0;
		while (a < 64)
		{
			printf("%02x ", game->memory[i]);
			a++;
			i++;
		}
		printf("\n");
	}
	return (0);
}
