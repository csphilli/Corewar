/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_calc_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 22:27:45 by csphilli          #+#    #+#             */
/*   Updated: 2021/02/16 22:59:48 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		add(int n1, int n2)
{
	return (n1 + n2);
}

int		sub(int n1, int n2)
{
	return (n1 - n2);
}

t_func	get_operation(int sign)
{
	int	i;

	i = 0;
	while (i < N_OPERANDS)
	{
		if (g_func_list[i].sign == sign)
			return (g_func_list[i].f);
		i++;
	}
	return (NULL);
}