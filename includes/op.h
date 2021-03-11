/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 15:55:39 by cphillip          #+#    #+#             */
/*   Updated: 2021/03/11 16:30:46 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

# define IND_SIZE           2
# define REG_SIZE           4
# define DIR_SIZE           REG_SIZE
# define REG_CODE           1
# define DIR_CODE           2
# define IND_CODE           3
# define MAX_ARGS_NUMBER    4
# define MAX_PLAYERS        4

/*
**	4 * 1024 = 4096
*/
# define MEM_SIZE			4096

/*
**	MEM_SIZE / 8 = 512
*/
# define IDX_MOD			512

/*
**	MEM_SIZE / 6 = 682
*/
# define CHAMP_MAX_SIZE		682

# define COMMENT_CHAR       '#'
# define ALT_COMMENT_CHAR   ';'
# define LABEL_CHAR         ':'
# define DIRECT_CHAR        '%'
# define REG_CHAR			'r'
# define SEPARATOR_CHAR     ','
# define LABEL_CHARS        "abcdefghijklmnopqrstuvwxyz_0123456789"
# define NON_LABEL_CHARS	"-+abcdefx01234567890"
# define NAME_CMD_STRING    ".name"
# define NAME_CMD_LEN		5
# define COMMENT_CMD_STRING ".comment"
# define COMMENT_CMD_LEN	8
# define REG_NUMBER         16
# define CYCLE_TO_DIE       1536
# define CYCLE_DELTA        50
# define NBR_LIVE           21
# define MAX_CHECKS         10

#endif
