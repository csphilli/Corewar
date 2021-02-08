/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:29:34 by cphillip          #+#    #+#             */
/*   Updated: 2021/02/08 14:29:52 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	init_master(t_master *m)
{
	m->champ = ft_memalloc(sizeof(t_champ));
	m->champ->champ_name = NULL;
	m->champ->champ_comment = NULL;
	m->champ->magic = 15369203;
	m->ins_count = 0;
	m->line_cnt = 0;
	init_list(&m->instrux);
	init_list(&m->labels);
}

void	leftover_labels(t_master *m)
{
	t_ins *ins;

	ins = ft_memalloc(sizeof(t_ins));
	add_labels(m, ins);
	append_node(&m->instrux, ins);
}

int		main(int ac, char **av)
{
	t_master	*m;
	int			fd;

	fd = 0;
	if (ac == 2)
	{
		fd = open(av[1], fd, O_RDONLY);
		m = ft_memalloc(sizeof(t_master));
		init_master(m);
		get_data(m, fd);
		if (((t_list*)&m->labels)->head)
			leftover_labels(m);
		handle_labels(m);
		display_list(&m->instrux, (t_display)(print_instrux_list));
	}
	else
		ft_error("Error. Usage: ./asm [filename.s]\n");
	system("leaks asm");
	return (0);
}
