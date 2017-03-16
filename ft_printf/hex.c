//
// Created by Anastasiia Trepyton on 3/16/17.
//
#include "ft_printf.h"

void	unflagged_hex(t_printf *p, va_list ap)
{
	long int		nb;
	int		len;
	char	*s;
	int 	zero;
	int 	i;

	nb = va_arg(ap, unsigned int);
	zero = 0;
	s = ft_itoa_base(nb, 16);
	len = (int) ft_strlen(s);
	if (len < p->precision)
		zero = p->precision - len;
	if (nb != 0 && p->sharp == 2)
		len += 2;
	if (p->minus != 1)
		print_spaces(p, len + zero);
	if (nb != 0 && p->sharp == 2) {
		if (p->convers == 'x')
			c_putstr("0x");
		else
			c_putstr("0X");
	}
	i = -1;
	while (++i < zero)
		c_putchar('0');
	if (p->convers == 'x')
		ft_lowercase(s);
	c_putstr(s);
	if (p->minus == 1)
		print_spaces(p, len + zero);
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
