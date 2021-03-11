/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_uintmax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 10:35:30 by cphillip          #+#    #+#             */
/*   Updated: 2021/03/02 06:42:29 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_itoa_uintmax(uintmax_t n)
{
	char			*new;
	int				len;

	len = ft_intlen_max(n) + 1;
	if (!(new = ft_strnew(len + 1)))
		return (NULL);
	new[len] = '\0';
	len--;
	while (n >= 10)
	{
		new[--len] = (char)(n % 10 + '0');
		n /= 10;
	}
	new[--len] = (char)(n + '0');
	return (new);
}
