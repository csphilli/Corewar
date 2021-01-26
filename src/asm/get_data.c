/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:32:36 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/26 09:25:52 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*capture(char *input)
{
	int		len;
	char	*ret;

	len = ft_strlen(input);
	ret = ft_strnew(len + 1);
	ft_strncpy(ret, input, len);
	ft_strcat(ret, "\n");
	return (ret);
}

t_input	*get_data(t_list *list, char **av)
{
	int		i;
	int		fd;
	char	*line;
	t_input *input;

	i = 0;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		input = ft_memalloc(sizeof(t_input));
		input->line = capture(line);
		input->index = i;
		append_node(list, input);
		ft_strdel(&line);
		i++;
	}
	close(fd);
	return (input);
}
