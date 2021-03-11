/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 18:33:46 by cphillip          #+#    #+#             */
/*   Updated: 2021/03/02 07:36:35 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_struct	*csp;

	if (!(csp = (t_struct*)malloc(sizeof(t_struct))))
		return (-1);
	csp->fmt = format;
	csp = initialize(csp);
	if (format)
	{
		va_start(csp->args, format);
		csp->len = parse(csp);
		va_end(csp->args);
	}
	free(csp);
	return (csp->len);
}
