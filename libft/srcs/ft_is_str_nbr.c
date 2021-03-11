/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_str_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:26:01 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/16 13:13:29 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_str_num(const char *s1)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s1[i])
	{
		if (ft_isdigit(s1[i]))
			len++;
		i++;
	}
	if (i == len)
		return (1);
	return (0);
}
