/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 17:29:14 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/29 18:25:25 by csphilli         ###   ########.fr       */
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
	char			*champ_name;
	unsigned int	champ_size;
	char			*comment;
	unsigned int	magic;
}					t_champ;

void	 	get_data(t_list *list, t_champ *champ, int fd, char **av);
void		get_name_comment(char **ret, char *line, int fd);
t_node		*get_node_at_index(t_list *list, int index);

#endif