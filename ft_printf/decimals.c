/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 18:07:44 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/15 18:07:48 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	unflagged_di(t_printf *p, va_list ap)
{
	long int	nb;

	nb = va_arg(ap, int);
	output_int(nb, p);
}

void	put_long_d(t_printf *p, va_list ap)
{
	long long nb;

	nb = va_arg(ap, long int);
	output_int(nb, p);
}

void	put_d_i(t_printf *p, va_list ap)
{
	if (p->length && p->length[0] != '\0')
	{
		if (ft_strcmp("h", p->length) == 0)
			h_flag(p, ap);
		else if (ft_strcmp("hh", p->length) == 0)
			hh_flag(p, ap);
		else if (ft_strcmp("l", p->length) == 0)
			put_long_d(p, ap);
		else if (ft_strcmp("ll", p->length) == 0)
			ll_flag(p, ap);
		else if (ft_strcmp("z", p->length) == 0)
			z_flag(p, ap);
		else if (ft_strcmp("j", p->length) == 0)
			j_flag(p, ap);
	}
	else
		unflagged_di(p, ap);
}

void	nonzero_int(long long int nb, t_printf *p, t_output o)
{
	space_kostyl(&o, p);
	if (p->space == 1 && p->plus != 1 && nb >= 0)
		c_putchar(' ');
	if (p->plus == 1 && nb >= 0 && o.flag != 1)
		c_putchar('+');
	if (o.flag)
		c_putchar('-');
	nb = nb < 0 ? -nb : nb;
	while (o.w > 0 && p->minus != 1 && p->zero == 1)
	{
		c_putchar('0');
		o.w--;
	}
	o.i = -1;
	while (++o.i < o.prec)
		c_putchar('0');
	c_putnbr(nb);
	while (o.w > 0 && p->minus == 1)
	{
		c_putchar(' ');
		o.w--;
	}
}

void	output_int(long long int nb, t_printf *p)
{
	t_output o;

	if (nb == 0)
		number_zero(p);
	else
	{
		o.len = nblen(nb, 10);
		o.flag = nb < 0 ? 1 : 0;
		o.prec = p->precision >= o.len ? p->precision - o.len + o.flag : 0;
		if ((p->space || p->plus) && nb > 0)
			o.len++;
		o.w = p->width - o.prec - o.len;
		nonzero_int(nb, p, o);
	}
}
