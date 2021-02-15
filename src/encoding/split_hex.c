/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 21:52:25 by osalmine          #+#    #+#             */
/*   Updated: 2021/02/15 17:05:11 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	nb_len is divided by 2 as e.g. 0xea83f3 is 6 numbers
**	but is split to ea 83 f3
**	the weird looking stuff in the loop just grabs the first number but as
**	they are in reverse order (would be ae 38 3f otherwise),
**	gets it stored in a variable, gets the second nb to split,
**	shifts the split to make room for the first number and combines the two
*/

uint8_t	*split_hex(int32_t nb, int nb_len)
{
	uint8_t	*split;
	int		i;
	uint8_t	first_nb;
	int		zero_padding;

	// printf("nbr_size: %d\n", ft_nbr_size_base(nb, 16));
	zero_padding = ft_nbr_size_base(nb, 16) - nb_len;
	zero_padding = zero_padding < 0 ? 0 : zero_padding;
	if (nb_len % 2 != 0)
		nb_len = (nb_len / 2) + 1;
	else
		nb_len /= 2;
	// printf("split size: %d, zero_padding: %d\n", nb_len, zero_padding);
	if (!(split = (uint8_t*)ft_memalloc(sizeof(uint8_t) * nb_len)))
		ft_errorexit("ERROR: Malloc error");
	ft_bzero(split, nb_len);
	i = nb_len - zero_padding;
	while (--i >= 0)
	{
		first_nb = nb % 16;
		// printf("first nb: %#x\n", first_nb);
		nb /= 16;
		split[i] += nb % 16;
		// printf("split[%d]: %#x\n", i, split[i]);
		split[i] = split[i] << 4;
		// printf("split[%d]: %#x\n", i, split[i]);
		split[i] += first_nb;
		nb /= 16;
		// printf("split[%d]: %#x\n", i, split[i]);
	}
	return (split);
}
