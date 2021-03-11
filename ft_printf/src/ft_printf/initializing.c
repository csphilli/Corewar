/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:10:49 by cphillip          #+#    #+#             */
/*   Updated: 2021/03/02 07:36:35 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
**	These functions "set the table" for the struct.
*/

t_struct	*initialize(t_struct *csp)
{
	csp->i = 0;
	csp->len = 0;
	csp->padding = 0;
	csp->s_len = 0;
	csp->format_flags = "#0-+ ";
	csp->a_flags = "lhL";
	csp->spec_flags = "cspdiouxXfF%";
	csp->hex_chars = "0123456789abcdef";
	csp->c_fmt = (char *)csp->fmt;
	csp->srch_fmt = (char *)csp->fmt;
	return (csp);
}

t_struct	*re_init(t_struct *csp)
{
	csp->get_plus = '\0';
	csp->specifier = '\0';
	csp->prec = -1;
	csp->width = 0;
	csp->c_flags[0] = '\0';
	csp->c_flags[1] = '\0';
	csp->c_flags[2] = '\0';
	csp->c_flags[3] = '\0';
	csp->c_flags[4] = '\0';
	csp->c_flags[5] = '\0';
	csp->len_flags[0] = '\0';
	csp->len_flags[1] = '\0';
	csp->len_flags[2] = '\0';
	return (csp);
}
