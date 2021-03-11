/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:46:12 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/16 13:13:29 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_revstr(char *str)
{
	char	*tmp;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	if (!(tmp = (char *)malloc(sizeof(len * (char)+1))))
		return (NULL);
	tmp[len] = '\0';
	while (len--)
	{
		tmp[len] = str[i];
		i++;
	}
	return (tmp);
}
