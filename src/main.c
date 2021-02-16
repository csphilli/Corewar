/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:29:34 by cphillip          #+#    #+#             */
/*   Updated: 2021/02/16 15:34:22 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	Initializes the master struct.
**	init_list is part of the library functions and can be found in
**	libft/srcs/ft_lstfuncs.c file
*/

void	init_master(t_master *m)
{
	m->champ = ft_memalloc(sizeof(t_champ));
	m->champ->champ_name = NULL;
	m->champ->champ_comment = NULL;
	m->ins_count = 0;
	m->line_cnt = 0;
	init_list(&m->instrux);
	init_list(&m->labels);
}

/*
**	In the event that the last line contains a label but no
**	instruction tied to the label, it still needs to be added
**	to the list of instructions so that other labels referring to
**	it can be converted to the number of bytes to the label. So it'll
**	just have a blank instruction set.
*/

void	leftover_labels(t_master *m)
{
	t_ins *ins;

	ins = ft_memalloc(sizeof(t_ins));
	add_labels(m, ins);
	ins->index = m->ins_count;
	ins->line = m->line_cnt - 1;
	append_node(&m->instrux, ins);
}

int		main(int ac, char **av)
{
	t_master	*m;
	int			fd;

	fd = 0;
	if (ac == 2)
	{
		m = ft_memalloc(sizeof(t_master));
		m->filename = av[1];
		fd = open(m->filename, fd, O_RDONLY);
		init_master(m);
		get_data(m, fd);
		if (((t_list*)&m->labels)->head)
			leftover_labels(m);
		handle_labels(m);
		encode_asm(m);
		write_to_file(m);
		// printf("NAME: >%s<\nCOMMENT: >%s<\n", m->champ->champ_name,\
		// 	m->champ->champ_comment);
		// display_list(&m->instrux, (t_display)(print_instrux_list)); // not needed once asm complete.
	}
	else
		ft_error("Error. Usage: ./asm [filename.s]\n");
	// system("leaks asm"); // Leaks checker
	return (0);
}
