/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii_to_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 22:39:32 by osalmine          #+#    #+#             */
/*   Updated: 2021/02/12 23:23:48 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	dec_to_hex(int nb)
{
	int hex;
	int quotient;
	int	remainder;

	hex = 0x0;
	quotient = nb;
	while (quotient != 0)
	{
		remainder = quotient % 16;
		hex *= 16;
		hex += remainder;
		quotient /= 16;
	}
	quotient = hex;
	hex = 0;
	while (quotient != 0)
	{
		remainder = quotient % 16;
		hex = hex * 16 + remainder;
		quotient /= 16;
	}
	return (hex);
}

int32_t		*ascii_to_hex(char *str)
{
	int		i;
	int32_t	*hex;

	if (!(hex = (int32_t*)ft_memalloc(sizeof(char) * ft_strlen(str))))
		ft_errorexit("ERROR: Malloc error");
	i = 0;
	while (str[i])
	{
		// next_nb = dec_to_hex((int)str[i]);
		// printf("hex bef:\t%#x, shift amount: %d\n", hex, 4 * ft_nbr_size_base(next_nb, 16));
		// hex = hex[i] << (4 * ft_nbr_size_base(next_nb, 16));
		// printf("hex between:\t%#x\n", hex);
		// hex += next_nb;
		// printf("hex aft:\t%#x\n", hex);
		// printf("char: %c, as hex: %x, (int)str[i]: %d\n\n", str[i], next_nb, (int)str[i]);
		hex[i] = dec_to_hex((int)str[i]);
		i++;
	}
	return (hex);
}