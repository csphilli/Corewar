/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrstrcmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:20:49 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/16 13:13:29 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrstrcmp(const char *s1, const char *s2)
{
	int i;
	int	n_s1;
	int	n_s2;

	i = 0;
	n_s1 = 0;
	n_s2 = 0;
	if (!ft_is_str_num(s1) || !ft_is_str_num(s2))
	{
		while (s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0'))
			i++;
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	else if (ft_is_str_num(s1) && ft_is_str_num(s2))
	{
		n_s1 = atoi(s1);
		n_s2 = atoi(s2);
		return (n_s1 - n_s2);
	}
	return (0);
}
