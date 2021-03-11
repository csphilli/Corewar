/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 09:37:37 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/16 13:13:29 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(const char *s, char c)
{
	int		i;
	int		j;
	char	**new;

	i = 0;
	j = 0;
	if (!s || (!(new = (char **)malloc(sizeof(char *) * (ft_nbw(s, c) + 1)))))
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			if (!(new[j] = (char *)malloc(sizeof(char) * (ft_lword(s, c) + 1))))
				return (NULL);
			while (*s && *s != c)
				new[j][i++] = (char)*s++;
			new[j][i] = '\0';
			j++;
			i = 0;
		}
	}
	new[j] = NULL;
	return (new);
}
