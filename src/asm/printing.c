/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 20:47:10 by csphilli          #+#    #+#             */
/*   Updated: 2021/03/11 12:01:35 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	print_arg_type(int id)
{
	if (id == T_REG)
		ft_printf("\t%-20s", "T_REG");
	else if (id == T_DIR)
		ft_printf("\t%-20s", "T_DIR");
	else if (id == T_LAB)
		ft_printf("\t%-20s", "T_LAB");
	else
		ft_printf(BRED"\t%-20s"RESET, "T_IND");
}

void	print_ins_labels(t_labels *labels)
{
	ft_printf("\t%s\n", labels->label);
}

void	print_instrux_list(t_ins *ins)
{
	int		i;
	t_node	*labels;

	i = 0;
	labels = ((t_list*)&ins->labels)->head;
	ft_printf(BGRN"----- INSTRUCTION %d -----\n"RESET, ins->index + 1);
	ft_printf("\tLabel(s):\n");
	display_list(&ins->labels, (t_display)(print_ins_labels));
	ft_printf("\tOpcode: %d\n\tOpname: %s\n", ins->opcode, ins->opname);
	ft_printf("\tBytes: %d\n", ins->bytes);
	ft_printf("\tArgCnt: %d\n\tt_dir_size: %d\n\targ_type_code: %d\n", \
		ins->arg_count, ins->t_dir_size, ins->arg_type_code);
	ft_printf("\tLine: %d\n", ins->line);
	ft_printf(BMAG"\tARGUMENTS\n"RESET);
	ft_printf("\t%-20s%-20s%-20s\n", "TYPE", "VALUE", "ORIG VALUE");
	while (i < ins->arg_count)
	{
		print_arg_type(ins->arg_type[i]);
		ft_printf("%-20s%-20s\n", ins->arg_values[i], ins->orig_arg_values[i]);
		i++;
	}
	write(1, "\n", 1);
}

/*
**	Basic debugger which will print out champ name and comment and all
**	instructions with respective information.
**	NOTE! The flag of this is manual so just change to 1 to enable. Didn't
**	want to include flag parsing in this program simply for this.
*/

void	debug(t_master *m)
{
	int	debug_flag;

	debug_flag = 0;
	if (debug_flag == 1)
	{
		ft_printf("NAME: >%s<\nCOMMENT: >%s<\n", m->champ->champ_name,\
			m->champ->champ_comment);
		display_list(&m->instrux, (t_display)(print_instrux_list));
		system("leaks asm");
	}
}
