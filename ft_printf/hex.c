//
// Created by Anastasiia Trepyton on 3/16/17.
//
#include "ft_printf.h"

void	unflagged_hex(t_printf *p, va_list ap)
{
	long int		nb;
	int		len;
	char	*s;
	int 	prec;
	int w;
	int flag;
	int 	i;

	nb = va_arg(ap, unsigned int);
	s = ft_itoa_base(nb, 16);
	len = ft_strlen(s);
	prec = 0;
	if (nb == 0)
		number_zero(p);
	else {
		flag = p->sharp == 2 ? 2 : 0;
		if (p->precision >= len)
			prec = p->precision - len;
		w = p->width - prec - len - flag;
		while (w > 0 && p->minus != 1 &&
			   (p->zero != 1 || (p->zero == 1 && p->precision > 0))) {
			c_putchar(' ');
			w--;
		}
		if (flag && p->convers == 'x')
			c_putstr("0x");
		else if (flag && p->convers == 'X')
			c_putstr("0X");
		while (w > 0 && p->minus != 1 && p->zero == 1 && prec == 0) {
			c_putchar('0');
			w--;
		}
		i = -1;
		while (++i < prec)
			c_putchar('0');
		if (p->convers == 'x')
			ft_lowercase(s);
		c_putstr(s);
		while (w > 0 && p->minus == 1) {
			c_putchar(' ');
			w--;
		}
		while (w > 0 && p->minus == 1 && p->zero == 1 && prec == 0) {
			c_putchar('0');
			w--;
		}
	}
}

void	put_hex(t_printf *p, va_list ap)
{
	if (p->length && p->length[0] != '\0')
	{
		if (ft_strcmp("h", p->length) == 0)
			h_flag3(p, ap, 16);
		else if (ft_strcmp("hh", p->length) == 0)
			hh_flag3(p, ap, 16);
		else if (ft_strcmp("l", p->length) == 0)
			l_flag3(p, ap, 16);
		else if (ft_strcmp("ll", p->length) == 0)
			ll_flag3(p, ap, 16);
		else if (ft_strcmp("z", p->length) == 0)
			z_flag3(p, ap, 16);
		else if (ft_strcmp("j", p->length) == 0)
			j_flag3(p, ap, 16);
	}
	else
		unflagged_hex(p, ap);
}
