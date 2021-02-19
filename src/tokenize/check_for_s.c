/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 13:03:53 by osalmine          #+#    #+#             */
/*   Updated: 2021/02/19 13:14:20 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_for_filename(char *filename)
{
	if (!filename || ft_strlen(filename) < 2 || \
		!ft_strequ(ft_strchr(filename, '\0') - 2, ".s"))
		ft_errorexit("ERROR: Invalid input file extension\n");
}