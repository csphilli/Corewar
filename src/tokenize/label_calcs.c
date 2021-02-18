/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_calcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 21:49:33 by csphilli          #+#    #+#             */
/*   Updated: 2021/02/18 14:38:56 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	Identifies whether or not there is a hex string present in the current
**	line.
*/

int		hex_in_str(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_isalpha(line[i]))
			return (1);
		i++;
	}
	return (0);
}

/*
**	The only change from the original atoi function is that a double pointer
**	is used to keep track of the last known spot in the conversion.
*/

int		mod_atoi(char *str, char **end_ptr)
{
	int	i;
	int	sign;
	int	res;
	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	*end_ptr = &str[i];
	return (res * sign);
}

/*
**	Returns the number of numbers in a string based on signs.
*/

int		nbr_count(char *s)
{
	int	c;

	c = 0;
	if (*s != '-' && *s != '+' && *s)
	{
		s++;
		c++;
	}
	while (*s)
	{
		while (*s == '-' || *s == '+')
		{
			s++;
			if (*s != '-' && *s != '+' && *s)
				c++;
		}
		s++;
	}
	return (c);
}

/*
**	After all conversions (labels & hex strings) have been done, this
**	calculates the final sum. The real beauty here is using a pointer
**	to continuously keep tabs on the last spot in the string. The string
**	continues to loop through summing all numbers using mod_atoi above. You can
**	use += because mod_atoi will apply the sign anyways.
*/

void	final_count(t_ins *ins, int arg, char **line)
{
	int		sum;
	char	*end;
	char	*tmp;

	sum = 0;
	if (nbr_count(*line) > 1)
	{
		tmp = *line;
		end = tmp;
		if (*tmp == '%')
			tmp++;
		while (*tmp)
		{
			sum += mod_atoi(tmp, &end);
			tmp = end;
		}
		ft_strdel(line);
		*line = ft_itoa(sum);
		add_label_char_back(ins, arg, line);
	}
}

/*
**	A parser to loop through all arguments in each instruction. If the
**	instruction has either T_DIR or T_IND values, a conversion takes place.
**	First, double signs are simplified to single signs. Then all hex strings
**	are converted provided the string has one. Then the final count
**	is carried out.
*/

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
			{
				printf("before signs: %s\n", ins->arg_values[i]);
				simp_signs(&ins->arg_values[i]);
				printf("after signs: %s\n", ins->arg_values[i]);
				if (hex_in_str(ins->arg_values[i]))
					convert_hex(ins, &ins->arg_values[i]);
				// printf("argument prior to work: %s\n", ins->arg_values[i]);
				final_count(ins, i, &ins->arg_values[i]);
			}
			i++;
		}
		tmp = tmp->next;
	}
}
