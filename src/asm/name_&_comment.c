/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_&_comment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 11:48:11 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/10 13:00:21 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_int_arr(int **arr, int size)
{
	ft_memset(*arr, '\0', sizeof(int) * size);
	free(*arr);
	*arr = NULL;
}

void	name_to_byte(char **src, char *name)
{
	int		*int_value;

	str_to_int_str(&int_value, name, PROG_NAME_LENGTH);
	*src = to_hex(int_value, PROG_NAME_LENGTH);
	free_int_arr(&int_value, PROG_NAME_LENGTH);
}

void	comment_to_byte(char **src, char *name_comment)
{
	int	*int_value;

	str_to_int_str(&int_value, name_comment, COMMENT_LENGTH);
	*src = to_hex(int_value, COMMENT_LENGTH);
	free_int_arr(&int_value, COMMENT_LENGTH);
}
