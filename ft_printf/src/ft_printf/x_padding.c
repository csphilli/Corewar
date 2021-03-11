/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_padding.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 10:38:49 by cphillip          #+#    #+#             */
/*   Updated: 2021/03/02 07:36:35 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_struct	*x_padding(t_struct *csp, int m_z, int mod, uintmax_t nbr)
{
	int prec;

	prec = csp->prec;
	if (!nbr)
		csp->padding = csp->width - csp->s_len - m_z;
	else if (csp->c_flags[4] != '0' && prec == -1)
		csp->padding = csp->width - csp->s_len - mod;
	else if (csp->c_flags[4] == '0' && prec != -1 && prec < csp->s_len)
		csp->padding = csp->width - csp->s_len - mod;
	else if (csp->c_flags[4] != '0' && csp->prec != -1)
		csp->padding = csp->width - csp->s_len - mod - m_z;
	else if (csp->c_flags[4] == '0' && prec && prec > csp->s_len)
		csp->padding = csp->width - prec - mod;
	else if (csp->c_flags[4] == '0' && csp->c_flags[0] == '-'\
			&& csp->prec == -1)
		csp->padding = csp->width - csp->s_len - mod - m_z;
	else
		csp->padding = 0;
	return (csp);
}
