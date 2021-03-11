/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 19:51:44 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/15 19:54:29 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_handle_error(char *error_msg, int exit_code)
{
	write(2, error_msg, ft_strlen(error_msg));
	if (exit_code == 1)
		exit(-1);
}
