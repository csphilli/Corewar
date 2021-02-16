/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:46:01 by csphilli          #+#    #+#             */
/*   Updated: 2021/02/16 09:43:17 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_error_line(char *error_msg, int line)
{
	write(2, error_msg, ft_strlen(error_msg));
	ft_putnbr(line);
	write(2, ".\n", 2);
	exit(1);
}

void	label_not_found(char *error_msg, t_ins *node, char *label)
{
	ft_putendl_fd(error_msg, 2);
	ft_putstr_fd("Label '", 2);
	ft_putstr_fd(label, 2);
	ft_putstr_fd("' not found. Error on line ", 2);
	ft_putnbr_fd(node->line, 2);
	write(2, "\n", 1);
	exit(1);
}

void	error_arg_type(t_master *m, char *line)
{
	ft_putstr_fd("ERROR: Invalid arg type \'", 2);
	ft_putstr_fd(line, 2);
	ft_putstr_fd("\' found on line ", 2);
	ft_putnbr_fd(m->line_cnt, 2);
	ft_putendl_fd(".", 2);
	exit(1);
}
