//
// Created by Anastasiia Trepyton on 3/16/17.
//
#include "ft_printf.h"

void	unflagged_octal(t_printf *p, va_list ap)
{

	int		len;
	long int	nb;
	char	*s;
	int		zero;
	int 	i;

	zero = 0;
	nb = va_arg(ap, unsigned int);
	s = ft_itoa_base(nb, 8);
	len = (int) ft_strlen(s);
	if (nb != 0 && p->sharp == 2)
		len++;
	if (len < p->precision)
		zero = p->precision - len;
	if (p->minus != 1)
		print_spaces(p, len + zero);
	if (nb != 0 && p->sharp == 2)
		c_putstr("0");
	i = -1;
	while (++i < zero)
		c_putchar('0');
	c_putstr(s);
	if (p->minus == 1)
		print_spaces(p, len + zero);



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
			ll_flag3(p, ap, 8);
		else if (ft_strcmp("z", p->length) == 0)
			z_flag3(p, ap, 8);
		else if (ft_strcmp("j", p->length) == 0)
			j_flag3(p, ap, 8);
	}
	else
		unflagged_octal(p, ap);
}

void	put_long_octal(t_printf *p, va_list ap)
{
	int			len;
	long int	nb;
	char		*s;
	int		zero;
	int 	i;

	nb = va_arg(ap, long int);
	zero = 0;
	s = ft_itoa_base(nb, 8);
	len = (int)ft_strlen(s);
	if (nb != 0 && p->sharp == 2)
		len++;
	if (len < p->precision)
		zero = p->precision - len;
	if (p->minus != 1)
		print_spaces(p, len + zero);
	if (nb != 0 && p->sharp == 2)
		c_putstr("0");
	i = -1;
	while (++i < zero)
		c_putchar('0');
	c_putstr(s);
	if (p->minus == 1)
		print_spaces(p, len + zero);
}
