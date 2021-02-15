/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii_to_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 22:39:32 by osalmine          #+#    #+#             */
/*   Updated: 2021/02/15 22:42:56 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

// static uint8_t	neg_dec_to_hex(nb)
// {
// 	printf("NEGATIVE NUMBER\n");
// 	nb = ~nb;
// 	nb++;
// 	return ((uint8_t)nb);
// }

uint32_t		dec_to_hex(int nb)
{
	uint32_t	hex;
	uint32_t	quotient;
	uint32_t	remainder;
	int			zero_toggle;
	int			neg;

	neg = 0;
	// printf("nb: %d\n", nb);
	if (nb < 0)
	{
		// printf("NEGATIVE NUMBER\n");
		// for (int i = 15; 0 <= i; i--) {
		// 	printf("%u ", (nb & (1 << i)) ? 1 : 0);
		// }
		// printf("\n");
		neg = 1;
		nb *= -1;
	}
	// for (int i = 31; 0 <= i; i--) {
	// 	printf("%u ", (nb & (1 << i)) ? 1 : 0);
	// }
	// printf("\n");
	hex = 0x0;
	quotient = nb;
	zero_toggle = 0;
	while (quotient != 0)
	{
		remainder = quotient % 16;
		if (remainder == 0)
			zero_toggle++;
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
	hex = hex << (4 * zero_toggle);
	if (neg)
	{
		// hex = 0xFF00;
		// printf("hex before neg: %#x\n", hex);
		// for (int i = 15; 0 <= i; i--) {
		// 	printf("%u ", (hex & (1 << i)) ? 1 : 0);
		// }
		// printf("\n");
		// hex = 0xFFFF ^ hex;
		hex = ~hex;
		// printf("hex after neg xor: %#x\n", hex);
		// for (int i = 15; 0 <= i; i--) {
		// 	printf("%u ", (hex & (1 << i)) ? 1 : 0);
		// }
		// printf("\n");
		hex++;
		// printf("hex after neg add 1: %#x\n", hex);
		// for (int i = 15; 0 <= i; i--) {
		// 	printf("%u ", (hex & (1 << i)) ? 1 : 0);
		// }
		// printf("\n");
	}
	// printf("returning hex: %#x\n", hex);
	return (hex);
}

uint8_t		*ascii_to_hex(char *str)
{
	int		i;
	uint8_t	*hex;

	if (!(hex = (uint8_t*)ft_memalloc(sizeof(uint8_t) * ft_strlen(str))))
		ft_errorexit("ERROR: Malloc error");
	i = 0;
	// printf("\nNEW STRING: %s\n", str);
	while (str[i])
	{
		// printf("str[%d]: |%c|, int: %d, hex: %#x\n", i, str[i], (int)str[i], (int)str[i]);
		hex[i] = dec_to_hex((int)str[i]);
		i++;
	}
	return (hex);
}
