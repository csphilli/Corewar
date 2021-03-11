/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 11:49:10 by cphillip          #+#    #+#             */
/*   Updated: 2021/03/02 07:36:35 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static char		*do_x(t_struct *csp, uintmax_t nbr, int m_z, char *tmp)
{
	if (csp->c_flags[0] != '-')
		print_alt(csp, csp->padding, ' ');
	print_zero(csp, csp->specifier, nbr);
	print_alt(csp, m_z, '0');
	if (csp->specifier == 'X')
		ft_s_toupper(tmp);
	else
		ft_putstr(tmp);
	if (csp->c_flags[0] == '-')
		print_alt(csp, csp->padding, ' ');
	return (0);
}

t_struct		*print_zero(t_struct *csp, char spec, uintmax_t nbr)
{
	if (nbr && csp->c_flags[3] == '#')
	{
		if (spec == 'X')
		{
			write(1, "0X", 2);
			csp->len += 2;
		}
		else if (spec == 'x')
		{
			write(1, "0x", 2);
			csp->len += 2;
		}
	}
	return (csp);
}

/*
**	Nastly little function, m_z is to obtain the middle zero value. This is
**	the zero which will fill when prec -1 or when prec > s_len.
*/

static int		get_mz(t_struct *csp, uintmax_t nbr, int s_len, int mod)
{
	int		m_z;
	int		prec;

	prec = csp->prec;
	if (csp->c_flags[4] == '0' && prec == -1 && !nbr)
		m_z = csp->width - s_len;
	else if (!nbr && (prec == 0 || prec == -1))
		m_z = 1;
	else if (csp->c_flags[4] == '0' && prec == -1)
		m_z = csp->width - s_len - mod;
	else if (csp->c_flags[4] == '0' && csp->c_flags[3] == '#' && prec != -1)
		m_z = prec - s_len;
	else if (csp->c_flags[4] != '0' && prec && prec > s_len)
		m_z = prec - s_len;
	else if (csp->c_flags[4] != '0' && prec == -1 && nbr)
		m_z = 0;
	else
		m_z = prec - s_len - mod;
	if (csp->c_flags[4] == '0' && csp->c_flags[0] == '-' && csp->prec == -1)
		m_z = 0;
	return (m_z = m_z < 0 ? 0 : m_z);
}

/*
**	Mod is the value if a # is specified. It adds 2 to the strlen
*/

t_struct		*print_x(t_struct *csp)
{
	char		*tmp;
	uintmax_t	nbr;
	int			m_z;
	int			mod;

	m_z = 0;
	nbr = get_oux_nbr(csp);
	if (nbr == 0 && csp->prec == 0)
	{
		print_alt(csp, csp->width, ' ');
		return (csp);
	}
	tmp = ft_itoa_base(nbr, 16);
	mod = (csp->c_flags[3] == '#' && nbr) ? 2 : 0;
	csp->s_len = ft_strlen(tmp);
	m_z = get_mz(csp, nbr, csp->s_len, mod);
	x_padding(csp, m_z, mod, nbr);
	do_x(csp, nbr, m_z, tmp);
	csp->len += csp->s_len;
	free(tmp);
	return (csp);
}
