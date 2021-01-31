/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_statement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 16:55:10 by csphilli          #+#    #+#             */
/*   Updated: 2021/01/31 18:38:25 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		opcode_len(char *line)
{
	int len;

	len = 0;
	while (line[len] != ' ' && line[len] != '\t' && \
			line[len] != '\n' && line[len] != '\0')
		len++;
	return (len);
}

void	len2_opcodes(char *line, int len)
{
	if (ft_strnstr(line, "ld", len))
		printf(RED"ld\n"RESET);
	else if (ft_strnstr(line, "st", len))
		printf(RED"st\n"RESET);
	else if (ft_strnstr(line, "or", len))
		printf(RED"or\n"RESET);
	else
		printf("Label len2\n");
	
}

void	len3_opcodes(char *line, int len)
{
	if (ft_strnstr(line, "add", len))
		printf(RED"add\n"RESET);
	else if (ft_strnstr(line, "sub", len))
		printf(RED"sub\n"RESET);
	else if (ft_strnstr(line, "and", len))
		printf(RED"and\n"RESET);
	else if (ft_strnstr(line, "xor", len))
		printf(RED"xor\n"RESET);
	else if (ft_strnstr(line, "ldi", len))
		printf(RED"ldi\n"RESET);
	else if (ft_strnstr(line, "sti", len))
		printf(RED"sti\n"RESET);
	else if (ft_strnstr(line, "lld", len))
		printf(RED"lld\n"RESET);
	else if (ft_strnstr(line, "aff", len))
		printf(RED"aff\n"RESET);
	else
		printf("Label len3\n");
}

void	len4_opcodes(char *line, int len)
{
	if (ft_strnstr(line, "live", len))
		printf(RED"live\n"RESET);
	else if (ft_strnstr(line, "zjmp", len))
		printf(RED"zjmp\n"RESET);
	else if (ft_strnstr(line, "fork", len))
		printf(RED"fork\n"RESET);
	else if (ft_strnstr(line, "lldi", len))
		printf(RED"lldi\n"RESET);
	else
		printf("Label Len4\n");
}

void	len5_opcodes(char *line, int len)
{
	if (ft_strnstr(line, "lfork", len))
		printf(RED"lfork\n"RESET);
	else
		printf("Label Len5\n");
}

void	analyse_statement(char *line)
{
	int len;
	int	i;

	i = 0;
	len = 0;
    if (!line || line[0] == 0 || line[0] == '#' || line[0] == ALT_COMMENT_CHAR)
	{
        printf("Found emptyline/comment/alt comment char\n"); // set to return
		return ;
	}
	printf("line: %s\n", line);
	len = opcode_len(line);
	if (len == 2)
		len2_opcodes(line, len);
	else if (len == 3)
		len3_opcodes(line, len);
	else if (len == 4)
		len4_opcodes(line, len);
	else if (len == 5)
		len5_opcodes(line, len);
	else
		printf("probably a label\n");
}