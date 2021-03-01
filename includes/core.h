/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2020/07/16 16:49:28 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include "cop.h"
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <ncurses.h>

typedef struct s_op		t_op;
typedef struct s_game		t_game;
typedef struct s_player		t_player;
typedef struct s_waiter		t_waiter;
typedef struct s_carriage	t_carriage;
typedef struct s_arguments	t_arguments;

struct		s_arguments
{
	int		arg[3];
};

struct		s_op
{
	char	*name;
	int		args;
	int		argtypes[3][3];
	int		opcode;
	int		dur;
	int		acb;
	int		dir_bytes;
};

struct		s_game
{
	int			players;
	t_player	**playerlist;
	int			memory[MEM_SIZE];
	int			last_alive;
	int			lives;
	int			cycles;
	int			cur_cycles;
	int			cycles_to_die;
	int			checks;
	t_carriage	*carriages;
	t_waiter	*waiters;
	int			carr_count;
	int			carrs_alive;
	int			cols[MEM_SIZE];
	int			dump_cycle;
	int			print;
	int			visual;
	int			speed;
	int			coor[MAX_PLAYERS];
};

struct		s_player
{
	char		*argu;
	int			nr;
	char		name[PROG_NAME_LENGTH + 1];
	char		comment[COMMENT_LENGTH + 1];
	int			size;
	int			start;
	int			color;
	int			last_live;
	int			lives;
};

struct		s_carriage
{
	int			nr;
	int			carry;
	int			cur_instr;
	int			last_live_cycle;
	int			wait;
	int			position;
	int			to_next;
	long int	regs[REG_NUMBER];
	int			col;
	t_carriage	*next;
	int			cur_arg;
};

struct		s_waiter
{
	int			position;
	int			wait;
	t_waiter	*next;
};

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
	{"ldi", 3, {{T_REG, T_DIR, T_IND}, {T_DIR, T_REG, 5}, {T_REG, 0, 0}},
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

/*
** core.c
*/

int		init_game(int argc, t_game *game);
int		print_usage(void);
int		announce_winner(t_game *game);
int		main(int argc, char *argv[]);

/*
** core_arg_reader.c
*/

int		arg_error(int error);
int		get_dump(char *arg, t_game *game);
int		check_n_flag_player(char **argv, int i, t_game *game);
int		check_regular_player(char **argv, int i, t_game *game);
int		read_arguments(char **argv, t_game *game);

/*
** core_players.c
*/

int		name(char *arg, unsigned char *buf, t_player *player);
int		comment(char *arg, unsigned char *buf, t_player *player);
int		code(unsigned char *buf, size_t file_size, int player_nr, t_game *game);
int		size(char *arg, unsigned char *buf, t_player *player);
int		get_player(int player_nr, char *arg, t_game *game);

/*
** core_players2.c
*/

int		player_error(char *arg, int error);
int		print_players(t_game *game);
int		replace_regular_players(t_game *game);
int		arrange_players(t_game *game);

/*
** core_carriage.c
*/

void	fill_registries(int i, t_carriage *carr);
int		first_carriages(t_game *game);
int		add_child_carriage(int new_spot, t_carriage *carriage, t_game *game);

/*
** core_play.c
*/

void	read_new_instruction(t_carriage *carriage, t_game *game);
int		handle_instruction(t_carriage *carriage, t_game *game);
int		cycle(t_game *game);
int		play(t_game *game);

/*
** core_code_handler.c
*/

int		bin1(int i);
int		bin2(int i);
int		wrong_arg_type(int instruction, int index, int argument);
int		is_valid_args(int code, t_arguments args, t_carriage *car,\
		t_game *game);
int		check_and_execute_args(int code, t_carriage *car, int pos,\
		t_game *game);

/*
** core_check.c
*/

void	remove_car(t_carriage *last, t_carriage *temp, t_game *game);
void	remove_dead_carriages(t_game *game);
int		reset_player_lives(t_game *game);
int		check(t_game *game);

/*
** core_execute.c
*/

int		execute_2(int code, t_arguments args, t_carriage *carriage,\
		t_game *game);
int		execute_code(int code, t_arguments args, t_carriage *carriage,\
		t_game *game);

/*
** core_tools.c
*/

int		get_four(int position, t_game *game);
int		get_two(int position, t_game *game);
int		move_pos(int steps, int pos);
void	write_to_memory(int value, int pos, t_carriage *carriage, t_game *game);
int		arg_len(int arg_type, int dir_size);

/*
** core_values.c
*/

int		reg_value(int pos, t_carriage *carriage, t_game *game);
int		ind_value(int pos, t_carriage *carriage, t_game *game);
int		ind_value_no_mod(int pos, t_carriage *carriage, t_game *game);
int		get_value(int arg_type, int pos, t_carriage *carriage, t_game *game);

/*
** codes
*/

int		live(t_carriage *carriage, t_game *game);
int		ld(t_arguments args, t_carriage *carriage, t_game *game);
int		st(t_arguments args, t_carriage *carriage, t_game *game);
int		add(t_carriage *carriage, t_game *game);
int		sub(t_carriage *carriage, t_game *game);
int		and(t_arguments args, t_carriage *carriage, t_game *game);
int		or(t_arguments args, t_carriage *carriage, t_game *game);
int		xor(t_arguments args, t_carriage *carriage, t_game *game);
int		zjmp(t_carriage *carriage, t_game *game);
int		ldi(t_arguments args, t_carriage *carriage, t_game *game);
int		sti(t_arguments args, t_carriage *carriage, t_game *game);
int		c_fork(t_carriage *carriage, t_game *game);
int		lld(t_arguments args, t_carriage *carriage, t_game *game);
int		lldi(t_arguments args, t_carriage *carriage, t_game *game);
int		c_lfork(t_carriage *carriage, t_game *game);
int		aff(t_carriage *carriage, t_game *game);

/*
** core_dump.c
*/

int		dump_game(t_game *game);

/*
** n_arena.c
*/

int		n_print_player_name(int row, int col, t_player *player);
void	n_print_players(t_game *game);
void	n_print_arena(t_game *game);
void	print_car(int position, t_game *game);
void	n_draw_arena(t_game *game);

/*
** n_print_update.c
*/

void	n_update_game_stats(t_game *game);
void	n_update_player_stats(t_game *game);
void	n_update_speed_bar(int row, int col, t_game *game);
void	n_update_live_bar(t_game *game);

/*
** n_cases.c
*/

void	n_start_game(t_game *game);
int		n_slow_case(t_game *game);
int		n_fast_case(t_game *game);

/*
** n_end.c
*/

void	n_game_over(int row, int col);
void	n_winner(int row, int col, t_game *game);
void	n_winner_message(int row, int col, t_player *winner);
void	n_end_game(t_game *game);

/*
** n_keys.c
*/

void	n_change_speed (char c, t_game *game);
int		n_pause(t_game *game);
int		n_keys(int c, t_game *game);

/*
** n_wait.c
*/

void	add_waiter(int position, t_game *game);
void	remove_waiter(t_waiter *last, t_waiter *temp, t_game *game);
void	check_waiters(t_game *game);
void	delete_wait(int position, t_game *game);

/*
** n_color.c
*/

void	n_init_color_pairs(void);
void	n_init_colors(t_game *game);
int		set_color2(int i);
int		set_color(int i);

/*
** n_color2.c
*/

int		normal(int done, int pos, t_game *game);
int		live_col(int pos, t_game *game);
int		car_col(int pos, t_game *game);
int		highlight(int pos, t_carriage *carriage, t_game *game);

#endif
