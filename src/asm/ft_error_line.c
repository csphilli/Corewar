/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:46:01 by csphilli          #+#    #+#             */
/*   Updated: 2021/02/02 11:48:28 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_error_line(char *error_msg, int line)
{
	write(2, error_msg, ft_strlen(error_msg));
	ft_putnbr(line);
	write(2, ".\n", 2);
	exit(0);
}
