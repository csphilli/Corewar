/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:17:02 by cphillip          #+#    #+#             */
/*   Updated: 2021/03/02 06:31:57 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_strndup(char *str, int size)
{
	char	*new;
	int		i;

	i = 0;
	if (!(new = ft_strnew(size)))
		return (NULL);
	while (str && i < size)
	{
		new[i] = str[i];
		i++;
	}
	return (new);
}
