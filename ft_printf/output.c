/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 11:12:16 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/21 15:19:23 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	nonzero_binary(t_printf *p, unsigned long long nb)
{
	t_output o;

	o.s = ft_itoa_base(nb, 2);
	o.len = ft_strlen(o.s);
	o.prec = p->precision >= o.len ? p->precision - o.len : 0;
	o.w = p->width - o.prec - o.len;
	space_kostyl(&o, p);
	while (o.w > 0 && p->minus != 1 && p->zero == 1)
	{
		c_putchar('0');
		o.w--;
	}
	o.i = -1;
	while (++o.i < o.prec)
		c_putchar('0');
	c_putstr(o.s);
	while (o.w > 0 && p->minus == 1)
	{
		c_putchar(' ');
		o.w--;
	}
}

void	put_binary(t_printf *p, va_list ap)
{
	unsigned long long	nb;

	nb = va_arg(ap, unsigned long long);
	if (nb == 0)
		number_zero(p);
	else
		nonzero_binary(p, nb);
}

void	put_percent(t_printf *p, va_list ap)
{
	int i;

	if (p->convers == 'b')
		put_binary(p, ap);
	else
	{
		i = 0;
		if (p->minus != 1)
			print_spaces(p, 1);
		while (ft_strchr("-+.0123456789 hljz", p->arg[i]) && p->arg[i])
			i++;
		if (p->arg[i] == '%')
			c_putchar('%');
		else
		{
			while (p->arg[i] && p->arg[i] != '%')
			{
				c_putchar(p->arg[i]);
				i++;
			}
		}
		if (p->minus == 1)
			print_spaces(p, 1);
	}
}

void	put_arg(t_printf *p, va_list ap)
{
	if (p->convers == 'd' || p->convers == 'i')
		put_d_i(p, ap);
	else if (p->convers == 'D')
		put_long_d(p, ap);
	else if (p->convers == 'o')
		put_octal(p, ap);
	else if (p->convers == 'O')
		put_long_octal(p, ap);
	else if (p->convers == 'X' || p->convers == 'x')
		put_hex(p, ap);
	else if (p->convers == 'u')
		put_unsigned_i(p, ap);
	else if (p->convers == 'U')
		put_unsigned_long_i(p, ap);
	else if (p->convers == 's')
		put_string(p, ap);
	else if (p->convers == 'c' || p->convers == 'C')
		put_char(p, ap);
	else if (p->convers == 'S')
		put_string_unicode(p, ap);
	else if (p->convers == 'p')
		put_pointer(p, ap);
	else
		put_percent(p, ap);
}
