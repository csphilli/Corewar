/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:27:34 by cphillip          #+#    #+#             */
/*   Updated: 2021/03/02 06:31:57 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		ft_nbr_size(intmax_t nbr)
{
	int len;

	if (nbr < 0)
		nbr *= -1;
	len = 1;
	while ((nbr /= 10) > 0)
		len++;
	return (len);
}
