/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:06:30 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/20 15:06:32 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	nonzero_octal(t_printf *p, unsigned long long nb, int base)
{
	t_output o;

	o.s = ft_itoa_base(nb, base);
	o.len = ft_strlen(o.s);
	o.flag = p->sharp == 2 ? 1 : 0;
	o.prec = p->precision >= o.len ? p->precision - o.len - o.flag : 0;
	o.w = p->width - o.prec - o.len - o.flag;
	space_kostyl(&o, p);
	while (o.w > 0 && p->minus != 1 && p->zero == 1 && o.prec == 0)
	{
		c_putchar('0');
		o.w--;
	}
	o.i = -1;
	while (++o.i < o.prec)
		c_putchar('0');
	ox_kostyl(o.flag, p);
	c_putstr(o.s);
	while (o.w > 0 && p->minus == 1)
	{
		c_putchar(' ');
		o.w--;
	}
}

void	output_octal(t_printf *p, intmax_t nb, int base)
{
	if (nb == 0)
		number_zero(p);
	else
		nonzero_octal(p, nb, base);
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
