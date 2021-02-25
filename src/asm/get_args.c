/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 21:47:17 by csphilli          #+#    #+#             */
/*   Updated: 2021/02/25 21:29:58 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

/*
**	Counts the number of arguments in a given instruction.
*/

int		arg_count(char *line, int max_count)
{
	int cnt;
	int	sep;

	cnt = 0;
	sep = 0;
	if (*line && *line != SEPARATOR_CHAR)
	{
		cnt++;
		line++;
	}
	while (*line)
	{
		while (*line == SEPARATOR_CHAR)
		{
			line++;
			sep++;
			if (*line && *line != SEPARATOR_CHAR)
				cnt++;
		}
		line++;
	}
	if (cnt == max_count && sep == cnt - 1)
		return (1);
	return (0);
}

/*
**	Cleans up the argument so a strsplit can be done without including
**	leading or trailing whitespaces. Also removes trailing comments.
*/

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

/*
**	Parses the instruction given and identifies which argument it is.
**	Also validates that the specific argument can be utilized for the
**	respective argument number in the instruction and type.
**	valid_reg_def is in arg_utils.c
*/

int		parse_arg_type(t_asm_oplist oplist, \
		char *line, int arg_nbr)
{
	int i;
	int	nbr;

	i = 0;
	if (line[i] == REG_CHAR && oplist.arg_type[arg_nbr] & T_REG)
	{
		nbr = ft_atoi(&line[1]);
		if (nbr >= 0 && nbr <= 99 && valid_reg_def(line))
			return (T_REG);
		else
			return (0);
	}
	else if (line[i] == DIRECT_CHAR && oplist.arg_type[arg_nbr] & T_DIR &&\
				valid_t_dir(line))
		return (T_DIR);
	else if (valid_t_ind(line) && oplist.arg_type[arg_nbr] & T_IND)
		return (T_IND);
	else
		return (0);
}

/*
**	Calculates the total number of bytes a specific instruction
**	will have.
*/

int		calc_statement_bytes(t_ins *ins)
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

/*
**	Parses a statement and adds the args to the t_ins instruction node.
**	Helper function locations are listed where. Descriptions of what they do are
**	above the function.
**	pre_split is found in the arg_utils.c file.
**	arg_count is above.
**	parse_arg_type is above.
**	error_arg_type found in the errors.c file
**	calc_statement_bytes is above.
*/

void	get_args(t_master *m, t_ins *ins, char *line, t_asm_oplist oplist)
{
	char	**args;
	int		i;
	char	*tmp;

	i = 0;
	tmp = line;
	pre_split(&tmp);
	args = ft_strsplit(tmp, SEPARATOR_CHAR);
	if (!arg_count(tmp, oplist.arg_count))
		ft_error_line("ERROR: Invalid number of arguments on line ",\
		m->line_cnt);
	ins->arg_values = ft_memalloc(sizeof(char *) * oplist.arg_count);
	while (args[i])
	{
		clean_arg(&args[i]);
		if ((ins->arg_type[i] = parse_arg_type(oplist, args[i], i)) > 0)
			ins->arg_values[i] = ft_strdup(args[i]);
		else
			error_arg_type(m, args[i]);
		i++;
	}
	ins->bytes = calc_statement_bytes(ins);
	free_strsplit(&args);
	ft_strdel(&tmp);
}
