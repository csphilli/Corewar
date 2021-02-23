/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 10:10:06 by csphilli          #+#    #+#             */
/*   Updated: 2021/02/23 17:42:30 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

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
		if (tmp[i] == COMMENT_CHAR || tmp[i] == ALT_COMMENT_CHAR)
			break ;
		i++;
	}
	*line = new;
}

int		valid_reg_def(char *line)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			cnt++;
		i++;
	}
	if (cnt == 1)
		return (1);
	return (0);
}
