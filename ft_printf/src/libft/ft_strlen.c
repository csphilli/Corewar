/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 09:54:10 by cphillip          #+#    #+#             */
/*   Updated: 2021/03/02 06:31:57 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	if (!*str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
