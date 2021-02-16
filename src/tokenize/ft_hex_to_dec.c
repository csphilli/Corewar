/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 13:25:48 by csphilli          #+#    #+#             */
/*   Updated: 2021/02/16 14:48:20 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	error_chk_hex(char *hex)
{
	int	i;

	i = 0;
	while (hex[i])
	{
		if (ft_toupper(hex[i]) == 'X' && i != 1)
			ft_error("ERROR: Invalid Hex string.\n");
		if ((ft_toupper(hex[i]) >= 'A' && ft_toupper(hex[i]) <= 'Z') ||
			(hex[i] >= '0' && hex[i] <= '9'))
			i++;
		else
			ft_error("ERROR: Invalid Hex Char.\n");
	}
}

int		ft_hex_to_dec(char *hex_str)
{
	int	len;
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	len = strlen(hex_str) - 1;
	error_chk_hex(hex_str);
	while (hex_str[len] && hex_str[len] != 'x' && \
			hex_str[len] != 'X')
	{
		if (hex_str[len] >= 'A' && hex_str[len] <= 'F')
			sum += ft_pow(16, i) * (hex_str[len] - 'A' + 10);
		else if (hex_str[len] >= 'a' && hex_str[len] <= 'f')
			sum += ft_pow(16, i) * (hex_str[len] - 'a' + 10);
		else
			sum += ft_pow(16, i) * (hex_str[len] - '0');
		len--;
		i++;
	}
	return (sum);
}
