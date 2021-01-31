/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:29:34 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/31 19:24:07 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "ll.h"

void	print_list(t_input *input)
{
	printf("[%d]: %s", input->index, input->line);
}

int		get_index(t_input *i, int j)
{
	j = 5; // Just setting which index I want to return
	if (i->index == j)
		return (0);
	else
		return (1);
}


void	init_champ(t_champ *champ)
{
	// if (!(champ = (t_champ*)ft_memalloc(sizeof(t_champ))))
	// 	ft_error("ERROR: Failed to allocate memory for champ struct.\n");
	champ->champ_name = NULL;
	champ->comment = NULL;
	champ->magic = 15369203;
	
}

int		main(int ac, char **av)
{
	t_list 	list;
	t_champ champ;	

	int		fd;
	fd = 0;
	if (ac == 2)
	{
		fd = open(av[1], fd, O_RDONLY);
		init_list(&list);
		init_champ(&champ);
		get_data(&champ, fd);
	}
	else
		ft_error("ERROR. Usage: ./asm [filename.s]\n");

	// system("leaks asm");
	// SAVE THIS FOR REFERENCE! printf has casting to see what value.
	// node = get_node(&list, (int (*)(void*, void*))get_index, data);
	// printf("node: %s\n", ((t_input*)node->data)->line);

	// system("leaks asm");
	return (0);
}