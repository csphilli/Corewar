/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 17:29:14 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/10 13:05:35 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"
#include <stdio.h> // remove before submission

/*
**	NAME & COMMENT CONVERSION TO BYTE CODE
*/

void	name_to_byte(char **src, char *name);
void	comment_to_byte(char **src, char *name_comment);

/*
**	BYTE CONVERSION TOOLS
*/

char	*to_hex(int *int_str, int max_len);
void	str_to_int_str(int **src, char *input, int max_len);
#endif