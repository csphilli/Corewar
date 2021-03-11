/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cop.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COP_H
# define COP_H

# define MAX_PLAYERS		4
# define MEM_SIZE		(4*1024)
# define IDX_MOD		(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE		(MEM_SIZE / 6)

# define REG_NUMBER		16

# define CYCLE_TO_DIE		1536
# define CYCLE_DELTA		50
# define NBR_LIVE		21
# define MAX_CHECKS		10

# define T_REG			1
# define T_DIR			2
# define T_IND			3

# define PROG_NAME_LENGTH	128
# define COMMENT_LENGTH		2048
# define COREWAR_EXEC_MAGIC	0xea83f3

typedef	struct		s_op
{
	char	*name;
	int		args;
	int		argtypes[3][3];
	int		opcode;
	int		dur;
	int		acb;
	int		dir_bytes;
}					t_op;

static const t_op	g_op_tab[16] =
{
	{"live", 1, {{T_DIR, 5, 5}, {0, 0, 0}, {0, 0, 0}}, 1, 10, 0, 0},
	{"ld", 2, {{T_DIR, T_IND, 5}, {T_REG, 5, 5}, {0, 0, 0}}, 2, 5, 1, 0},
	{"st", 2, {{T_REG, 5, 5}, {T_IND, T_REG, 5}, {0, 0, 0}}, 3, 5, 1, 0},
	{"add", 3, {{T_REG, 5, 5}, {T_REG, 5, 5}, {T_REG, 5, 5}}, 4, 10, 1, 0},
	{"sub", 3, {{T_REG, 5, 5}, {T_REG, 5, 5}, {T_REG, 5, 5}}, 5, 10, 1, 0},
	{"and", 3, {{T_REG, T_DIR, T_IND}, {T_REG, T_IND, T_DIR}, {T_REG, 5, 5}},
		6, 6, 1, 0},
	{"or", 3, {{T_REG, T_DIR, T_IND}, {T_REG, T_IND, T_DIR}, {T_REG, 5, 5}},
		7, 6, 1, 0},
	{"xor", 3, {{T_REG, T_DIR, T_IND}, {T_REG, T_IND, T_DIR}, {T_REG, 5, 5}},
		8, 6, 1, 0},
	{"zjmp", 1, {{T_DIR, 5, 5}, {0, 0, 0}, {0, 0, 0}}, 9, 20, 0, 1},
	{"ldi", 3, {{T_REG, T_DIR, T_IND}, {T_DIR, T_REG, 5}, {T_REG, 5, 5}},
		10, 25, 1, 1},
	{"sti", 3, {{T_REG, 5, 5 }, {T_REG, T_DIR, T_IND}, {T_DIR, T_REG, 5}},
		11, 25, 1, 1},
	{"fork", 1, {{T_DIR, 5, 5}, {0, 0, 0}, {0, 0, 0}}, 12, 800, 0, 1},
	{"lld", 2, {{T_DIR, T_IND, 5}, {T_REG, 5, 5}, {0, 0, 0}}, 13, 10, 1, 0},
	{"lldi", 3, {{T_REG, T_DIR, T_IND}, {T_DIR, T_REG, 5}, {T_REG, 5, 5}},
		14, 50, 1, 1},
	{"lfork", 1, {{T_DIR, 5, 5}, {0, 0, 0}, {0, 0, 0}}, 15, 1000, 0, 1},
	{"aff", 1, {{T_REG, 5, 5}, {0, 0, 0}, {0, 0, 0}}, 16, 2, 1, 0},
};

#endif
