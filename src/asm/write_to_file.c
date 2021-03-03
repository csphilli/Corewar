/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 18:28:07 by osalmine          #+#    #+#             */
/*   Updated: 2021/03/02 14:50:56 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	Search for the old file extension and replaces it with new_extension
*/

static char	*file_extension_swap(char *filename, char *old, char *new_extension)
{
	char	*new_file;
	char	*base;

	if (ft_strstr(filename, old))
		base = ft_strsub(filename, 0, ft_strlen(filename) - ft_strlen(old));
	else
		base = ft_strdup(filename);
	new_file = ft_strjoin(base, new_extension);
	ft_strdel(&base);
	return (new_file);
}

static void	write_to_bytecode(char *bytes, t_master *m)
{
	int	i;

	i = 0;
	while (i < m->encoded_player_size)
	{
		bytes[i] = m->encoded_player[i];
		i++;
	}
}

static char	*convert_to_bytecode(t_master *m)
{
	char	*bytecode;

	if (!(bytecode = ft_strnew((size_t)m->encoded_player_size)))
		ft_errorexit("ERROR: Malloc error");
	ft_bzero(bytecode, m->encoded_player_size);
	write_to_bytecode(bytecode, m);
	return (bytecode);
}

void		write_to_file(t_master *m)
{
	int		fd;
	char	*new_file;
	char	*bytecode;

	new_file = file_extension_swap(m->filename, ".s", ".cor");
	bytecode = convert_to_bytecode(m);
	if (!(fd = open(new_file, O_WRONLY | O_CREAT | O_TRUNC, 0644)))
		ft_errorexit("Error creating a new file\n");
	write(fd, bytecode, m->encoded_player_size);
	ft_putstr_fd("Writing output program to ", 1);
	ft_putstr_fd(new_file, 1);
	write(1, "\n", 2);
	ft_strdel(&new_file);
	ft_strdel(&bytecode);
}
