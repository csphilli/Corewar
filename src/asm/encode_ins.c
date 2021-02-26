/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode_ins.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:47:16 by osalmine          #+#    #+#             */
/*   Updated: 2021/02/26 08:00:33 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static uint8_t	parse_reg(char *reg)
{
	uint8_t	reg_nb;

	reg_nb = dec_to_hex(ft_atoi(reg + 1));
	return (reg_nb);
}

static void		parse_dir(t_master *m, char *dir, int t_dir_size, int *mem_i)
{
	uint32_t	dir_nb;

	dir_nb = dec_to_hex(ft_atoi(dir + 1));
	set_bytes(m, \
		split_hex(dir_nb, t_dir_size * 2), \
		t_dir_size, *mem_i);
	*mem_i += t_dir_size;
}

static void		parse_ind(t_master *m, char *ind, int *mem_i)
{
	uint16_t	ind_nb;

	ind_nb = dec_to_hex(ft_atoi(ind));
	set_bytes(m, \
		split_hex(ind_nb, 4), \
		2, *mem_i);
	*mem_i += 2;
}

/*
**	Writes all necessary bytes for the instruction. Writes opcode and
**	possible arg type code and then proceeds to loop through the arguments
*/

static int		write_ins(t_master *m, t_ins *ins, int mem_i)
{
	uint8_t op_code;
	int		i;

	op_code = dec_to_hex(ins->opcode);
	set_a_byte(m, op_code, mem_i++);
	if (ins->arg_type_code == 1)
		set_a_byte(m, calc_arg_type_code(ins), mem_i++);
	i = 0;
	while (i < ins->arg_count)
	{
		if (ins->arg_type[i] == T_REG)
			set_a_byte(m, parse_reg(ins->arg_values[i]), mem_i++);
		else if (ins->arg_type[i] == T_DIR)
			parse_dir(m, ins->arg_values[i], ins->t_dir_size, &mem_i);
		else if (ins->arg_type[i] == T_IND)
			parse_ind(m, ins->arg_values[i], &mem_i);
		i++;
	}
	return (ins->bytes);
}

/*
**	Champ code main encoding funtion. Calls write_ins for every
**	instruction in the list. Also keeps track where on memory to
**	write with mem_i (memory index)
*/

void			encode_ins(t_master *m)
{
	t_node	*tmp;
	int		mem_i;

	tmp = ((t_list*)&m->instrux)->head;
	mem_i = PROG_NAME_LENGTH + COMMENT_LENGTH + 16;
	while (tmp)
	{
		mem_i += write_ins(m, (t_ins*)tmp->data, mem_i);
		tmp = tmp->next;
	}
}
