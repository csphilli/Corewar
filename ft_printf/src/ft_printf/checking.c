/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:16:22 by cphillip          #+#    #+#             */
/*   Updated: 2021/03/02 07:36:39 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
**	Obtaining the conversion flags
*/

t_struct	*chk_conv_flags(t_struct *csp)
{
	size_t	i;

	i = 0;
	while (csp->format_flags[i] != '\0')
	{
		while (csp->format_flags[i] == csp->srch_fmt[csp->i])
		{
			if (csp->srch_fmt[csp->i] == '-')
				csp->c_flags[0] = '-';
			else if (csp->srch_fmt[csp->i] == '+')
				csp->c_flags[1] = '+';
			else if (csp->srch_fmt[csp->i] == ' ')
				csp->c_flags[2] = ' ';
			else if (csp->srch_fmt[csp->i] == '#')
				csp->c_flags[3] = '#';
			else if (csp->srch_fmt[csp->i] == '0')
				csp->c_flags[4] = '0';
			i = 0;
			csp->i++;
		}
		i++;
	}
	return (csp);
}

/*
**	Obtaining the width
*/

t_struct	*chk_width(t_struct *csp)
{
	while (ft_isdigit(csp->srch_fmt[csp->i]))
	{
		csp->width *= 10;
		csp->width += (csp->srch_fmt[csp->i] - 48);
		csp->i++;
	}
	return (csp);
}

/*
**	Obtaining precision
*/

t_struct	*chk_precision(t_struct *csp)
{
	if (csp->srch_fmt[csp->i] == '.')
	{
		csp->prec = 0;
		csp->i++;
	}
	while (ft_isdigit(csp->srch_fmt[csp->i]))
	{
		csp->prec *= 10;
		csp->prec += (csp->srch_fmt[csp->i] - 48);
		csp->i++;
	}
	return (csp);
}

/*
**	Obtaining the length arguments
*/

t_struct	*chk_arg_flags(t_struct *csp)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (csp->a_flags[i] != '\0')
	{
		while (csp->a_flags[i] == csp->srch_fmt[csp->i])
		{
			csp->len_flags[j] = csp->srch_fmt[csp->i];
			csp->len_flags[j + 1] = '\0';
			j++;
			csp->i++;
		}
		i++;
	}
	return (csp);
}

/*
**	Obtaining the specifier
*/

t_struct	*chk_specifier(t_struct *csp)
{
	int i;

	i = 0;
	while (csp->spec_flags[i] != '\0')
	{
		if (csp->srch_fmt[csp->i] == csp->spec_flags[i])
			csp->specifier = csp->srch_fmt[csp->i];
		i++;
	}
	return (csp);
}
