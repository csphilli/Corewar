/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:58:00 by csphilli          #+#    #+#             */
/*   Updated: 2021/02/15 14:11:35 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*ft_charcat(char *dest, const char src)
{
	int			i;
	size_t		dest_l;

	i = 0;
	dest_l = strlen(dest);
	dest[dest_l + i] = src;
	dest[dest_l + i + 1] = '\0';
	return ((char *)dest);
}

int		end_of_label(char *line)
{
	int	i;

	i = 1;
	while (line[i] != '\n' && line[i] != '\0' && \
			ft_strchr(LABEL_CHARS, line[i]))
		i++;
	return (i - 1);
}

char	*extract_label(char *line)
{
	int		i;
	char	*str;

	i = 0;
	while (!ft_strchr(LABEL_CHARS, *line))
		line++;
	while (ft_strchr(LABEL_CHARS, line[i]))
		i++;
	str = ft_strndup(line, i);
	return (str);
}

/*
**	Converts a label into a numeric label. For example, %:label could be
**	%-15.
*/

char	*new_str_from_label(t_ins *node, int arg_nbr, char *bytes)
{
	int		len;
	char	*new;

	len = 0;
	if (node->arg_values[arg_nbr])
		ft_strdel(&node->arg_values[arg_nbr]);
	if (node->arg_type[arg_nbr] == T_DIR)
		len++;
	len += ft_strlen(bytes);
	new = ft_strnew(len);
	if (node->arg_type[arg_nbr] == T_DIR)
		new[0] = '%';
	ft_strcat(new, bytes);
	return (new);
}
