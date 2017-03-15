//
// Created by Anastasiia Trepyton on 3/15/17.
//

#include "ft_printf.h"

void	h_flag(t_printf *p, va_list ap)
{
	int			len;
	short int	nb;

	nb = (short)va_arg(ap, int);
	len = nblen(nb, 10);
	if (p->plus == 1 || p->space == 1)
		p->width--;
	if (p->minus != 1)
		print_spaces(p, len);
	if (p->space == 1 && p->plus != 1)
		c_putchar(' ');
	if (p->plus == 1)
		c_putchar('+');
	c_putnbr(nb);
	if (p->minus == 1)
		print_spaces(p, len);
}

void	hh_flag(t_printf *p, va_list ap)
{
	int			len;
	signed char	nb;

	nb = (signed char)va_arg(ap, int);
	len = nblen(nb, 10);
	if (p->plus == 1 || p->space == 1)
		p->width--;
	if (p->minus != 1)
		print_spaces(p, len);
	if (p->space == 1 && p->plus != 1)
		c_putchar(' ');
	if (p->plus == 1)
		c_putchar('+');
	c_putnbr(nb);
	if (p->minus == 1)
		print_spaces(p, len);
}

void	ll_flag(t_printf *p, va_list ap)
{
	int				len;
	long long int	nb;

	nb = va_arg(ap, long long int);
	len = nblen(nb, 10);
	if (p->plus == 1 || p->space == 1)
		p->width--;
	if (p->minus != 1)
		print_spaces(p, len);
	if (p->space == 1 && p->plus != 1)
		c_putchar(' ');
	if (p->plus == 1)
		c_putchar('+');
	c_putnbr(nb);
	if (p->minus == 1)
		print_spaces(p, len);
}

void	z_flag(t_printf *p, va_list ap)
{
	int		len;
	size_t	nb;

	nb = va_arg(ap, size_t);
	len = nblen(nb, 10);
	if (p->plus == 1 || p->space == 1)
		p->width--;
	if (p->minus != 1)
		print_spaces(p, len);
	if (p->space == 1 && p->plus != 1)
		c_putchar(' ');
	if (p->plus == 1)
		c_putchar('+');
	c_putnbr(nb);
	if (p->minus == 1)
		print_spaces(p, len);
}

void	j_flag(t_printf *p, va_list ap)
{
	int			len;
	intmax_t	nb;

	nb = va_arg(ap, intmax_t);
	len = nblen(nb, 10);
	if (p->plus == 1 || p->space == 1)
		p->width--;
	if (p->minus != 1)
		print_spaces(p, len);
	if (p->space == 1 && p->plus != 1)
		c_putchar(' ');
	if (p->plus == 1)
		c_putchar('+');
	c_putnbr(nb);
	if (p->minus == 1)
		print_spaces(p, len);
}