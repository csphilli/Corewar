/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 20:47:10 by csphilli          #+#    #+#             */
/*   Updated: 2021/02/04 21:45:12 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	arg_type(int id)
{
	if (id == T_REG)
		printf("T_REG");
	else if (id == T_DIR)
		printf("T_DIR");
	else if (id == T_LAB)
		printf("T_LAB");
	else
		printf(BRED"T_IND"RESET);
}

void	print_instrux_list(t_ins *ins)
{
	int i;

	i = 0;
	printf(BGRN"----- INSTRUCTION %d -----\n"RESET, ins->index);
	printf("\tLabel: %s\n\tOpcode: %d\n\tOpname: %s\n", \
		ins->label, ins->opcode, ins->opname);
	printf("\tBytes: %d\n", ins->bytes);
	printf("\tArgCnt: %d\n\tt_dir_size: %d\n\targ_type_code: %d\n", \
		ins->arg_count, ins->t_dir_size, ins->arg_type_code);
	printf(GRN"\tARGUMENTS\n"RESET);
	printf("\tTYPE\tVALUE\n");
	while (i < ins->arg_count)
	{
		printf("\t");
		arg_type(ins->arg_type[i]);
		printf("\t%s\n", ins->arg_values[i]);
		i++;
	}
	printf("\n");
}
