/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_bytes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 22:22:59 by osalmine          #+#    #+#             */
/*   Updated: 2021/02/26 08:00:33 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	sets bytes into the meory at a mem_offset location
**	mem_offset can be 0 to inset bytes to the start
*/

void	set_bytes(t_master *m, uint8_t *bytes, int bytes_amount, int mem_offset)
{
	int i;

	i = 0;
	while (i < bytes_amount && i + mem_offset < m->encoded_player_size)
	{
		m->encoded_player[i + mem_offset] = bytes[i];
		i++;
	}
	ft_memdel((void**)&bytes);
}

/*
**	sets one byte in the mem_offset place
*/

void	set_a_byte(t_master *m, uint8_t byte, int mem_offset)
{
	m->encoded_player[mem_offset] = byte;
}
