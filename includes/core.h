/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:41:17 by laskolin          #+#    #+#             */
/*   Updated: 2021/03/11 16:38:00 by osalmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include "cop.h"
# include "../libft/includes/libft.h"
# include "../ft_printf/includes/ft_printf.h"
# include <unistd.h>
# include <ncurses.h>

typedef struct s_n_writer	t_n_writer;
typedef struct s_n_coor		t_n_coor;
typedef struct s_game		t_game;
typedef struct s_player		t_player;
typedef struct s_waiter		t_waiter;
typedef struct s_carriage	t_carriage;
typedef struct s_arguments	t_arguments;

struct		s_n_writer
{
	int		cur;
	int		len;
	int		rows;
};

struct		s_n_coor
{
	int		row;
	int		col;
};

struct		s_arguments
{
	int		arg[3];
};

struct		s_game
{
	int			players;
	t_player	*playerlist[MAX_PLAYERS * 2];
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
	int			aff;
	int			live_print;
	int			visual;
	int			speed;
	int			coor[MAX_PLAYERS];
};

struct		s_player
{
	char		*argu;
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
	int			pc;
	int			to_next;
	long int	regs[REG_NUMBER];
	int			col;
	t_carriage	*next;
};

struct		s_waiter
{
	int			position;
	int			wait;
	t_waiter	*next;
};

/*
** core.c
*/

int			init_game(int argc, t_game *game);
int			print_usage(void);
int			announce_winner(t_game *game);
int			main(int argc, char *argv[]);

/*
** core_arg_reader.c
*/

int			arg_error(int error, t_game *game);
int			check_n_flag_player(char **argv, int i, t_game *game);
int			check_regular_player(char **argv, int i, t_game *game);
int			read_arguments(char **argv, t_game *game);

/*
** core_flags.c
*/
int			get_dump_flag(char *arg, t_game *game);
int			get_print_flag(int i, t_game *game);
int			get_aff_flag(int i, t_game *game);
int			get_no_live_print_flag(int i, t_game *game);
int			get_visual_flag(int i, t_game *game);

/*
** core_players.c
*/

int			name(char *arg, unsigned char *buf, int nr, t_game *game);
int			comment(char *arg, unsigned char *buf, t_player *player,
			t_game *game);
int			code(unsigned char *buf, size_t file_size, int pl_nr, t_game *game);
int			size(unsigned char *buf, t_player *player);
int			get_player(int player_nr, char *arg, t_game *game);

/*
** core_players2.c
*/

int			check_size(char *arg, int code_length, t_player *player,
			t_game *game);
int			player_error(char *arg, int error, t_game *game);
int			print_players(t_game *game);
int			compress_playerlist(t_game *game);
int			arrange_players(t_game *game);

/*
** core_carriage.c
*/

void		fill_registries(int i, t_carriage *carr);
int			first_carriages(t_game *game);
int			add_child_carriage(int new_spot, t_carriage *old_car, t_game *game);

/*
** core_play.c
*/

void		read_new_instruction(t_carriage *carriage, t_game *game);
int			handle_instruction(t_carriage *carriage, t_game *game);
int			cycle(t_game *game);
int			play(t_game *game);

/*
** core_code_handler.c
*/

int			bin1(int i);
int			bin2(int i);
int			wrong_arg_type(int instruction, int index, int argument);
int			is_valid_args(int code, t_arguments args, t_carriage *car,\
			t_game *game);
int			check_and_execute_args(int code, t_carriage *car, int pos,\
			t_game *game);

/*
** core_check.c
*/

void		remove_car(t_carriage *last, t_carriage *temp, t_game *game);
void		remove_dead_carriages(t_game *game);
int			reset_player_lives(t_game *game);
int			check(t_game *game);

/*
** core_execute.c
*/

int			execute_2(int code, t_arguments args, t_carriage *carriage,\
			t_game *game);
int			execute_code(int code, t_arguments args, t_carriage *carriage,\
			t_game *game);

/*
** core_tools.c
*/

int			get_four(int position, t_game *game);
int			get_two(int position, t_game *game);
int			move_pos(int steps, int pos);
void		write_to_memory(int value, int pos, t_carriage *car, t_game *game);
int			arg_len(int arg_type, int dir_size);

/*
** core_values.c
*/

int			reg_value(int pos, t_carriage *carriage, t_game *game);
int			ind_value(int pos, t_carriage *carriage, t_game *game);
int			ind_value_no_mod(int pos, t_carriage *car, t_game *game);
int			get_value(int arg_type, int pos, t_carriage *car, t_game *game);

/*
** codes
*/

int			live(t_carriage *carriage, t_game *game);
int			ld(t_arguments args, t_carriage *carriage, t_game *game);
int			st(t_arguments args, t_carriage *carriage, t_game *game);
int			add(t_carriage *carriage, t_game *game);
int			sub(t_carriage *carriage, t_game *game);
int			and(t_arguments args, t_carriage *carriage, t_game *game);
int			or(t_arguments args, t_carriage *carriage, t_game *game);
int			xor(t_arguments args, t_carriage *carriage, t_game *game);
int			zjmp(t_carriage *carriage, t_game *game);
int			ldi(t_arguments args, t_carriage *carriage, t_game *game);
int			sti(t_arguments args, t_carriage *carriage, t_game *game);
int			c_fork(t_carriage *carriage, t_game *game);
int			lld(t_arguments args, t_carriage *carriage, t_game *game);
int			lldi(t_arguments args, t_carriage *carriage, t_game *game);
int			c_lfork(t_carriage *carriage, t_game *game);
int			aff(t_carriage *carriage, t_game *game);

/*
** core_dump.c
*/

void		dump_game_and_exit(t_game *game);
int			end_too_large(t_game *game);
void		free_players(t_game *game);
int			free_all_and_exit(int state, t_game *game);

/*
** n_arena.c
*/

int			n_print_player_name(int row, int col, t_player *player);
void		n_print_players(t_game *game);
void		n_print_arena(t_game *game);
void		print_car(int position, t_game *game);
void		n_draw_arena(t_game *game);

/*
** n_print_update.c
*/

void		n_update_game_stats(t_game *game);
void		n_update_player_stats(t_game *game);
void		n_update_speed_bar(int row, int col, t_game *game);
void		n_update_live_bar(t_game *game);

/*
** n_cases.c
*/

void		n_start_game(t_game *game);
int			n_slow_case(t_game *game);
int			n_fast_case(t_game *game);
t_n_writer	n_print_box2(char *str, t_n_writer writer);
int			print_box(t_n_coor spot, int size, int speed, char *str);

/*
** n_end.c
*/

void		n_game_over(int row, int col, int realend);
int			n_winner(int realend, int row, int col, t_game *game);
void		n_winner_message(int row, int col, t_player *winner);
void		n_end_game(int realend, t_game *game);

/*
** n_keys.c
*/

void		n_change_speed (char c, t_game *game);
int			n_pause(t_game *game);
int			n_keys(int c, t_game *game);

/*
** n_wait.c
*/

void		add_waiter(int position, t_game *game);
void		remove_waiter(t_waiter *last, t_waiter *temp, t_game *game);
void		check_waiters(t_game *game);
void		delete_wait(int position, t_game *game);

/*
** n_color.c
*/

void		n_init_color_pairs(void);
void		n_init_colors(t_game *game);
int			set_color2(int i);
int			set_color(int i);

/*
** n_color2.c
*/

int			normal(int done, int pos, t_game *game);
int			live_col(int pos, t_game *game);
int			car_col(int pos, t_game *game);
int			highlight(int pos, t_carriage *carriage, t_game *game);

#endif
