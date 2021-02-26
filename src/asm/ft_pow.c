/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 13:21:08 by csphilli          #+#    #+#             */
/*   Updated: 2021/02/26 08:00:33 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	ft_pow(int n, int exp)
{
	int y;

	y = 0;
	if (n > 0 && exp >= 0)
	{
		if (exp == 0)
			return (1);
		else if (exp % 2 == 0)
		{
			y = ft_pow(n, exp / 2);
			return (y * y);
		}
		else
			return (n * ft_pow(n, exp - 1));
	}
	return (0);
}
