/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 14:33:32 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/20 14:33:33 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	unflagged_hex(t_printf *p, va_list ap)
{
	long int		nb;

	nb = va_arg(ap, unsigned int);
	base_output(p, nb, 16);
}

void	get_params(unsigned long long nb, int base, t_output *o, t_printf *p)
{
	o->s = ft_itoa_base(nb, base);
	o->len = ft_strlen(o->s);
	o->prec = p->precision >= o->len ? p->precision - o->len : 0;
	o->flag = p->sharp == 2 ? 2 : 0;
	o->w = p->width - o->prec - o->len - o->flag;
	if (p->convers == 'x')
		ft_lowercase(o->s);
}

void	nonzero_hex(t_printf *p, unsigned long long nb, int base)
{
	t_output	o;

	get_params(nb, base, &o, p);
	while (o.w > 0 && p->minus != 1 &&
		(p->zero != 1 || (p->zero == 1 && p->precision > 0)))
	{
		c_putchar(' ');
		o.w--;
	}
	ox_kostyl(o.flag, p);
	while (o.w > 0 && p->minus != 1 && p->zero == 1 && o.prec == 0)
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

void	base_output(t_printf *p, intmax_t nb, int base)
{
	if (nb == 0)
		number_zero(p);
	else
		nonzero_hex(p, nb, base);
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
			l_flag3(p, ap, 16);
		else if (ft_strcmp("z", p->length) == 0)
			z_flag3(p, ap, 16);
		else if (ft_strcmp("j", p->length) == 0)
			j_flag3(p, ap, 16);
	}
	else
		unflagged_hex(p, ap);
}
