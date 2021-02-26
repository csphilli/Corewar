/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simp_signs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 10:40:59 by csphilli          #+#    #+#             */
/*   Updated: 2021/02/26 08:00:33 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	Helper function for returning the sign based on existing sign.
*/

int		get_sign(char *line)
{
	if (*line == '-' && *(line + 1) == '-')
		return ('+');
	else if (*line == '+' && *(line + 1) == '-')
		return ('-');
	else
		return (*line);
}

/*
**	Prior to final count, this function parses a line and simplies double signs
**	that arise from the conversion of labels. For example, a T_DIR could be
**	nbr1 - :loop and if :loop is negative, it would be nbr1 - -nbr2.
**	This helper function simplies that to nbr1 + nbr2.
*/

void	simplify_signs(char **line)
{
	char	*tmp;
	char	*new;
	int		i;

	tmp = *line;
	new = ft_strnew(ft_strlen(tmp));
	i = 0;
	while (*tmp)
	{
		if ((*tmp == '-' || *tmp == '+') && (*(tmp + 1) &&\
		(*(tmp + 1) == '-' || *(tmp + 1) == '+')))
		{
			new[i] = get_sign(tmp);
			tmp++;
		}
		else
			new[i] = *tmp;
		tmp++;
		i++;
	}
	*line = new;
}

/*
**	A simple check. If nbr_count is greater than 1, there could potentially be
**	signs to simplify. Otherwise, do nothing.
*/

void	simp_signs(char **line)
{
	char	*tmp;
	int		sum;

	sum = 0;
	tmp = NULL;
	if (nbr_count(*line) > 1)
	{
		tmp = *line;
		simplify_signs(&tmp);
		ft_strdel(line);
		*line = tmp;
	}
}
