/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 21:52:25 by osalmine          #+#    #+#             */
/*   Updated: 2021/02/12 22:45:39 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	nb_len is divided by 2 as e.g. 0xea83f3 is 6 numbers
**	but is split to ea 83 f3
**	the weird looking stuff in the loop just grabs the first number but as
**	they are in reverse order, it gets stored in a variable, gets the second
**	nb, shifts the split to make room for the first number and combines the two
*/

int32_t	*split_hex(int32_t nb, int nb_len)
{
	int32_t	*split;
	int		i;
	int32_t	first_nb;

	printf("split size: %d\n", nb_len / 2);
	if (!(split = (int32_t*)ft_memalloc(sizeof(int32_t) * (nb_len / 2))))
		ft_errorexit("ERROR: Malloc error");
	i = nb_len / 2;
	while (--i >= 0)
	{
		first_nb = nb % 16;
		nb /= 16;
		split[i] += nb % 16;
		split[i] = split[i] << 4;
		split[i] += first_nb;
		nb /= 16;
		printf("split[%d]: %x\n", i, split[i]);
	}
	return (split);
}