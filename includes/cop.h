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

#endif
