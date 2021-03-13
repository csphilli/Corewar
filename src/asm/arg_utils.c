/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 10:10:06 by csphilli          #+#    #+#             */
/*   Updated: 2021/03/13 19:06:54 by csphilli         ###   ########.fr       */
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

/*
**	validates a T_REG argument
*/

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

/*
**	This check assists with the T_DIR and T_IND checks.
**	If you have a direct or ind char, the validation will
**	first check whether or not the char is a valid LABEL_CHAR.
**	When it hits an invalid char, it moves into check_continuance
**	which tests if the following chars are also valid. The acceptable
**	chars after are defined as +-abcdef0123456789. This acceptance
**	allows for the calculation of hexidecimal after a valid
**	T_DIR or T_IND.
*/

int		check_continuance(char *line)
{
	char	*tmp;

	tmp = line;
	while (*tmp)
	{
		if (!ft_strchr(NON_LABEL_CHARS, ft_tolower(*tmp)))
			return (0);
		tmp++;
	}
	return (1);
}

/*
**	validates a T_DIR argument.
**	check_continuance is above.
*/

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
				if (!check_continuance(line))
					return (0);
			line++;
		}
	}
	else
	{
		while (*line)
		{
			if (!ft_strchr(NON_LABEL_CHARS, ft_tolower(*line)))
				return (0);
			line++;
		}
	}
	return (1);
}

/*
**	validates a T_IND argument
**	check_continuance is above.
*/

int		valid_t_ind(char *line)
{
	if (*line == LABEL_CHAR)
	{
		line++;
		while (*line)
		{
			if (!ft_strchr(LABEL_CHARS, *line))
				if (!check_continuance(line))
					return (0);
			line++;
		}
	}
	else
	{
		while (*line)
		{
			if (!ft_strchr(NON_LABEL_CHARS, ft_tolower(*line)))
				return (0);
			line++;
		}
	}
	return (1);
}
