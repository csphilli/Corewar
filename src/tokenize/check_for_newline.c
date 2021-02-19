/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_newline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:50:12 by osalmine          #+#    #+#             */
/*   Updated: 2021/02/19 12:57:25 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_for_newline(t_master *m)
{
	int		fd2;
	char	newline[10000];
	int		ret;

	fd2 = 0;
	if ((fd2 = open(m->filename, fd2, O_RDONLY)) < 0)
		ft_errorexit("Error on reading input file\n");
	while ((ret = read(fd2, newline, 10000)) > 0)
	{
		if (newline[ret - 1] != '\n')
			ft_errorexit("Syntax error - unexpected end of input \
(Perhaps you forgot to end with a newline ?)\n");
	}
}
