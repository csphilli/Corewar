/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:29:34 by cphillip          #+#    #+#             */
/*   Updated: 2021/02/04 16:05:08 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "ll.h"

/*
**	For reference later
**	node = get_node(&list, (int (*)(void*, void*))get_index, data);
**	printf("node: %s\n", ((t_input*)node->data)->line);
*/

void	init_master(t_master *m)
{
	m->champ = ft_memalloc(sizeof(t_champ));
	m->champ->champ_name = NULL;
	m->champ->champ_comment = NULL;
	m->label = NULL;
	m->champ->magic = 15369203;
	m->ins_count = 1;
	init_list(&m->list);
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
		display_list(&master->list, (t_display)(print_instrux_list));
	}
	else
		ft_error("ERROR. Usage: ./asm [filename.s]\n");
	system("leaks asm");
	return (0);
}
