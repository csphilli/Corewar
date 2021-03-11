/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 11:40:26 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/16 13:13:29 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(uintmax_t nbr, int base)
{
	char	*new;
	int		j;

	j = ft_nbr_size_base(nbr, base);
	if (!(new = (char*)malloc(sizeof(char) * j + 1)))
		return (NULL);
	if (nbr < 0)
		new[0] = '-';
	new[j] = '\0';
	while (j--)
	{
		new[j] = (nbr % base < 10) ? nbr % base + '0' : nbr % base + 'a' - 10;
		nbr /= base;
	}
	return (new);
}
