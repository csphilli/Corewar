/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_bytecode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 22:23:56 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/26 22:25:22 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	print_name(t_champ *champ) // this is correct. Just need to swap in fd of file
{
	int i;

	i = 0;
	while (champ->prog_name[i])
		write(1, &champ->prog_name[i++], 1);
}


void	print_comment(t_champ *champ) // this is correct. Just need to swap in fd of file
{
	int i;

	i = 0;
	while (champ->comment[i])
		write(1, &champ->comment[i++], 1);
}

void	bytecode_parsing(t_champ *champ)
{
		print_name(champ);
		print_comment(champ);
}