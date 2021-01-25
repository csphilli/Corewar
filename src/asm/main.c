/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:29:34 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/25 15:58:03 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "ll.h"

void	print_list(t_input *input)
{
	printf("[%d]: %s\n", input->index, input->line);
}

t_input 	*get_data(t_list *list, char **av)
{
	int		i;
	int		fd;
	char 	*line;
	t_input *input;

	i = 0;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		input = ft_memalloc(sizeof(t_input));
		input->line = ft_strdup(line);
		input->index = i;
		append_node(list, input);
		ft_strdel(&line);
		i++;
	}
	close(fd);
	return(input);
}

int		get_index(t_input *i, int j)
{
	j = 5; // Just setting which index I want to return
	if (i->index == j)
		return (0);
	else
		return (1);
}

void	asm_parser(t_list *list)
{
	printf(BBLU"printing list in asm parser\n"RESET);
	display_list(list, (t_display)(print_list));
}

int		main(int ac, char **av)
{
	t_list 	list;
	t_input *data;
	t_node *node;

	// data = NULL;
	if (ac == 2)
	{
		init_list(&list);
		data = get_data(&list, av);
		asm_parser(&list);
	}
	else
		ft_handle_error("ERROR. Usage: ./asm [filename.s]\n", 1);

	
	// SAVE THIS FOR REFERENCE! printf has casting to see what value.
	// node = get_node(&list, (int (*)(void*, void*))get_index, data);
	// printf("node: %s\n", ((t_input*)node->data)->line);

	system("leaks asm");
	return (0);
}