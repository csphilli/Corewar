/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   staging.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:19:47 by cphillip          #+#    #+#             */
/*   Updated: 2021/03/02 07:36:35 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_struct	*staging(t_struct *csp)
{
	char	*spec;

	spec = &csp->specifier;
	if (ft_strchr("cspxXdDioufF%", (int)csp->srch_fmt[csp->i]))
	{
		if (*spec == 'c')
			print_c(csp);
		else if (*spec == 's')
			print_s(csp);
		else if (*spec == 'p')
			print_p(csp);
		else if (*spec == 'x' || *spec == 'X')
			print_x(csp);
		else if (*spec == 'o')
			print_o(csp);
		else if (*spec == 'u')
			print_u(csp);
		else if (*spec == 'd' || *spec == 'i' || *spec == 'D')
			print_d(csp);
		else if (*spec == 'f' || *spec == 'F')
			print_f(csp);
		else
			print_other(csp);
	}
	return (csp);
}
