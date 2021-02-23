/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 21:52:25 by osalmine          #+#    #+#             */
/*   Updated: 2021/02/23 16:50:08 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

/*
**	nb_len is divided by 2 as e.g. 0xea83f3 is 6 numbers
**	but is split to ea 83 f3
**	the weird looking stuff in the loop just grabs the first number but as
**	they are in reverse order (would be ae 38 3f otherwise),
**	gets it stored in a variable, gets the second nb to split,
**	shifts the split to make room for the first number and combines the two
*/

uint8_t	*split_hex(uint32_t nb, int nb_len)
{
	uint8_t	*split;
	int		i;
	uint8_t	first_nb;

	if (nb_len % 2 != 0)
		nb_len = (nb_len / 2) + 1;
	else
		nb_len /= 2;
	if (!(split = (uint8_t*)ft_memalloc(sizeof(uint8_t) * nb_len)))
		ft_errorexit("ERROR: Malloc error\n");
	ft_bzero(split, nb_len);
	i = nb_len;
	while (--i >= 0)
	{
		first_nb = nb % 16;
		nb /= 16;
		split[i] += nb % 16;
		split[i] = split[i] << 4;
		split[i] += first_nb;
		nb /= 16;
	}
	return (split);
}
