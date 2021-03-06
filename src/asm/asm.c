/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:29:34 by cphillip          #+#    #+#             */
/*   Updated: 2021/03/06 09:27:24 by csphilli         ###   ########.fr       */
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
	m->encoded_player = NULL;
	m->encoded_player_size = 0;
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
	ins->line = m->line_cnt;
	append_node(&m->instrux, ins);
}

int		main(int ac, char **av)
{
	t_master	*m;
	int			fd;

	fd = 0;
	if (ac == 2)
	{
		ft_printf("FILE: %s\n", av[1]); // using for testing
		m = ft_memalloc(sizeof(t_master));
		m->filename = av[1];
		check_for_filename(m->filename);
		if ((fd = open(m->filename, fd, O_RDONLY)) < 0)
			ft_errorexit("ERROR: Cannot read from input file.\n");
		init_master(m);
		get_data(m, fd);
		if (((t_list*)&m->labels)->head)
			leftover_labels(m);
		handle_labels(m);
		error_chk_instructions(m);
		label_calcs(m);
		encode_asm(m);
		write_to_file(m);
		debug(m);
	}
	else
		ft_error("Error. Usage: ./asm [filename.s]\n");
	return (0);
}
