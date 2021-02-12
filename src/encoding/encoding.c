/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 21:16:36 by osalmine          #+#    #+#             */
/*   Updated: 2021/02/12 23:26:47 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	encode_asm(t_master *m)
{
	m->encoded_player_size = PROG_NAME_LENGTH + COMMENT_LENGTH + 16; // 16 = magic header (4) + 2 * null (= 2 * 4) + champion exec code size (4)
	if (!(m->encoded_player = (int32_t*)ft_memalloc(sizeof(int32_t) * m->encoded_player_size)))
		ft_errorexit("ERROR: Malloc error");
	ft_bzero(m->encoded_player, m->encoded_player_size);
	set_bytes(m, \
		split_hex(COREWAR_EXEC_MAGIC, ft_nbr_size_base(COREWAR_EXEC_MAGIC, 16)), \
		ft_nbr_size_base(COREWAR_EXEC_MAGIC, 16) / 2, 1);
	// printf("name: %x\n", ascii_to_hex(m->champ->champ_name));
	// int32_t *name = ascii_to_hex(m->champ->champ_name);
	// for (size_t i = 0; i < ft_strlen(m->champ->champ_name); i++)
	// 	printf("%x ", name[i]);
	set_bytes(m, \
		ascii_to_hex(m->champ->champ_name), \
		ft_strlen(m->champ->champ_name), 4);
	set_bytes(m, \
		ascii_to_hex(m->champ->champ_comment), \
		ft_strlen(m->champ->champ_comment), 4 + PROG_NAME_LENGTH + 8);
	printf("\nEncoding\n");
	for (size_t i = 0; i < PROG_NAME_LENGTH \
				+ COMMENT_LENGTH + m->champ->champ_size + 16; i++)
	{
		if (i == 0)
			printf("%08zx   ", i);
		if (i % 8 == 0 && i != 0)
			printf("  ");
		if (i % 16 == 0 && i != 0)
			printf("\n%08zx   ", i);
		printf("%02x ", m->encoded_player[i]);
	}
	printf("\nDone, magic: %x, len: %d\n", COREWAR_EXEC_MAGIC, ft_nbr_size_base(COREWAR_EXEC_MAGIC, 16));
}