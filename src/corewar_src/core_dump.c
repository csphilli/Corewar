/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_dump.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2021/03/02 12:40:00 by csphilli         ###   ########.fr       */
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
		ft_printf("0x%04x : ", i);
		a = 0;
		while (a < 64)
		{
			ft_printf("%02x ", game->memory[i]);
			a++;
			i++;
		}
		ft_printf("\n");
	}
	return (0);
}
