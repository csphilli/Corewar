/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_calcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 21:49:33 by csphilli          #+#    #+#             */
/*   Updated: 2021/02/16 23:13:33 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		calc_nbrs(int n1, int n2, t_func f)
{
	return (f(n1, n2));
}

void	parse_nbrs(char *line)
{
	t_func	*f;
	int		sign;

	sign = '+';
	

}

void	label_calcs(t_master *m)
{
	t_node	*tmp;
	t_ins	*ins;
	int		i;

	tmp = ((t_list*)&m->instrux)->head;
	while (tmp)
	{
		ins = node_name_helper(tmp);
		i = 0;
		while (i < ins->arg_count)
		{
			if (ins->arg_type[i] == T_DIR || ins->arg_type[i] == T_IND)
				parse_nbrs(ins->arg_values[i]);
			i++;
		}
		tmp = tmp->next;
	}
}