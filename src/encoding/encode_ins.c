/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode_ins.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:47:16 by osalmine          #+#    #+#             */
/*   Updated: 2021/02/15 22:43:07 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static uint8_t	calc_arg_type_code(t_ins *ins)
{
	uint8_t	arg_type_code;
	int				i;
	int				bit_multiplier;

	arg_type_code = 0x0;
	i = 0;
	bit_multiplier = 7;
	while (i < ins->arg_count)
	{
		if (ins->arg_type[i] == T_REG)
		{
			bit_multiplier--;
			arg_type_code |= 1UL << bit_multiplier;
			bit_multiplier--;
		}
		else if (ins->arg_type[i] == T_DIR)
		{
			arg_type_code |= 1UL << bit_multiplier;
			bit_multiplier -= 2;
		}
		else if (ins->arg_type[i] == T_IND)
		{
			arg_type_code |= 1UL << bit_multiplier;
			bit_multiplier--;
			arg_type_code |= 1UL << bit_multiplier;
			bit_multiplier--;
		}	
		i++;
	}
	return (arg_type_code);
}

static uint8_t	parse_reg(char *reg)
{
	uint8_t	reg_nb;

	// printf("\nPARSE REG\n");
	// reg_nb = 0x0;
	// printf("atoi from reg: %d\n", ft_atoi(reg + 1));
	reg_nb = dec_to_hex(ft_atoi(reg + 1));
	// printf("reg_nb: %#x\n", reg_nb);
	return (reg_nb);
}

static void		parse_dir(t_master *m, char *dir, int t_dir_size, int *mem_i)
{
	uint32_t	dir_nb;

	// printf("\n%sPARSE_DIR%s\n", MAG, RESET);
	// printf("dec_to_hex: %d: %#x\n", -260, dec_to_hex(-260));
	dir_nb = dec_to_hex(ft_atoi(dir + 1));
	// printf("dir_nb: %#x, dec: %d, t_dir_size: %d\n", dir_nb, ft_atoi(dir + 1), t_dir_size);
	set_bytes(m, \
		split_hex(dir_nb, t_dir_size * 2), \
		t_dir_size, *mem_i);
	*mem_i += t_dir_size;
}

static void		parse_ind(t_master *m, char *ind, int *mem_i)
{
	uint16_t	ind_nb;

	// printf("\n%sPARSE_IND%s\n", MAG, RESET);
	// printf("dec_to_hex: %d: %#x\n", -260, dec_to_hex(-260));
	ind_nb = dec_to_hex(ft_atoi(ind));
	// printf("ind input str: %s, ind_nb: %#x, ind: %d\n", ind, ind_nb, ft_atoi(ind));
	set_bytes(m, \
		split_hex(ind_nb, 4), \
		2, *mem_i);
	*mem_i += 2;
}

static int		write_ins(t_master *m, t_ins *ins, int mem_i)
{
	uint8_t op_code;
	int		i;

	op_code = dec_to_hex(ins->opcode);
	// printf("\n%sNEW INSTRUCTION%s\nmem_i: %d, %#x, opcode: %#x, dec_to_hex: %#x, len: %d\n", YEL, RESET, mem_i, mem_i, ins->opcode, dec_to_hex(ins->opcode), ft_nbr_size_base(dec_to_hex(ins->opcode), 16));
	set_a_byte(m, op_code, mem_i++);
	if (ins->arg_type_code == 1)
		set_a_byte(m, calc_arg_type_code(ins), mem_i++);
	i = 0;
	while (i < ins->arg_count)
	{
		// printf("MEM_I BEF: %d, %#x\n", mem_i, mem_i);
		if (ins->arg_type[i] == T_REG)
			set_a_byte(m, parse_reg(ins->arg_values[i]), mem_i++);
		else if (ins->arg_type[i] == T_DIR)
			parse_dir(m, ins->arg_values[i], ins->t_dir_size, &mem_i);
		else if (ins->arg_type[i] == T_IND)
			parse_ind(m, ins->arg_values[i], &mem_i);
		// printf("MEM_I AFT: %d, %#x\n", mem_i, mem_i);
		i++;
	}
	return (ins->bytes);
}

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