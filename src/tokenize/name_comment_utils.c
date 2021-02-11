/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_comment_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:49:14 by csphilli          #+#    #+#             */
/*   Updated: 2021/02/11 14:55:17 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	Helper function for trailing_quote in get_name_comment.c file.
**	Parses line to identify if there is additional characters after the
**	closing quote of a name/comment. Returns 1 if so, otherwise 0.
*/

int		extraneous(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\"')
		i++;
	i++;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] == ' ' || line[i] == '\t')
			i++;
		else
			return (1);
	}
	return (0);
}
