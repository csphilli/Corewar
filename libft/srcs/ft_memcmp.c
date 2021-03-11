/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:49:21 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/16 13:13:29 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*ptr1;
	unsigned const char	*ptr2;

	ptr1 = (unsigned const char*)s1;
	ptr2 = (unsigned const char*)s2;
	if (n == 0)
		return (0);
	while (n--)
	{
		if (*ptr1 != *ptr2)
			return ((int)*ptr1 - (int)*ptr2);
		ptr1++;
		ptr2++;
	}
	return (0);
}
