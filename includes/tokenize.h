/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 19:46:03 by csphilli          #+#    #+#             */
/*   Updated: 2021/01/31 20:40:26 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
# define TOKENIZE_H

void	tokenizing(char *line, t_list *ins_list);
int		opcode_len(char *line);

void	tokenize_sti(char *line, t_list *ins_list);
void	tokenize_live(char *line, t_list *ins_list);
void	tokenize_ld(char *line, t_list *ins_list);
void	tokenize_st(char *line, t_list *ins_list);
void	tokenize_or(char *line, t_list *ins_list);
void	tokenize_sub(char *line, t_list *ins_list);
void	tokenize_add(char *line, t_list *ins_list);
void	tokenize_and(char *line, t_list *ins_list);
void	tokenize_xor(char *line, t_list *ins_list);
void	tokenize_ldi(char *line, t_list *ins_list);
void	tokenize_lld(char *line, t_list *ins_list);
void	tokenize_aff(char *line, t_list *ins_list);
void	tokenize_zjmp(char *line, t_list *ins_list);
void	tokenize_fork(char *line, t_list *ins_list);
void	tokenize_lldi(char *line, t_list *ins_list);
void	tokenize_lfork(char *line, t_list *ins_list);

#endif

