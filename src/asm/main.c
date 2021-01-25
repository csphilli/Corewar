/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:29:34 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/25 20:25:54 by cphillip         ###   ########.fr       */
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

void	asm_parser(t_list *list, t_champ *champ)
{
	int	i;

	i = 0;
	i = get_name(list, champ, i);
	printf(BBLU"printing list in asm parser\n"RESET);
	display_list(list, (t_display)(print_list));
}

void	init_champ(t_champ *champ)
{
	champ->magic = 15369203;
}

int		main(int ac, char **av)
{
	t_list 	list;
	t_champ champ;
	t_input *data;
	// t_node *node;

	// data = NULL;
	if (ac == 2)
	{
		init_list(&list);
		init_champ(&champ);
		data = get_data(&list, av);
		asm_parser(&list, &champ);
	}
	else
		ft_handle_error("ERROR. Usage: ./asm [filename.s]\n", 1);

	
	// SAVE THIS FOR REFERENCE! printf has casting to see what value.
	// node = get_node(&list, (int (*)(void*, void*))get_index, data);
	// printf("node: %s\n", ((t_input*)node->data)->line);

	system("leaks asm");
	return (0);
}