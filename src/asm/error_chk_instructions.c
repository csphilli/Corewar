/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_chk_labels.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 19:57:48 by csphilli          #+#    #+#             */
/*   Updated: 2021/03/06 09:35:47 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	chk_single_plus just validates a single '+' in an argument.
*/

void	chk_single_plus(t_ins *ins, int arg)
{
	char	*line;
	int		i;
	int		digit;

	i = 0;
	digit = 0;
	line = ins->arg_values[arg];
	while (line[i])
	{
		if (ft_isdigit(line[i]))
			digit = 1;
		if (!digit && line[i] == '+')
		{
			ft_putstr_fd("ERROR: Invalid '+' on line ", 2);
			ft_putnbr_fd(ins->line, 2);
			ft_putstr_fd(" in instruction \'", 2);
			ft_putstr_fd(ins->orig_arg_values[arg], 2);
			ft_putendl_fd("\'", 2);
			exit(1);
		}
		i++;
	}
}

/*
**	Checks for erroneous and incorrect % placement
*/

void	chk_pcent(t_ins *ins, int arg)
{
	int		i;
	int		cnt;
	char	*line;

	i = 0;
	cnt = 0;
	line = ins->orig_arg_values[arg];
	while (line[i])
	{
		if (line[i] == DIRECT_CHAR)
			cnt++;
		i++;
	}
	if ((ins->arg_type[arg] == T_DIR && (cnt > 1 || (cnt == 1 && \
		line[0] != DIRECT_CHAR))) || (ins->arg_type[arg] == T_IND && \
		cnt > 0))
		ft_error_line("ERROR: Invalid '%' on line ", ins->line);
}

/*
**	Checks for multiple +/- opertions. For example, 5+-5 will error
**	Multiplication and division are not permitted
*/

void	chk_operands(t_ins *ins, int arg)
{
	int		i;
	char	*line;

	i = 0;
	line = ins->orig_arg_values[arg];
	while (line[i])
	{
		if (line[i] == '+' || line[i] == '-')
		{
			if (line[i + 1] && (line[i + 1] == '+' || line[i + 1] == '-'))
				ft_error_line("ERROR: Multiple '+/-' on line ", ins->line);
		}
		else if (line[i] == '/' || line[i] == '*')
			ft_error_line("ERROR: Invalid operand on line ", ins->line);
		i++;
	}
}

void	chk_name_comment_exists(t_champ *champ)
{
	if (!champ->champ_name)
		ft_errorexit("ERROR: Missing champ name!\n");
	else if (!champ->champ_comment)
		ft_errorexit("ERROR: Missing champ comment!\n");
}

/*
**	Parsing function to check multiple errors within instructions.
**	All functions except label_dup_chk are above.
**	label_dup_chk is in the duplicate_label_chk.c file.
*/

void	error_chk_instructions(t_master *m)
{
	t_node	*tmp;
	t_ins	*ins;
	int		i;

	tmp = ((t_list*)&m->instrux)->head;
	chk_name_comment_exists(m->champ);
	label_dup_chk(m);
	while (tmp)
	{
		i = 0;
		ins = node_name_helper(tmp);
		while (i < ins->arg_count)
		{
			if (ins->arg_type[i] == T_DIR || ins->arg_type[i] == T_IND)
			{
				chk_single_plus(ins, i);
				chk_pcent(ins, i);
				chk_operands(ins, i);
			}
			i++;
		}
		tmp = tmp->next;
	}
}
