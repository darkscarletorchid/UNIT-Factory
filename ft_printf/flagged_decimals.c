//
// Created by Anastasiia Trepyton on 3/15/17.
//

#include "ft_printf.h"

void 	output_int(long long int nb, t_printf *p)
{
	int len;
	int prec;
	int w;
	int i;
	int flag;

	prec = 0;
	len = nblen(nb, 10);
	if (nb == 0)
		number_zero(p);
	else
	{
		flag = nb < 0 ? 1 : 0;
		if (p->precision >= len)
			prec = p->precision - len + flag;
		if ((p->space || p->plus) && nb > 0)
			len++;
		w = p->width - prec - len;
		while (w > 0 && p->minus != 1 &&
			   (p->zero != 1 || (p->zero == 1 && p->precision > 0)))
		{
			c_putchar(' ');
			w--;
		}
		if (p->space == 1 && p->plus != 1 && nb >= 0)
			c_putchar(' ');
		if (p->plus == 1 && nb >= 0 && flag != 1)
			c_putchar('+');
		if (flag == 1)
		{
			c_putchar('-');
			nb = -nb;
		}
		while (w > 0 && p->minus != 1 && p->zero == 1 && prec == 0)
		{
			c_putchar('0');
			w--;
		}
		i = -1;
		while (++i < prec)
			c_putchar('0');
		c_putnbr(nb);
		while (w > 0 && p->minus == 1)
		{
			c_putchar(' ');
			w--;
		}
		while (w > 0 && p->minus == 1 && p->zero == 1 && prec == 0)
		{
			c_putchar('0');
			w--;
		}
	}
}

void	h_flag(t_printf *p, va_list ap)
{
	short int	nb;

	nb = (short)va_arg(ap, int);
	output_int(nb, p);
}

void	hh_flag(t_printf *p, va_list ap)
{
	signed char	nb;

	nb = (signed char)va_arg(ap, int);
	output_int(nb, p);
}

void	ll_flag(t_printf *p, va_list ap)
{
	long long int	nb;

	nb = va_arg(ap, long long int);
	output_int(nb, p);
}

void	z_flag(t_printf *p, va_list ap)
{
	size_t	nb;

	nb = va_arg(ap, size_t);
	output_int(nb, p);
}

void	j_flag(t_printf *p, va_list ap)
{
	intmax_t	nb;

	nb = va_arg(ap, intmax_t);
	output_int(nb, p);
}