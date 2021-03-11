/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 10:30:26 by cphillip          #+#    #+#             */
/*   Updated: 2021/03/02 07:33:59 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		ft_intlen_max(uintmax_t nbr)
{
	int len;

	if (nbr < 0)
		nbr *= -1;
	len = 1;
	while ((nbr /= 10) > 0)
		len++;
	return (len);
}
