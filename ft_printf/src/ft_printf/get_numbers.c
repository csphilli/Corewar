/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:25:08 by cphillip          #+#    #+#             */
/*   Updated: 2021/03/02 07:36:35 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
** This function obtains the numbers for floats
*/

long double	get_float(t_struct *csp)
{
	long double nbr;

	if (ft_strcmp(csp->len_flags, "L") == 0)
		nbr = (long double)va_arg(csp->args, long double);
	else
		nbr = (double)va_arg(csp->args, double);
	return (nbr);
}

/*
**	This function obtains the numbers for the decimals/integers
*/

intmax_t	get_d_nbr(t_struct *csp)
{
	intmax_t nbr;

	if (ft_strcmp(csp->len_flags, "h") == 0)
		nbr = (short)va_arg(csp->args, long long);
	else if (ft_strcmp(csp->len_flags, "hh") == 0)
		nbr = (signed char)va_arg(csp->args, long long);
	else if (ft_strcmp(csp->len_flags, "l") == 0)
		nbr = (long)va_arg(csp->args, long long int);
	else if (ft_strcmp(csp->len_flags, "ll") == 0)
		nbr = (long long)va_arg(csp->args, long long);
	else
		nbr = (int)va_arg(csp->args, int);
	return (nbr);
}

/*
**	Obtains the numbers for o u x.
*/

uintmax_t	get_oux_nbr(t_struct *csp)
{
	uintmax_t nbr;

	if (ft_strcmp(csp->len_flags, "h") == 0)
		nbr = (unsigned short)va_arg(csp->args, unsigned int);
	else if (ft_strcmp(csp->len_flags, "hh") == 0)
		nbr = (unsigned char)va_arg(csp->args, unsigned int);
	else if (ft_strcmp(csp->len_flags, "l") == 0)
		nbr = (unsigned long)va_arg(csp->args, unsigned long int);
	else if (ft_strcmp(csp->len_flags, "ll") == 0)
		nbr = (unsigned long long)va_arg(csp->args, unsigned long long);
	else
		nbr = (unsigned int)va_arg(csp->args, unsigned int);
	nbr = (uintmax_t)nbr;
	return (nbr);
}
