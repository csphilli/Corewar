/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 10:23:50 by cphillip          #+#    #+#             */
/*   Updated: 2021/03/02 06:37:41 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static long double	rounding(long double nbr, int prec)
{
	long double rounding;
	int			i;

	i = 0;
	rounding = 0.5;
	if (nbr < 0)
		rounding *= -1;
	while (i++ < prec)
		rounding /= 10.0;
	return (rounding);
}

static char			*joining(char *whole, char *dec_part)
{
	char *joint;

	joint = ft_strjoin(whole, dec_part);
	free(whole);
	free(dec_part);
	return (joint);
}

char				*ft_ftoa(long double nbr, int prec, char dot)
{
	char				*joint;
	char				*whole;
	char				*dec_part;
	unsigned long long	dec;
	int					i;

	i = 0;
	prec = prec == -1 ? 6 : prec;
	nbr += prec >= 0 ? rounding(nbr, prec) : 0;
	nbr < 0 ? nbr *= -1 : nbr * 1;
	whole = ft_itoa_uintmax(nbr);
	dec = nbr;
	nbr = prec > 0 ? nbr - dec : 0;
	dec_part = ft_strnew(prec + 1);
	dec_part[i++] = (dot && prec > 0) ? '.' : '\0';
	while (prec-- > 0)
	{
		nbr *= 10;
		dec = nbr;
		nbr -= dec;
		dec_part[i++] = dec + '0';
	}
	joint = joining(whole, dec_part);
	return (joint);
}
