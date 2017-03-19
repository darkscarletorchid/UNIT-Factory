//
// Created by Anastasiia Trepyton on 3/16/17.
//
#include "ft_printf.h"

void	output_octal(t_printf *p, unsigned long long nb, int base)
{
	int			len;
	int 		w;
	int 		prec;
	char		*s;
	int 		i;
	int			flag;

	s = ft_itoa_base(nb, base);
	len = ft_strlen(s);
	prec = 0;
	if (nb == 0)
		number_zero(p);
	else {
		flag = p->sharp == 2 ? 1 : 0;
		if (p->precision >= len)
			prec = p->precision - len - flag;
		w = p->width - prec - len - flag;
		while (w > 0 && p->minus != 1 &&
			   (p->zero != 1 || (p->zero == 1 && p->precision > 0)))
		{
			c_putchar(' ');
			w--;
		}
		while (w > 0 && p->minus != 1 && p->zero == 1 && prec == 0)
		{
			c_putchar('0');
			w--;
		}
		i = -1;
		while (++i < prec)
			c_putchar('0');
		if (flag)
			c_putstr("0");
		c_putstr(s);
		while (w > 0 && p->minus == 1)
		{
			c_putchar(' ');
			w--;
		}
	}
}
void	unflagged_octal(t_printf *p, va_list ap)
{
	long int	nb;

	nb = va_arg(ap, unsigned int);
	output_octal(p, nb, 8);
}

void	put_long_octal(t_printf *p, va_list ap)
{
	unsigned long int	nb;

	nb = va_arg(ap, unsigned long int);
	output_octal(p, nb, 8);
}

void	put_octal(t_printf *p, va_list ap)
{
	if (p->length && p->length[0] != '\0')
	{
		if (ft_strcmp("h", p->length) == 0)
			h_flag3(p, ap, 8);
		else if (ft_strcmp("hh", p->length) == 0)
			hh_flag3(p, ap, 8);
		else if (ft_strcmp("l", p->length) == 0)
			put_long_octal(p, ap);
		else if (ft_strcmp("ll", p->length) == 0)
			l_flag3(p, ap, 8);
		else if (ft_strcmp("z", p->length) == 0)
			z_flag3(p, ap, 8);
		else if (ft_strcmp("j", p->length) == 0)
			j_flag3(p, ap, 8);
	}
	else
		unflagged_octal(p, ap);
}

