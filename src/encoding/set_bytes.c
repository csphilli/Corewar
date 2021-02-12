/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_bytes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 22:22:59 by osalmine          #+#    #+#             */
/*   Updated: 2021/02/12 22:36:14 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	mem_offset can be 0 to inset bytes to the start
*/

void	set_bytes(t_master *m, int32_t *bytes, int bytes_amount, int mem_offset)
{
	int i;

	i = 0;
	printf("bytes_amount: %d\n", bytes_amount);
	while (i < bytes_amount && i < m->encoded_player_size)
	{
		m->encoded_player[i + mem_offset] = bytes[i];
		i++;
	}
}