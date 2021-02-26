/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 20:47:10 by csphilli          #+#    #+#             */
/*   Updated: 2021/02/26 08:00:33 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

// printf needs to be removed!

void	print_arg_type(int id)
{
	if (id == T_REG)
		printf("\t%-20s", "T_REG");
	else if (id == T_DIR)
		printf("\t%-20s", "T_DIR");
	else if (id == T_LAB)
		printf("\t%-20s", "T_LAB");
	else
		printf(BRED"\t%-20s"RESET, "T_IND");
}

void	print_ins_labels(t_labels *labels)
{
	printf("\t%s\n", labels->label);
}

void	print_instrux_list(t_ins *ins)
{
	int		i;
	t_node	*labels;

	i = 0;
	labels = ((t_list*)&ins->labels)->head;
	printf(BGRN"----- INSTRUCTION %d -----\n"RESET, ins->index + 1);
	printf("\tLabel(s):\n");
	display_list(&ins->labels, (t_display)(print_ins_labels));
	printf("\tOpcode: %d\n\tOpname: %s\n", ins->opcode, ins->opname);
	printf("\tBytes: %d\n", ins->bytes);
	printf("\tArgCnt: %d\n\tt_dir_size: %d\n\targ_type_code: %d\n", \
		ins->arg_count, ins->t_dir_size, ins->arg_type_code);
	printf("\tLine: %d\n", ins->line);
	printf(GRN"\tARGUMENTS\n"RESET);
	printf("\t%-20s%-20s%-20s\n", "TYPE", "VALUE", "ORIG VALUE");
	while (i < ins->arg_count)
	{
		print_arg_type(ins->arg_type[i]);
		printf("%-20s%-20s\n", ins->arg_values[i], ins->orig_arg_values[i]);
		i++;
	}
	write(1, "\n", 1);
}
