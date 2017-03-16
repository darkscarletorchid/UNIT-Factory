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
	int			len;
	long int	nb;
	int			zero;
	int			i;
	int flag;

	zero = 0;
	flag = 0;
	nb = va_arg(ap, int);
	len = nblen(nb, 10);
	if (len <= p->precision)
	{
		if (nb < 0)
			len--;
		zero = p->precision - len;
	}
	if ((p->plus == 1 || p->space == 1 ) && nb >= 0)
		len++;
	if (nb < 0 && p->zero == 1)
	{
		c_putchar('-');
		nb = -nb;
		flag = 1;
	}
	if (p->minus != 1)
		print_spaces(p, len + zero);
	if (p->space == 1 && p->plus != 1 && nb >= 0 && flag != 1)
		c_putchar(' ');
	if (p->plus == 1 && nb >= 0 && flag != 1)
		c_putchar('+');
	i = -1;
	while (++i < zero)
		c_putchar('0');
	c_putnbr(nb);
	if (p->minus == 1)
		print_spaces(p, len);
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

void	put_long_d(t_printf *p, va_list ap)
{
	int			len;
	long int	nb;
	int 		zero;
	int 		i;

	zero = 0;
	nb = va_arg(ap, long int);
	len = nblen(nb, 10);
	if (len < p->precision)
		zero = p->precision - len;
	if (p->plus == 1 || p->space == 1)
		p->width--;
	if (p->minus != 1)
		print_spaces(p, len + zero);
	if (p->space == 1 && p->plus != 1)
		c_putchar(' ');
	if (p->plus == 1)
		c_putchar('+');
	i = -1;
	while (++i < zero)
		c_putchar('0');
	c_putnbr(nb);
	if (p->minus == 1)
		print_spaces(p, len + zero);
}
