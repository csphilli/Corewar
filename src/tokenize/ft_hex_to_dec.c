/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 13:25:48 by csphilli          #+#    #+#             */
/*   Updated: 2021/02/16 15:01:07 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	print_hex_error(char *str)
{
	ft_putstr_fd("ERROR: Invalid hex str: ", 2);
	ft_putendl_fd(str, 2);
	exit(1);
}

void	error_chk_hex(char *hex)
{
	int	i;

	i = 0;
	while (hex[i])
	{
		if ((ft_toupper(hex[i]) == 'X' && i == 1) || \
			(ft_toupper(hex[i]) >= 'A' && ft_toupper(hex[i]) <= 'F') ||\
			(hex[i] >= '0' && hex[i] <= '9'))
			i++;
		else
			print_hex_error(hex);
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
