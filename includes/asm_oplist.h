/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_oplist.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 11:12:56 by csphilli          #+#    #+#             */
/*   Updated: 2021/02/01 16:32:11 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_OPLIST_H
# define ASM_OPLIST_H

# define T_REG					    1
# define T_DIR					    2
# define T_IND					    4
# define T_LAB					    8

typedef struct	s_asm_oplist
{
	int		opcode;
	char	*opname;
	int		arg_count;
	int		arg_type[3];
	int		t_dir_size;
	int		arg_type_code;

}				t_asm_oplist;

static const	t_asm_oplist	g_oplist[16] = {
	{
		.opcode = 0x01,
		.opname = "live",
		.arg_count = 1,
		.arg_type = {T_DIR, 0, 0},
		.t_dir_size = 4,
		.arg_type_code = 0
	},
	{
		.opcode = 0x02,
		.opname = "ld",
		.arg_count = 2,
		.arg_type = {T_DIR | T_IND, T_REG, 0},
		.t_dir_size = 4,
		.arg_type_code = 1
	},
	{
		.opcode = 0x03,
		.opname = "st",
		.arg_count = 2,
		.arg_type = {T_REG, T_REG | T_IND, 0},
		.t_dir_size = 4,
		.arg_type_code = 1
	},
	{
		.opcode = 0x04,
		.opname = "add",
		.arg_count = 3,
		.arg_type = {T_REG, T_REG, T_REG},
		.t_dir_size = 4,
		.arg_type_code = 1
	},
	{
		.opcode = 0x05,
		.opname = "sub",
		.arg_count = 3,
		.arg_type = {T_REG, T_REG, T_REG},
		.t_dir_size = 4,
		.arg_type_code = 1
	},
	{
		.opcode = 0x06,
		.opname = "and",
		.arg_count = 3,
		.arg_type = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.t_dir_size = 4,
		.arg_type_code = 1
	},
	{
		.opcode = 0x07,
		.opname = "or",
		.arg_count = 3,
		.arg_type = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.t_dir_size = 4,
		.arg_type_code = 1
	},
	{
		.opcode = 0x08,
		.opname = "xor",
		.arg_count = 3,
		.arg_type = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.t_dir_size = 4,
		.arg_type_code = 1
	},
	{
		.opcode = 0x09,
		.opname = "zjmp",
		.arg_count = 1,
		.arg_type = {T_DIR, 0, 0},
		.t_dir_size = 2,
		.arg_type_code = 0
	},
	{
		.opcode = 0x0a,
		.opname = "ldi",
		.arg_count = 3,
		.arg_type = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.t_dir_size = 2,
		.arg_type_code = 1
	},
	{
		.opcode = 0x0b,
		.opname = "sti",
		.arg_count = 3,
		.arg_type = {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR},
		.t_dir_size = 2,
		.arg_type_code = 1
	},
	{
		.opcode = 0x0c,
		.opname = "fork",
		.arg_count = 1,
		.arg_type = {T_DIR, 0, 0},
		.t_dir_size = 2,
		.arg_type_code = 0
	},
	{
		.opcode = 0x0d,
		.opname = "lld",
		.arg_count = 2,
		.arg_type = {T_DIR | T_IND, T_REG, 0},
		.t_dir_size = 4,
		.arg_type_code = 1
	},
	{
		.opcode = 0x0e,
		.opname = "lldi",
		.arg_count = 3,
		.arg_type = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.t_dir_size = 2,
		.arg_type_code = 1
	},
	{
		.opcode = 0x0f,
		.opname = "lfork",
		.arg_count = 1,
		.arg_type = {T_DIR, 0, 0},
		.t_dir_size = 2,
		.arg_type_code = 0
	},
	{
		.opcode = 0x10,
		.opname = "aff",
		.arg_count = 1,
		.arg_type = {T_REG, 0, 0},
		.t_dir_size = 4,
		.arg_type_code = 1
	}
};

#endif
