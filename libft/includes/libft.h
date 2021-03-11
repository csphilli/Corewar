/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:37:29 by cphillip          #+#    #+#             */
/*   Updated: 2021/02/05 20:34:52 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 1000
# define BUFF_SIZE_GNL 1000
# define FD_SIZE 1000

# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/types.h>
# include <fcntl.h>
# include <unistd.h>
# include "colors.h"
# include "ll.h"

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystk, const char *needle);
char				*ft_strnstr(const char *hay, const char *ndl, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
intmax_t			ft_atoimax(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **str);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
void				free_strsplit(char ***array);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *str);
void				ft_putendl(char const *s);
void				ft_putnbr(int nbr);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_nbr_size(intmax_t nbr);
int					ft_nbw(const char *s, char c);
int					ft_lword(const char *s, char c);
int					get_next_line(const int fd, char **line);
int					clean_line(char **fdt, char **line);
int					ft_nbr_size_base(uintmax_t nbr, int base);
char				*ft_revstr(char *str);
void				*ft_s_inlower(char *str);
void				*ft_s_inupper(char *str);
void				ft_s_toupper(char *str);
char				*ft_strndup(char *str, int size);
int					ft_intlen_max(uintmax_t nbr);
char				*ft_ftoa(long double nbr, int prec, char dot);
void				ft_putnbrmax(intmax_t nbr);
char				*ft_itoa_uintmax(uintmax_t n);
char				*ft_itoa_base(uintmax_t nbr, int base);
void				free_strsplit(char ***str);
int					ft_arrlen(char **arr);
char				**ft_arrcat(char **arr, char *str);
void				ft_init_arr(char **arr, int size);
int					ft_nbrstrcmp(const char *s1, const char *s2);
int					ft_is_str_num(const char *s1);
void				ft_errorexit(char *error_msg);
void				ft_handle_error(char *error_msg, int exit_code);
void				ft_error(char *error_msg);
#endif
