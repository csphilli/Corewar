/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:08:21 by cphillip          #+#    #+#             */
/*   Updated: 2021/03/02 07:36:35 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_struct	*print_s(t_struct *csp)
{
	char	*tmp;
	int		s_len;

	tmp = va_arg(csp->args, char *);
	if (csp->prec == -1 && tmp)
		tmp = ft_strdup(tmp);
	else if (csp->prec == -1 && !tmp)
		tmp = ft_strdup("(null)");
	else if (csp->prec > -1 && tmp)
		tmp = ft_strndup(tmp, csp->prec);
	else if (csp->prec > -1 && !tmp)
		tmp = ft_strndup("(null)", csp->prec);
	s_len = ft_strlen(tmp);
	if (csp->c_flags[0] != '-' && csp->c_flags[4] == '0')
		print_alt(csp, csp->width - s_len, '0');
	else if (csp->c_flags[0] != '-')
		print_alt(csp, csp->width - s_len, ' ');
	ft_putstr(tmp);
	if (csp->c_flags[0] == '-')
		print_alt(csp, csp->width - s_len, ' ');
	csp->len += ft_strlen(tmp);
	free(tmp);
	return (csp);
}
