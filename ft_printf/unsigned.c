/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 18:49:57 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/15 18:50:03 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void unflagged_uint(t_printf *p, va_list ap)
{
	int				len;
	unsigned int	nb;
	int zero;
	int i;

	zero = 0;
	nb = va_arg(ap, unsigned int);
	len = unsigned_nblen(nb, 10);
	if (len < p->precision)
		zero = p->precision - len;
	if (p->minus != 1)
		print_spaces(p, len + zero);
	i = -1;
	while (++i < zero)
		c_putchar('0');
	c_putnbr(nb);
	if (p->minus == 1)
		print_spaces(p, len + zero);
}

void	put_unsigned_i(t_printf *p, va_list ap)
{
	if (p->length && p->length[0] != '\0')
	{
		if (ft_strcmp("h", p->length) == 0)
			h_flag2(p, ap);
		if (ft_strcmp("hh", p->length) == 0)
			hh_flag2(p, ap);
		if (ft_strcmp("l", p->length) == 0)
			put_unsigned_long_i(p, ap);
		if (ft_strcmp("ll", p->length) == 0)
			ll_flag2(p, ap);
		if (ft_strcmp("z", p->length) == 0)
			z_flag2(p, ap);
		if (ft_strcmp("j", p->length) == 0)
			j_flag2(p, ap);
	}
	else
		unflagged_uint(p, ap);
}

void	put_unsigned_long_i(t_printf *p, va_list ap)
{
	int					len;
	int zero;
	unsigned long int	nb;
	int i;

	zero = 0;
	nb = va_arg(ap, unsigned long int);
	len = unsigned_nblen(nb, 10);
	if (len < p->precision)
		zero = p->precision - len;
	if (p->minus != 1)
		print_spaces(p, len + zero);
	i = -1;
	while (++i < zero)
		c_putchar('0');
	c_putnbr(nb);
	if (p->minus == 1)
		print_spaces(p, len + zero);
}