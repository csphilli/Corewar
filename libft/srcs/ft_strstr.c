/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:22:40 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/16 13:13:29 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystk, const char *needle)
{
	int pos;
	int i;

	i = 0;
	pos = 0;
	if (!*needle)
		return ((char *)haystk);
	while (haystk[pos])
	{
		i = 0;
		if (needle[i] == haystk[pos + i])
		{
			while (needle[i] == haystk[pos + i] && needle[i] != '\0')
			{
				i++;
				if (needle[i] == '\0')
					return ((char *)&haystk[pos]);
			}
		}
		pos++;
	}
	return (NULL);
}
