/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 16:55:10 by csphilli          #+#    #+#             */
/*   Updated: 2021/01/31 20:40:49 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	len2_opcodes(char *line, int len, t_list *ins_list)
{
	if (ft_strnstr(line, "ld", len))
		tokenize_ld(line, ins_list);
	else if (ft_strnstr(line, "st", len))
		tokenize_st(line, ins_list);
	else if (ft_strnstr(line, "or", len))
		tokenize_or(line, ins_list);
	else
		printf("Label: %s\n", line);	
}

void	len3_opcodes(char *line, int len, t_list *ins_list)
{
	if (ft_strnstr(line, "add", len))
		tokenize_add(line, ins_list);
	else if (ft_strnstr(line, "sub", len))
		tokenize_sub(line, ins_list);
	else if (ft_strnstr(line, "and", len))
		tokenize_and(line, ins_list);
	else if (ft_strnstr(line, "xor", len))
		tokenize_xor(line, ins_list);
	else if (ft_strnstr(line, "ldi", len))
		tokenize_ldi(line, ins_list);
	else if (ft_strnstr(line, "sti", len))
		tokenize_sti(line, ins_list);
	else if (ft_strnstr(line, "lld", len))
		tokenize_lld(line, ins_list);
	else if (ft_strnstr(line, "aff", len))
		tokenize_aff(line, ins_list);
	else
		printf("Label: %s\n", line);
}

void	len4_opcodes(char *line, int len, t_list *ins_list)
{
	if (ft_strnstr(line, "live", len))
		tokenize_live(line, ins_list);
	else if (ft_strnstr(line, "zjmp", len))
		tokenize_zjmp(line, ins_list);
	else if (ft_strnstr(line, "fork", len))
		tokenize_fork(line, ins_list);
	else if (ft_strnstr(line, "lldi", len))
		tokenize_lldi(line, ins_list);
	else
		printf("Label: %s\n", line);
}

void	len5_opcodes(char *line, int len, t_list *ins_list)
{
	if (ft_strnstr(line, "lfork", len))
		tokenize_lfork(line, ins_list);
	else
		printf("Label: %s\n", line);
}

void	tokenizing(char *line, t_list *ins_list)
{
	int len;
	int	i;

	i = 0;
	len = 0;
    if (!line || line[0] == 0 || line[0] == '#' || line[0] == ALT_COMMENT_CHAR)
	{
        printf("EMPTY LINE/COMMENT\n"); // set to return
		return ;
	}
	len = opcode_len(line);
	if (len == 2)
		len2_opcodes(line, len, ins_list);
	else if (len == 3)
		len3_opcodes(line, len, ins_list);
	else if (len == 4)
		len4_opcodes(line, len, ins_list);
	else if (len == 5)
		len5_opcodes(line, len, ins_list);
	else
		printf("Label: %s\n", line);
}