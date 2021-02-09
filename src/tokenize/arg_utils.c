/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 10:10:06 by csphilli          #+#    #+#             */
/*   Updated: 2021/02/09 08:55:27 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	Used as a helper function to get_args in the get_args.c file. This removes
**	whitespace between the arguments prior to ft_strsplit.
**	If the argument was sti r1, % : label, %1, the result would be
**	sti r1,%:label,%1
*/

void	pre_split(char **line)
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
