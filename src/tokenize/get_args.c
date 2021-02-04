/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 21:47:17 by csphilli          #+#    #+#             */
/*   Updated: 2021/02/04 21:48:41 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		arg_count(char **arg)
{
	int i;

	i = 0;
	while (*arg++)
		i++;
	return (i);
}

void	clean_arg(char **line)
{
	char	*tmp;
	int		leading;
	int		len;

	tmp = ft_strdup(*line);
	ft_strdel(line);
	leading = leading_ws(tmp);
	len = len_sans_trailing_ws(&tmp[leading]);
	*line = ft_strnew(len);
	ft_memcpy(*line, &tmp[leading], sizeof(char) * len);
	ft_strdel(&tmp);
}

int		parse_arg_type(t_asm_oplist oplist, char *line, int arg_nbr)
{
	int i;

	i = 0;
	if (line[i] == REG_CHAR && oplist.arg_type[arg_nbr] & T_REG)
		return (T_REG);
	else if (line[i] == DIRECT_CHAR && oplist.arg_type[arg_nbr] & T_DIR)
		return (T_DIR);
	else if ((ft_strchr(LABEL_CHARS, line[i]) || line[i] == ':' || \
		line[i] == '-') && oplist.arg_type[arg_nbr] & T_IND)
		return (T_IND);
	else
		return (0);
}

int		calc_bytes(t_ins *ins)
{
	int i;
	int	bytes;

	i = 0;
	bytes = 1;
	while (i < ins->arg_count)
	{
		if (ins->arg_type[i] == T_REG)
			bytes += 1;
		else if (ins->arg_type[i] == T_DIR)
			bytes += ins->t_dir_size;
		else if (ins->arg_type[i] == T_IND)
			bytes += 2;
		i++;
	}
	if (ins->arg_type_code)
		bytes += 1;
	return (bytes);
}

void	get_args(t_ins *ins, char *line, t_asm_oplist oplist)
{
	char	**args;
	int		i;

	i = 0;
	args = ft_strsplit(line, SEPARATOR_CHAR);
	if (arg_count(args) != oplist.arg_count)
		ft_error_line("ERROR. Invalid number of arguments in instruction ",\
		ins->index);
	ins->arg_values = ft_memalloc(sizeof(char *) * oplist.arg_count);
	while (args[i])
	{
		clean_arg(&args[i]);
		if ((ins->arg_type[i] = parse_arg_type(oplist, args[i], i)) > 0)
			ins->arg_values[i] = ft_strdup(args[i]);
		else
		{
			printf("Arg line: %s\n", args[i]);
			ft_error_line("ERROR: Invalid argument type for instruction ",\
			ins->index);
		}
		i++;
	}
	ins->bytes = calc_bytes(ins);
	free_strsplit(&args);
}
