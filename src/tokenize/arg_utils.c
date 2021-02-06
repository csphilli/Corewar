/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 10:10:06 by csphilli          #+#    #+#             */
/*   Updated: 2021/02/06 10:11:10 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	pre_split(t_ins *ins, char **line)
{
	char	*tmp;
	char	*new;
	int		i;
	int		j;

	tmp = *line;
	new = ft_strnew(ft_strlen(tmp));
	i = 0;
	j = 0;
	while (tmp[i])
	{
		if (tmp[i] != ' ' && tmp[i] != '\t')
		{
			new[j] = tmp[i];
			j++;
		}
		i++;
	}
	*line = new;
}
