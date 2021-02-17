/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 21:16:36 by osalmine          #+#    #+#             */
/*   Updated: 2021/02/17 20:05:07 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	calc_champ_size(t_master *m)
{
	t_node	*tmp;
	int		size;

	size = 0;
	tmp = ((t_list*)&m->instrux)->head;
	while (tmp)
	{
		size += ((t_ins*)tmp->data)->bytes;
		tmp = tmp->next;
	}
	return (size);
}

/*
**	the + 16 =
**	magic header (4) + 2 * null (= 2 * 4) + champion exec code size (4)
*/

static int	calc_encoded_size(t_master *m)
{
	int		size;

	size = PROG_NAME_LENGTH + COMMENT_LENGTH + 16;
	size += calc_champ_size(m);
	return (size);
}

/*
**	champ calculations are done to place the champ size in the correct place
**	it has 4 bytes to use and has to be left-justified (e.g. 00 00 00 16)
**	if the champ size is 0x1F4 bytes in hex (500 in dec), champ offset is 1
**	and as the remainder from champ nbr_size is not divisible by 2 it
**	gets incresed by one
**	(meaning that the champ needs +1 bytes to display: 01 F4)
*/

static void	encode_header(t_master *m)
{
	int champ_size;
	int	champ_offset;
	int	champ_bytes_len;

	champ_size = dec_to_hex(calc_champ_size(m));
	champ_offset = ft_nbr_size_base(champ_size, 16) / 2;
	champ_bytes_len = ft_nbr_size_base(champ_size, 16) % 2 != 0 \
						? champ_offset + 1 : champ_offset;
	if (ft_nbr_size_base(champ_size, 16) % 2 == 0)
		champ_offset--;
	set_bytes(m, \
		split_hex(COREWAR_EXEC_MAGIC, \
		ft_nbr_size_base(COREWAR_EXEC_MAGIC, 16)), \
		ft_nbr_size_base(COREWAR_EXEC_MAGIC, 16) / 2, 1);
	set_bytes(m, \
		ascii_to_hex(m->champ->champ_name), \
		ft_strlen(m->champ->champ_name), 4);
	set_bytes(m, \
		split_hex(champ_size, ft_nbr_size_base(champ_size, 16)), \
		champ_bytes_len, 4 + PROG_NAME_LENGTH + 7 - champ_offset);
	set_bytes(m, \
		ascii_to_hex(m->champ->champ_comment), \
		ft_strlen(m->champ->champ_comment), 4 + PROG_NAME_LENGTH + 8);
}

/*
**	Main encoding function. Writing to file happens in main.c
**	remove the comment to see the final encoded memory
*/

void		encode_asm(t_master *m)
{
	if (!m->champ->champ_name || !m->champ->champ_comment \
								|| !m->champ->champ_size)
		ft_errorexit("ERROR: incomplete input\n");
	m->encoded_player_size = calc_encoded_size(m);
	if (!(m->encoded_player = (uint8_t*)ft_memalloc(sizeof(uint8_t) \
										* m->encoded_player_size)))
		ft_errorexit("ERROR: Malloc error\n");
	ft_bzero(m->encoded_player, m->encoded_player_size);
	encode_header(m);
	encode_ins(m);
	// printf("\nEncoding\n");
	// for (int i = 0; i < m->encoded_player_size; i++)
	// {
	// 	if (i == 0)
	// 		printf("%08x   ", i);
	// 	if (i % 8 == 0 && i != 0)
	// 		printf("  ");
	// 	if (i % 16 == 0 && i != 0)
	// 		printf("\n%08x   ", i);
	// 	printf("%02x ", m->encoded_player[i]);
	// }
	// printf("\nDone\n");
}
