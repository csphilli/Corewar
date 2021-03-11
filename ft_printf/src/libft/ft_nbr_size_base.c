/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_size_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:48:28 by cphillip          #+#    #+#             */
/*   Updated: 2021/03/02 06:42:38 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		ft_nbr_size_base(uintmax_t nbr, int base)
{
	int	len;

	len = 0;
	len += (nbr < 0);
	while (nbr)
	{
		nbr /= base;
		len++;
	}
	return (len);
}
