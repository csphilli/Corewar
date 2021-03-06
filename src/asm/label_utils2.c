/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:58:00 by csphilli          #+#    #+#             */
/*   Updated: 2021/03/24 12:12:03 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	Similar to ft_strcat, this simply cats a char to a string
*/

char	*ft_charcat(char *dest, const char src)
{
	int			i;
	size_t		dest_l;

	i = 0;
	dest_l = ft_strlen(dest);
	dest[dest_l + i] = src;
	dest[dest_l + i + 1] = '\0';
	return ((char *)dest);
}

/*
**	Counts to the end of a label and returns the amount of moves. - 1 because
**	it will initially exceed the end of the label.
*/

int		end_of_label(char *line)
{
	int	i;

	i = 1;
	while (line[i] != '\n' && line[i] != '\0' && \
			ft_strchr(LABEL_CHARS, line[i]))
		i++;
	return (i - 1);
}

/*
**	Gets the label from the line.
*/

char	*extract_label(char *line)
{
	int		i;
	char	*str;

	i = 0;
	while (*line && !ft_strchr(LABEL_CHARS, *line))
		line++;
	while (line[i] && ft_strchr(LABEL_CHARS, line[i]))
		i++;
	str = ft_strndup(line, i);
	return (str);
}

/*
**	After the final count, mod_atoi omits the DIRECT_CHAR. This function
**	simply adds it back.
*/

void	add_label_char_back(t_ins *ins, int i, char **src)
{
	char	*new;

	if (ins->arg_type[i] == T_DIR && !ft_strchr(*src, '%'))
	{
		new = ft_strnew(ft_strlen(*src) + 1);
		new[0] = DIRECT_CHAR;
		ft_strcat(new, *src);
		ft_strdel(src);
		*src = new;
	}
}
