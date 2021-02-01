/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 20:47:10 by csphilli          #+#    #+#             */
/*   Updated: 2021/02/01 20:57:13 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	print_instrux_list(t_ins *ins)
{
	printf(BGRN"----- INDEX %d -----\n"RESET, ins->index);
	printf(" Label: %s\n Opcode: %d\n Opname: %s\n", \
		ins->label, ins->opcode, ins->opname);
	printf(" ArgCnt: %d\n t_dir_size: %d\n arg_type_code: %d\n\n", \
		ins->arg_count, ins->t_dir_size, ins->arg_type_code);
}
