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

void	number_zero(t_printf *p)
{
	int i;
	int w;

	if (p->precision != 0)
	{
		i = -1;
		if (p->precision >= 0)
			w = p->width - p->precision;
		else
			w = p->width - 1;
		while (w > 0)
		{
			c_putchar(' ');
			w--;
		}
		if (p->space == 1 && p->plus != 1)
			c_putchar(' ');
		if (p->plus == 1)
			c_putchar('+');
		while (++i < p->precision - 1)
			c_putchar('0');
		c_putnbr(0);
	}
	else
	{
		w = p->width;
		while (w > 0)
		{
			c_putchar(' ');
			w--;
		}
		if ((p->convers == 'o' || p->convers == 'O') && p->sharp == 2)
			c_putchar('0');
	}
}

void	unflagged_di(t_printf *p, va_list ap)
{
	long int	nb;

	nb = va_arg(ap, int);
	output_int(nb, p);
}

void	put_long_d(t_printf *p, va_list ap)
{
	long long int	nb;

	nb = va_arg(ap, long int);
	output_int(nb, p);
}

void	put_d_i(t_printf *p, va_list ap)
{
	if (p->length && p->length[0] != '\0') {
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

