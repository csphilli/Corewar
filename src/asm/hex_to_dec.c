/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 13:25:48 by csphilli          #+#    #+#             */
/*   Updated: 2021/02/23 16:50:08 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void	print_hex_error(t_ins *ins, char *str)
{
	ft_putstr_fd("ERROR: Invalid hex str \'", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\' on line ", 2);
	ft_putnbr_fd(ins->line, 2);
	ft_putendl_fd(".", 2);
	exit(1);
}

/*
**	Error checking for hex string. Must follow hex string definition
**	otherwise errors out.
*/

void	error_chk_hex(t_ins *ins, char *hex, int len)
{
	int		i;
	char	*error;

	i = 0;
	error = NULL;
	while (i < len)
	{
		if ((ft_toupper(hex[i]) == 'X' && i == 1) || \
			(ft_toupper(hex[i]) >= 'A' && ft_toupper(hex[i]) <= 'F') ||\
			(hex[i] >= '0' && hex[i] <= '9'))
			i++;
		else
		{
			error = ft_strndup(hex, len);
			print_hex_error(ins, error);
			ft_strdel(&error);
		}
	}
}

/*
**	Calculates the length of a hex string. Returns i - 1
**	otherwise the result is sitting on '\0' or unwanted value.
*/

int		hex_len(char *line)
{
	int	i;

	i = 0;
	while (ft_isalnum(line[i]))
		i++;
	return (i - 1);
}

/*
**	Converts a hex string to decimal. Returns the int value
**	and sets the *e_ptr to the last spot in the hex string.
**	Makes converting mutliple strings "easier".
*/

int		hex_to_dec(t_ins *ins, char *hex_str)
{
	int		len;
	int		i;
	int		sum;

	i = 0;
	sum = 0;
	len = hex_len(hex_str);
	error_chk_hex(ins, hex_str, len);
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

/*
**	Parses a line and converts all valid hex strings to decimal.
**	char *end is used to keep track of the latest spot in the
**	string after conversion so that the loop continues where it left off
*/

void	convert_hex(t_ins *ins, char **line)
{
	char	*tmp;
	char	*new;
	char	*hex;

	tmp = *line;
	new = ft_strnew(ft_strlen(tmp));
	while (*tmp)
	{
		if (is_hex(tmp))
		{
			hex = ft_itoa(hex_to_dec(ins, tmp));
			ft_strcat(new, hex);
			ft_strdel(&hex);
			while (*(tmp + 1) && *(tmp + 1) != '+' && *(tmp + 1) != '-')
				tmp++;
		}
		else
			ft_charcat(new, *tmp);
		tmp++;
	}
	ft_strdel(line);
	*line = new;
}
