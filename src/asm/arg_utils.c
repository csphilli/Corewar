/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 10:10:06 by csphilli          #+#    #+#             */
/*   Updated: 2021/02/26 08:00:33 by csphilli         ###   ########.fr       */
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
		if (tmp[i] != ' ' && tmp[i] != '\t' && tmp[i] != COMMENT_CHAR &&\
			tmp[i] != ALT_COMMENT_CHAR)
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

int		valid_t_dir(char *line)
{
	if (*(line + 1) == '\0')
		return (0);
	line++;
	if (*line == LABEL_CHAR)
	{
		line++;
		while (*line)
		{
			if (!ft_strchr(LABEL_CHARS, *line))
				return (0);
			line++;
		}
	}
	else
	{
		while (*line)
		{
			if (!ft_strchr(NON_LABEL_CHARS, *line))
				return (0);
			line++;
		}
	}
	return (1);
}

int		valid_t_ind(char *line)
{
	if (*line == LABEL_CHAR)
	{
		line++;
		while (*line)
		{
			if (!ft_strchr(LABEL_CHARS, *line))
				return (0);
			line++;
		}
	}
	else
	{
		while (*line)
		{
			if (!ft_strchr(NON_LABEL_CHARS, *line))
				return (0);
			line++;
		}
	}
	return (1);
}
