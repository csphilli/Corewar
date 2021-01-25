/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 17:29:14 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/25 19:24:05 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"
#include <stdio.h> // remove before submission

typedef struct 		s_input
{
	int				index;
	char 			*line;
}					t_input;

typedef struct		s_champ
{
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
	unsigned int	magic;
}					t_champ;

t_input 	*get_data(t_list *list, char **av);
int			get_name(t_list *list, t_champ *champ, int i);
#endif