/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:58:08 by cphillip          #+#    #+#             */
/*   Updated: 2021/03/02 07:36:35 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
**	Handles the alt printing of whitespaces and zero fillers
*/

static int		do_p(t_struct *csp)
{
	int		zeroes;

	zeroes = 0;
	if (csp->c_flags[4] != '0')
	{
		if (csp->prec > 0 && csp->prec > csp->s_len)
			zeroes = csp->prec - csp->s_len;
		else if (csp->prec == -1 && csp->width > csp->s_len)
			zeroes = 0;
	}
	else if (csp->c_flags[4] == '0')
	{
		if (csp->width > csp->s_len && csp->prec == -1)
			zeroes = csp->width - csp->s_len - 2;
		else if (csp->width > csp->s_len && csp->prec > 0)
			zeroes = csp->prec - csp->s_len;
	}
	return (zeroes);
}

static t_struct	*handle_str(t_struct *csp, char *tmp)
{
	if (csp->prec == 0)
	{
		ft_putstr("\0");
		csp->len--;
	}
	else
		ft_putstr(tmp);
	return (csp);
}

/*
**	Printing P
*/

t_struct		*print_p(t_struct *csp)
{
	char		*tmp;
	uintmax_t	nbr;
	int			zeroes;

	zeroes = 0;
	nbr = (unsigned long)va_arg(csp->args, unsigned long int);
	nbr = (uintmax_t)nbr;
	tmp = nbr == 0 ? ft_strdup("0") : ft_itoa_base(nbr, 16);
	csp->s_len = ft_strlen(tmp);
	zeroes = do_p(csp);
	if (csp->c_flags[0] != '-')
		print_alt(csp, csp->width - csp->s_len - zeroes - 2, ' ');
	write(1, "0x", 2);
	print_alt(csp, zeroes, '0');
	csp->len += 2;
	handle_str(csp, tmp);
	csp->len += csp->s_len;
	if (csp->c_flags[0] == '-')
		print_alt(csp, csp->width - csp->s_len - zeroes - 2, ' ');
	free(tmp);
	return (csp);
}
