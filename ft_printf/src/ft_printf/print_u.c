/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 10:15:00 by cphillip          #+#    #+#             */
/*   Updated: 2021/03/02 07:36:35 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void			print_u_zero(t_struct *csp, uintmax_t nbr)
{
	if (nbr && nbr == 0)
		print_alt(csp, 1, '0');
}

static int			collect_u(t_struct *csp)
{
	int			n_blank;

	n_blank = csp->s_len;
	if (csp->c_flags[4] == '0' && csp->prec == -1 && csp->c_flags[3] != '-')
		csp->prec = csp->width;
	if (csp->s_len <= csp->prec && csp->prec > 0)
		n_blank = csp->prec;
	if (csp->c_flags[0] != '-')
		print_alt(csp, csp->width - n_blank, ' ');
	return (n_blank);
}

t_struct			*print_u(t_struct *csp)
{
	char		*tmp;
	uintmax_t	nbr;
	int			n_blank;

	nbr = get_oux_nbr(csp);
	if (nbr == 0 && csp->prec == 0)
	{
		print_alt(csp, csp->width, ' ');
		return (csp);
	}
	if (nbr == 9223372036854775807)
		tmp = ft_strdup("9223372036854775807");
	else
		tmp = nbr == 0 ? ft_strdup("0") : ft_itoa_base(nbr, 10);
	csp->s_len = nbr == 0 ? 1 : ft_strlen(tmp);
	n_blank = collect_u(csp);
	print_u_zero(csp, nbr);
	print_alt(csp, csp->prec - csp->s_len, '0');
	ft_putstr(tmp);
	csp->len += ft_strlen(tmp);
	if (csp->c_flags[0] == '-')
		print_alt(csp, csp->width - n_blank, ' ');
	free(tmp);
	return (csp);
}
