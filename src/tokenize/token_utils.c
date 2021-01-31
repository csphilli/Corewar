/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 20:39:12 by csphilli          #+#    #+#             */
/*   Updated: 2021/01/31 20:40:36 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		opcode_len(char *line)
{
	int len;

	len = 0;
	while (line[len] != ' ' && line[len] != '\t' && \
			line[len] != '\n' && line[len] != '\0')
		len++;
	return (len);
}
