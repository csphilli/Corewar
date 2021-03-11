/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:51:59 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/16 13:13:29 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	char	*new;

	if (!(s))
		return (0);
	start = 0;
	end = ft_strlen(s);
	while (ft_isspace(s[start]))
		start++;
	while (ft_isspace(s[end - 1]))
		end--;
	if (end < start)
		end = start;
	if (!(new = ft_strnew(end - start)))
		return (NULL);
	return (ft_strncpy(new, s + start, end - start));
}
