/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_arg_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:19:53 by osalmine          #+#    #+#             */
/*   Updated: 2021/02/23 16:50:08 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

static void	calc_reg(int *bit_multiplier, uint8_t *arg_type_code)
{
	(*bit_multiplier)--;
	*arg_type_code |= 1UL << *bit_multiplier;
	(*bit_multiplier)--;
}

static void	calc_dir(int *bit_multiplier, uint8_t *arg_type_code)
{
	*arg_type_code |= 1UL << *bit_multiplier;
	*bit_multiplier -= 2;
}

static void	calc_ind(int *bit_multiplier, uint8_t *arg_type_code)
{
	*arg_type_code |= 1UL << *bit_multiplier;
	(*bit_multiplier)--;
	*arg_type_code |= 1UL << *bit_multiplier;
	(*bit_multiplier)--;
}

/*
**	Calculates the arg_type_code number if needed.
**	T_REG:	01
**	T_DIR:	10
**	T_IND:	11
**	arg_type_code |= 1UL << bit_multiplier
**	sets an individual bit to the bit_multiplier place (<< 0 is the first bit)
*/

uint8_t		calc_arg_type_code(t_ins *ins)
{
	uint8_t	arg_type_code;
	int		i;
	int		bit_multiplier;

	arg_type_code = 0x0;
	i = 0;
	bit_multiplier = 7;
	while (i < ins->arg_count)
	{
		if (ins->arg_type[i] == T_REG)
			calc_reg(&bit_multiplier, &arg_type_code);
		else if (ins->arg_type[i] == T_DIR)
			calc_dir(&bit_multiplier, &arg_type_code);
		else if (ins->arg_type[i] == T_IND)
			calc_ind(&bit_multiplier, &arg_type_code);
		i++;
	}
	return (arg_type_code);
}
