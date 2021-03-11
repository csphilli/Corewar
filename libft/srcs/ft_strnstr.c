/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:47:14 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/16 13:13:29 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *ndl, size_t len)
{
	int		pos;
	size_t	i;

	i = 0;
	pos = 0;
	if (!*ndl)
		return ((char *)hay);
	while (hay[pos] && len)
	{
		i = 0;
		if (ndl[i] == hay[pos + i])
		{
			while (ndl[i] == hay[pos + i] && i < len)
			{
				i++;
				if (ndl[i] == '\0')
					return ((char *)&hay[pos]);
			}
		}
		pos++;
		len--;
	}
	return (NULL);
}
