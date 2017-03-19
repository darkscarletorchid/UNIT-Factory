//
// Created by Anastasiia Trepyton on 3/13/17.
//

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <wchar.h>
int count;

typedef struct	s_printf
{
	char *arg;
	char convers;
	char *length;
	int sharp;
	int zero;
	int minus;
	int plus;
	int space;
	int width;
	int precision;
}				t_printf;



void	c_putchar(char c);
void	c_putnbr(unsigned long long int nb);
void	c_putstr(char *str);
int	check_conversion(char *format, va_list ap);

void	put_arg(t_printf *p, va_list ap);

/*
** decimal.c
*/
void	put_d_i(t_printf *p, va_list ap);
void	put_long_d(t_printf *p, va_list ap);
void	put_octal(t_printf *p, va_list ap);
void	put_long_octal(t_printf *p, va_list ap);
void	put_hex(t_printf *p, va_list ap);
/*
** flagged_decimals.c
*/
void	h_flag(t_printf *p, va_list ap);
void	hh_flag(t_printf *p, va_list ap);
void	ll_flag(t_printf *p, va_list ap);
void	z_flag(t_printf *p, va_list ap);
void	j_flag(t_printf *p, va_list ap);
/*
** flagged_base.c
*/
void	h_flag3(t_printf *p, va_list ap, int base);
void	hh_flag3(t_printf *p, va_list ap, int base);
void	ll_flag3(t_printf *p, va_list ap, int base);
void	z_flag3(t_printf *p, va_list ap, int base);
void	j_flag3(t_printf *p, va_list ap, int base);
void	l_flag3(t_printf *p, va_list ap, int base);

void	h_flag2(t_printf *p, va_list ap);
void	hh_flag2(t_printf *p, va_list ap);
void	ll_flag2(t_printf *p, va_list ap);
void	z_flag2(t_printf *p, va_list ap);
void	j_flag2(t_printf *p, va_list ap);
/*
** unsigned.c
*/
void	put_unsigned_i(t_printf *p, va_list ap);
void	put_unsigned_long_i(t_printf *p, va_list ap);
/*
** chars.c
*/
void	put_string(t_printf *p, va_list ap);
void	put_char(t_printf *p, va_list ap);
void	put_string_unicode(t_printf *p, va_list ap);
void	put_pointer(t_printf *p, va_list ap);
/*
** other.c
*/
void	print_spaces(t_printf *p, int len);
void	add_width(t_printf *p, int len);
void	number_zero(t_printf *p);

char *get_str(wint_t *str);
void	put_char_unicode(t_printf *p, va_list ap);

void	base_output(t_printf *p, unsigned long long nb, int base);
void	output_octal(t_printf *p, unsigned long long nb, int base);
void 	output_int(long long int nb, t_printf *p);
int		wide_strlen(wint_t *str);
void				wint_convert_c(wint_t c);
char				*convert_to_char(char *dest, wint_t *str);
#endif
