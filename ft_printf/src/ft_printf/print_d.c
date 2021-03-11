/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 10:15:00 by cphillip          #+#    #+#             */
/*   Updated: 2021/03/02 07:36:35 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
**	Handles the ' ' and '+' value provided the nbr >= 0. Else return \0
*/

t_struct	*negativity(t_struct *csp, intmax_t nbr)
{
	if (nbr >= 0)
	{
		if (csp->c_flags[1] == '+')
			csp->get_plus = '+';
		else if (csp->c_flags[2] == ' ')
			csp->get_plus = ' ';
		else
			csp->get_plus = '\0';
	}
	return (csp);
}

/*
**	This function handles the output for numbers == 0 with no precision
*/

void		do_basic_d(t_struct *csp, intmax_t nbr)
{
	if (nbr == 0 && csp->prec == 0)
	{
		if (csp->get_plus != '\0')
			csp->width--;
		if (csp->c_flags[0] != '-')
			print_alt(csp, csp->width, ' ');
		if (csp->c_flags[1] == '+')
			print_alt(csp, 1, '+');
		else if (csp->c_flags[2] == ' ')
			print_alt(csp, 1, ' ');
		if (csp->c_flags[0] == '-')
			print_alt(csp, csp->width, ' ');
	}
}

/*
**	Takes care of the printing of whitespace and filler values
*/

void		do_d(t_struct *csp, int zeroes, int is_neg)
{
	if (csp->c_flags[0] != '-')
		print_alt(csp, csp->width - zeroes - csp->s_len, ' ');
	if (is_neg)
		write(1, "-", 1);
	if (csp->get_plus != '\0')
		write(1, &csp->get_plus, 1);
	print_alt(csp, zeroes, '0');
}

/*
**	Handles zero counting. Many bandaid fixes resulting in nasty if/else
*/

int			get_zeroes(t_struct *csp, int is_neg)
{
	int			zeroes;

	zeroes = 0;
	if (csp->c_flags[4] == '0' && csp->c_flags[0] != '-')
	{
		if (csp->prec >= 0 && csp->prec >= csp->s_len)
			zeroes = csp->prec - csp->s_len;
		else if (csp->prec >= 0 && csp->prec < csp->s_len)
			zeroes = 0;
		else if (csp->prec == -1)
		{
			zeroes = csp->width - csp->s_len;
			zeroes -= is_neg ? 1 : 0;
			if (csp->c_flags[2] == ' ' && csp->c_flags[1] != '+' && !is_neg)
				zeroes -= 1;
		}
		if (csp->c_flags[1] == '+' && !is_neg && csp->prec == -1)
			zeroes -= 1;
	}
	else if (csp->c_flags[0] == '-' || csp->c_flags[4] != '0')
	{
		if (csp->prec > 0 && csp->prec > csp->s_len)
			zeroes = csp->prec - csp->s_len;
	}
	return (zeroes);
}

/*
**	Handles the obtainment of the nbr as well as final printing.
*/

t_struct	*print_d(t_struct *csp)
{
	long long	nbr;
	int			zeroes;
	int			is_neg;

	nbr = get_d_nbr(csp);
	negativity(csp, nbr);
	if (nbr == 0 && csp->prec == 0)
	{
		do_basic_d(csp, nbr);
		return (csp);
	}
	is_neg = (nbr < 0) ? 1 : 0;
	csp->s_len = nbr == 0 ? 1 : ft_nbr_size(nbr);
	nbr *= (is_neg && nbr != (-9223372036854775807 - 1)) ? -1 : 1;
	zeroes = get_zeroes(csp, is_neg);
	csp->s_len += csp->get_plus != '\0' || is_neg ? 1 : 0;
	do_d(csp, zeroes, is_neg);
	if (nbr == -9223372036854775807 - 1)
		handle_max(csp);
	else
		ft_putnbrmax(nbr);
	if (csp->c_flags[0] == '-')
		print_alt(csp, csp->width - zeroes - csp->s_len, ' ');
	csp->len += csp->s_len;
	return (csp);
}
