//
// Created by Anastasiia Trepyton on 3/16/17.
//
#include "ft_printf.h"

void	put_pointer(t_printf *p, va_list ap)
{
	void *nb;
	int len;
	char *s;
	int i;
	int zero;

	nb = va_arg(ap, void *);
	if (nb)
	{
		s = ft_itoa_base((long long int) nb, 16);
		len = (int) ft_strlen(s);
		zero = 0;
		if (len < p->precision)
			zero = p->precision - len;
		if (p->minus != 1)
			print_spaces(p, len + 2 + zero);
		c_putstr("0x");
		i = -1;
		while (++i < zero)
			c_putchar('0');
		ft_lowercase(s);
		c_putstr(s);
		if (p->minus == 1)
			print_spaces(p, len + 2 + zero);
	}
	else
	{
		if (p->precision == 0) {
			if (p->minus != 1)
				add_width(p, 2);
			c_putstr("0x");
			if (p->minus == 1)
				add_width(p, 2);
		} else if (p->precision < 0) {
			len = 1;
			if (p->minus != 1)
				add_width(p, len + 2);
			c_putstr("0x0");
			if (p->minus == 1)
				add_width(p, len + 2);
		} else if (p->precision > 0) {
			len = p->precision;
			if (p->minus != 1)
				add_width(p, len + 2);
			c_putstr("0x");
			i = -1;
			while (++i < len)
				c_putchar('0');
			if (p->minus == 1)
				add_width(p, len + 2);
		}
	}
}