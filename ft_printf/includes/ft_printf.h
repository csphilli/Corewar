/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 09:44:30 by cphillip          #+#    #+#             */
/*   Updated: 2021/03/02 08:28:24 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <ctype.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <wchar.h>

typedef struct	s_struct
{
	const char	*fmt;
	char		*c_fmt;
	char		*srch_fmt;
	va_list		args;
	size_t		i;
	int			len;
	int			padding;
	char		specifier;
	long int	width;
	int			s_len;
	long int	prec;
	char		len_flags[3];
	char		c_flags[6];
	char		*hex_chars;
	char		*format_flags;
	char		*a_flags;
	char		*spec_flags;
	char		get_plus;
}				t_struct;

long double		get_float(t_struct *csp);
intmax_t		get_d_nbr(t_struct *csp);
uintmax_t		get_oux_nbr(t_struct *csp);
void			handle_max(t_struct *csp);
t_struct		*print_pcent(t_struct *csp);
t_struct		*print_alt(t_struct *csp, int amount, int c);
void			print_other(t_struct *csp);
t_struct		*chk_conv_flags(t_struct *csp);
t_struct		*initialize(t_struct *csp);
t_struct		*re_init(t_struct *csp);
t_struct		*chk_width(t_struct *csp);
t_struct		*chk_precision(t_struct *csp);
t_struct		*chk_arg_flags(t_struct *csp);
t_struct		*chk_specifier(t_struct *csp);
t_struct		*staging(t_struct *csp);
t_struct		*print_c(t_struct *csp);
t_struct		*print_s(t_struct *csp);
t_struct		*print_p(t_struct *csp);
t_struct		*print_x(t_struct *csp);
t_struct		*print_o(t_struct *csp);
t_struct		*print_u(t_struct *csp);
t_struct		*print_d(t_struct *csp);
t_struct		*print_f(t_struct *csp);
t_struct		*x_padding(t_struct *csp, int m_z, int mod, uintmax_t nbr);
int				ft_printf(const char *format, ...);
int				parse(t_struct *csp);
t_struct		*pre_staging(t_struct *csp);
t_struct		*get_padding(t_struct *csp, long int s_len);
int				update_len(t_struct *csp, int s_len);
t_struct		*print_zero(t_struct *csp, char spec, uintmax_t nbr);
int				chk_is_valid(t_struct *csp);
void			do_max();

/*
**	LIBRARY FUNCS
*/

char			*ft_ftoa(long double nbr, int prec, char dot);
int				ft_isdigit(int c);
char			*ft_itoa_base(uintmax_t nbr, int base);
void			*ft_memset(void *b, int c, size_t len);
int				ft_nbr_size(intmax_t nbr);
void			ft_putchar(char c);
void			ft_putnbrmax(intmax_t nbr);
void			ft_putstr(char const *str);
void			ft_s_toupper(char *str);
char			*ft_strchr(const char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *str);
char			*ft_strndup(char *str, int size);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_bzero(void *s, size_t n);
char			*ft_itoa_uintmax(uintmax_t n);
char			*ft_strnew(size_t size);
void			*ft_memalloc(size_t size);
int				ft_nbr_size_base(uintmax_t nbr, int base);
int				ft_isalpha(int c);
int				ft_toupper(int c);
int				ft_intlen_max(uintmax_t nbr);

#endif
