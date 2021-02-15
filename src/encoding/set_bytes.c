/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_bytes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 22:22:59 by osalmine          #+#    #+#             */
/*   Updated: 2021/02/15 17:05:17 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	mem_offset can be 0 to inset bytes to the start
*/

void	set_bytes(t_master *m, uint8_t *bytes, int bytes_amount, int mem_offset)
{
	int i;

	i = 0;
	// printf("bytes_amount: %d, mem_offset: %d, %#x\n", bytes_amount, mem_offset, mem_offset);
	// printf("i < bytes_amount: %s, i + mem_offset < encoded_player_size: %s\n", i < bytes_amount ? "TRUE" : "FALSE", i + mem_offset < m->encoded_player_size ? "TRUE" : "FALSE");
	while (i < bytes_amount && i + mem_offset < m->encoded_player_size)
	{
		m->encoded_player[i + mem_offset] = bytes[i];
		// printf("bytes[%d]: %#x\n", i, bytes[i]);
		i++;
	}
}

void	set_a_byte(t_master *m, uint8_t byte, int mem_offset)
{
	// printf("mem_offset: %d\n", mem_offset);
	m->encoded_player[0 + mem_offset] = byte;
	// printf("bytes[0 + %d]: %#x\n", mem_offset, byte);
}
