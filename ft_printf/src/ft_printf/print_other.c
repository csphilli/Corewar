/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 12:13:08 by cphillip          #+#    #+#             */
/*   Updated: 2021/03/02 07:36:35 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
** Printing the % with whitespaces or zero fillers
*/

t_struct	*print_pcent(t_struct *csp)
{
	if (csp->c_flags[4] == '0' && !csp->c_flags[0] && csp->prec <= 0)
	{
		csp->prec = csp->width;
		csp->width = 0;
	}
	if (csp->c_flags[0] != '-')
		print_alt(csp, csp->width - 1, ' ');
	if (csp->c_flags[4] == '0')
		print_alt(csp, csp->prec - 1, '0');
	write(1, "%", 1);
	if (csp->c_flags[0] == '-')
		print_alt(csp, csp->width - 1, ' ');
	csp->len += 1;
	return (csp);
}

/*
**	I thought there might be more "others" to print here but it ended up
**	just being a stager for printing a % sign or white space
*/

void		print_other(t_struct *csp)
{
	if (csp->c_fmt[csp->i] == '%')
		print_pcent(csp);
	else
		print_alt(csp, csp->width - 1, ' ');
}
