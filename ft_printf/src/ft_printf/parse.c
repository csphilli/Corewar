/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:23:05 by cphillip          #+#    #+#             */
/*   Updated: 2021/03/02 07:36:35 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
**	This function prevents the parser from going beyond an invalid
**	specifier. It will only proceed if one of the specifiers is found
*/

static int	test_validity(t_struct *csp)
{
	int i;

	i = csp->i + 1;
	while (!ft_strchr("cspdDiouxXfF%", (int)csp->c_fmt[i]))
		i++;
	if (csp->c_fmt[i] != '\0')
		return (1);
	return (0);
}

/*
**	Parsing with a validity checker
*/

int			parse(t_struct *csp)
{
	int valid;

	valid = 0;
	if (ft_strcmp(csp->c_fmt, "%") == 0)
		return (0);
	while (csp->c_fmt[csp->i] != '\0')
	{
		if (csp->c_fmt[csp->i] == '%')
		{
			valid = test_validity(csp);
			if (valid == 0)
				return (0);
			re_init(csp);
			pre_staging(csp);
		}
		else
		{
			write(1, &csp->c_fmt[csp->i], 1);
			csp->len++;
		}
		csp->i++;
	}
	return (csp->len);
}
