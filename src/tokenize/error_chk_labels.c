/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_chk_labels.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 19:57:48 by csphilli          #+#    #+#             */
/*   Updated: 2021/02/19 15:21:14 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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

void	error_chk_labels(t_master *m)
{
	t_node	*tmp;
	t_ins	*ins;
	int		i;

	tmp = ((t_list*)&m->instrux)->head;
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
