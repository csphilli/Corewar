/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 10:15:00 by cphillip          #+#    #+#             */
/*   Updated: 2021/03/02 07:36:35 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
**	Handles the pre-printing of filler values
*/

static void			do_f(long double nbr, t_struct *csp, int not_blank,\
					int zeroes)
{
	if (!csp->c_flags[0] && !csp->c_flags[4])
		print_alt(csp, csp->width - not_blank, ' ');
	if (csp->c_flags[2] == ' ' && nbr >= 0 && csp->width)
		print_alt(csp, 1, ' ');
	if (nbr < 0)
		print_alt(csp, 1, '-');
	if (nbr >= 0 && csp->c_flags[1] == '+')
		print_alt(csp, 1, '+');
	if (csp->c_flags[4] == '0' && zeroes >= 1)
		print_alt(csp, zeroes, '0');
}

/*
**	not_blank is used to help facilitate what to actually print
*/

static int			collect_f(t_struct *csp, long double nbr, int not_blank)
{
	if (csp->prec == 0 && csp->c_flags[3] == '#')
		not_blank++;
	if (csp->c_flags[2] == ' ' && nbr >= 0)
		not_blank++;
	if (nbr < 0 || (csp->c_flags[1] == '+' && nbr >= 0))
		not_blank++;
	return (not_blank);
}

/*
**	Handles the initial formatting/number collection as well as printing
**	the final value for floats.
*/

t_struct			*print_f(t_struct *csp)
{
	long double	nbr;
	char		*flt;
	int			not_blank;
	int			zeroes;

	zeroes = 0;
	nbr = get_float(csp);
	nbr < 0 ? csp->len-- : csp->len;
	flt = ft_ftoa(nbr, csp->prec, '.');
	not_blank = ft_strlen(flt);
	not_blank = collect_f(csp, nbr, not_blank);
	if (!csp->c_flags[0] && csp->width > csp->prec && csp->width > not_blank)
		zeroes = csp->width - not_blank;
	do_f(nbr, csp, not_blank, zeroes);
	ft_putstr(flt);
	if (csp->c_flags[3] && csp->prec == 0)
		print_alt(csp, 1, '.');
	if (csp->c_flags[0] == '-')
		print_alt(csp, csp->width - not_blank, ' ');
	csp->len += not_blank;
	free(flt);
	return (csp);
}
