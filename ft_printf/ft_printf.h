/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:36:40 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/25 10:20:03 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <wchar.h>

int				g_count;

typedef struct	s_printf
{
	char		*arg;
	char		convers;
	char		*length;
	int			sharp;
	int			zero;
	int			minus;
	int			plus;
	int			space;
	int			width;
	int			precision;
}				t_printf;

typedef struct	s_output
{
	int			len;
	int			prec;
	int			w;
	int			i;
	int			flag;
	char		*s;
}				t_output;
/*
** ft_printf.c
*/
int				ft_printf(const char *format, ...);
/*
** conversion.c
*/
int				check_conversion(char *format, va_list ap);
void			null_struct(t_printf *p);
void			parse_arg(t_printf *p);
void			length_flags(t_printf *p, char *s);
int				flags(t_printf *p, char *s);
/*
** output.c
*/
void			put_arg(t_printf *p, va_list ap);
void			put_percent(t_printf *p, va_list ap);
/*
** chars.c
*/
void			null_string(t_printf *p, char *s);
void			exist_str(t_printf *p, char *s);
void			put_string(t_printf *p, va_list ap);
void			put_char(t_printf *p, va_list ap);
/*
** wchars.c
*/
void			put_string_unicode(t_printf *p, va_list ap);
void			exist_str_unicode(t_printf *p, char *s, wint_t *str);
void			precision_str(t_printf *p, int len, char *s, wint_t *str);
int				charlen(wint_t c);
/*
** wide_chars.c
*/
char			*get_str(wint_t *str);
int				wide_strlen(wint_t *str);
char			*convert_to_char(char *dest, wint_t *str);
/*
** pointer.c
*/
void			put_pointer(t_printf *p, va_list ap);
void			number_zero(t_printf *p);
/*
** printf_lib.c
*/
void			c_putnbr(unsigned long long nb);
void			c_putstr(char *str);
void			c_putchar(char c);
/*
** other.c
*/
void			print_spaces(t_printf *p, int len);
void			undef_flag(t_printf *p, int j, char *s);
void			add_width(t_printf *p, int len);
void			ox_kostyl(int flag, t_printf *p);
void			space_kostyl(t_output *o, t_printf *p);
/*
** decimals.c
*/
void			put_d_i(t_printf *p, va_list ap);
void			put_long_d(t_printf *p, va_list ap);
void			unflagged_di(t_printf *p, va_list ap);
void			output_int(long long int nb, t_printf *p);
void			output_int(long long int nb, t_printf *p);
/*
** hex.c
*/
void			unflagged_hex(t_printf *p, va_list ap);
void			put_hex(t_printf *p, va_list ap);
void			base_output(t_printf *p, intmax_t nb, int base);
void			nonzero_hex(t_printf *p, unsigned long long nb, int base);
void			get_params(unsigned long long nb, int base, t_output *o,
							t_printf *p);
/*
** octal.c
*/
void			put_octal(t_printf *p, va_list ap);
void			put_long_octal(t_printf *p, va_list ap);
void			unflagged_octal(t_printf *p, va_list ap);
void			output_octal(t_printf *p, intmax_t nb, int base);
void			nonzero_octal(t_printf *p, unsigned long long nb, int base);
/*
** unsigned.c
*/
void			unflagged_uint(t_printf *p, va_list ap);
void			put_unsigned_i(t_printf *p, va_list ap);
void			put_unsigned_long_i(t_printf *p, va_list ap);
void			output_unsigned(t_printf *p, unsigned long long nb);
/*
** flagged_decimals.c
*/
void			h_flag(t_printf *p, va_list ap);
void			hh_flag(t_printf *p, va_list ap);
void			z_flag(t_printf *p, va_list ap);
void			j_flag(t_printf *p, va_list ap);
void			ll_flag(t_printf *p, va_list ap);
/*
** flagged_base.c
*/
void			j_flag3(t_printf *p, va_list ap, int base);
void			z_flag3(t_printf *p, va_list ap, int base);
void			l_flag3(t_printf *p, va_list ap, int base);
void			hh_flag3(t_printf *p, va_list ap, int base);
void			h_flag3(t_printf *p, va_list ap, int base);
/*
** flagged_unsigned.c
*/
void			h_flag2(t_printf *p, va_list ap);
void			hh_flag2(t_printf *p, va_list ap);
void			ll_flag2(t_printf *p, va_list ap);
void			z_flag2(t_printf *p, va_list ap);
void			j_flag2(t_printf *p, va_list ap);
#endif
