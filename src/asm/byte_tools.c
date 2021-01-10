/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 11:50:12 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/10 12:54:34 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		str_to_int_str(int **src, char *input, int max_len)
{
	int		i;
	int		*int_str;
	int		input_len;

	i = 0;
	input_len = ft_strlen(input);
	int_str = ft_memalloc(sizeof(int) * max_len);
	while (input_len--)
	{
		if (input[i])
			int_str[i] = input[i];
		i++;
	}
	*src = int_str;
}

char	*to_hex(int *int_str, int max_len)
{
	int 	i;
	char 	*byte_str;
	char	*res;

	i = 0;
	byte_str = ft_strnew(max_len);
	i = 0;
	while (i < max_len)
	{
		if (int_str[i])
		{
			byte_str = ft_strcat(byte_str, res = ft_itoa_base(int_str[i], 16));
			free(res);
		}
		else
			byte_str = ft_strcat(byte_str, "00");
		i++;
	}
	return (byte_str);
}
