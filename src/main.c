/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:29:34 by cphillip          #+#    #+#             */
/*   Updated: 2021/02/08 12:28:50 by csphilli         ###   ########.fr       */
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
	m->line_cnt = 1;
	init_list(&m->instrux);
	init_list(&m->labels);
}

int		main(int ac, char **av)
{
	t_master	*master;
	int			fd;

	fd = 0;
	if (ac == 2)
	{
		fd = open(av[1], fd, O_RDONLY);
		master = ft_memalloc(sizeof(t_master));
		init_master(master);
		get_data(master, fd);
		handle_labels(master);
		display_list(&master->instrux, (t_display)(print_instrux_list));
	}
	else
		ft_error("ERROR. Usage: ./asm [filename.s]\n");
	system("leaks asm");
	return (0);
}
