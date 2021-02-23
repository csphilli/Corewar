/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii_to_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 22:39:32 by osalmine          #+#    #+#             */
/*   Updated: 2021/02/23 16:50:08 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"
// #include "../../includes/asm.h"

static int		check_for_neg(int *nb)
{
	int neg;

	neg = 0;
	if (nb < 0)
	{
		neg = 1;
		*nb *= -1;
	}
	return (neg);
}

static uint32_t	reverse_hex(uint32_t hex)
{
	uint32_t	quotient;
	uint32_t	remainder;

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

static uint32_t	reverse_neg(uint32_t hex, int neg)
{
	if (neg)
	{
		hex = ~hex;
		hex++;
	}
	return (hex);
}

/*
**	Converts a base 10 number to a uin32_t hex value
**	there is a lot of room for improvement here in
**	tidying up the code
*/

uint32_t		dec_to_hex(int nb)
{
	uint32_t	hex;
	uint32_t	quotient;
	uint32_t	remainder;
	int			zero_toggle;
	int			neg;

	neg = check_for_neg(&nb);
	hex = 0x0;
	quotient = nb;
	zero_toggle = 0;
	while (quotient != 0)
	{
		remainder = quotient % 16;
		if (remainder == 0 && hex == 0)
			zero_toggle++;
		hex *= 16;
		hex += remainder;
		quotient /= 16;
	}
	hex = reverse_hex(hex);
	hex = hex << (4 * zero_toggle);
	hex = reverse_neg(hex, neg);
	return (hex);
}

/*
**	Converts a string to a hexadecimal array
**	zork -> [7a, 6f, 72, 6b] where the hex is the char's ascii value
*/

uint8_t			*ascii_to_hex(char *str)
{
	int		i;
	uint8_t	*hex;

	if (!(hex = (uint8_t*)ft_memalloc(sizeof(uint8_t) * ft_strlen(str))))
		ft_errorexit("ERROR: Malloc error\n");
	i = 0;
	while (str[i])
	{
		hex[i] = dec_to_hex((int)str[i]);
		i++;
	}
	return (hex);
}
