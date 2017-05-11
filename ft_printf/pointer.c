/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 13:26:06 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/25 10:21:54 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		number_zero(t_printf *p)
{
	int i;
	int f;

	if (p->precision != 0)
	{
		f = 0;
		if ((p->space || p->plus))
			f = 1;
		i = p->precision >= 0 ? p->precision + f : 1 + f;
		add_width(p, i);
		if (p->space == 1 && p->plus != 1)
			c_putchar(' ');
		if (p->plus == 1)
			c_putchar('+');
		i = -1;
		while (++i < p->precision - 1)
			c_putchar('0');
		c_putnbr(0);
	}
	else
	{
		add_width(p, 0);
		if ((p->convers == 'o' || p->convers == 'O') && p->sharp == 2)
			c_putchar('0');
	}
}

static void	null_pointer(t_printf *p)
{
	int i;
	int len;

	len = 2;
	len += p->precision < 0 ? 1 : p->precision;
	if (p->minus != 1)
		add_width(p, len);
	if (p->precision == 0)
		c_putstr("0x");
	else if (p->precision < 0)
		c_putstr("0x0");
	else if (p->precision > 0)
	{
		c_putstr("0x");
		i = -1;
		while (++i < p->precision)
			c_putchar('0');
	}
	if (p->minus == 1)
		add_width(p, p->precision + 2);
}

void		put_pointer(t_printf *p, va_list ap)
{
	void		*nb;
	t_output	o;
	int			zero;

	nb = va_arg(ap, void *);
	if (nb)
	{
		o.s = ft_itoa_base((long long int)nb, 16);
		o.len = ft_strlen(o.s);
		zero = o.len < p->precision ? p->precision - o.len : 0;
		if (p->minus != 1)
			print_spaces(p, o.len + 2 + zero);
		c_putstr("0x");
		o.i = -1;
		while (++o.i < zero)
			c_putchar('0');
		ft_lowercase(o.s);
		c_putstr(o.s);
		ft_strdel(&o.s);
		if (p->minus == 1)
			print_spaces(p, o.len + 2 + zero);
	}
	else
		null_pointer(p);
}
