//
// Created by Anastasiia Trepyton on 3/13/17.
//

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

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
void	c_putnbr(long nb);
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
** h_flag.c
*/
void	h_flag(t_printf *p, va_list ap);
void	hh_flag(t_printf *p, va_list ap);
void	ll_flag(t_printf *p, va_list ap);
void	z_flag(t_printf *p, va_list ap);
void	j_flag(t_printf *p, va_list ap);
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
void	put_wide_str(t_printf *p, va_list ap);
void	put_wide_char(t_printf *p, va_list ap);
void	put_pointer(t_printf *p, va_list ap);
/*
** other.c
*/
void	print_spaces(t_printf *p, int len);
void	add_width(t_printf *p, int len);
#endif
