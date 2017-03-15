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
	int sharp;
	int zero;
	int minus;
	int plus;
	int space;
}				t_printf;



void	c_putchar(char c);
void	c_putnbr(long nb);
void	c_putstr(char *str);
int	check_conversion(char *format, va_list ap);
#endif
