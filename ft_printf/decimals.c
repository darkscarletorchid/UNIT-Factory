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

void	simple_di(t_printf *p, va_list ap)
{
	int		len;
	int		nb;

	nb = va_arg(ap, int);
	len = nblen(nb, 10);
	if (p->plus == 1 || p->space == 1)
		p->width--;
	if (p->minus != 1)
		print_spaces(p, len);
	if (p->space == 1 && p->plus != 1)
		c_putchar(' ');
	if (p->plus == 1)
		c_putchar('+');
	c_putnbr(nb);
	if (p->minus == 1)
		print_spaces(p, len);
}

void	put_d_i(t_printf *p, va_list ap)
{
	if (ft_strcmp("h", p->length) == 0)
		h_flag(p, ap);
	if (ft_strcmp("hh", p->length) == 0)
		hh_flag(p, ap);
	if (ft_strcmp("l", p->length) == 0)
		put_long_d(p, ap);
	if (ft_strcmp("ll", p->length) == 0)
		ll_flag(p, ap);
	if (ft_strcmp("z", p->length) == 0)
		z_flag(p, ap);
	if (ft_strcmp("j", p->length) == 0)
		j_flag(p, ap);
	else
		simple_di(p, ap);
}

void	put_long_d(t_printf *p, va_list ap)
{
	int			len;
	long int	nb;

	nb = va_arg(ap, long int);
	len = nblen(nb, 10);
	if (p->plus == 1 || p->space == 1)
		p->width--;
	if (p->minus != 1)
		print_spaces(p, len);
	if (p->space == 1 && p->plus != 1)
		c_putchar(' ');
	if (p->plus == 1)
		c_putchar('+');
	c_putnbr(nb);
	if (p->minus == 1)
		print_spaces(p, len);
}

void	put_octal(t_printf *p, va_list ap)
{
	int		len;
	int		nb;
	char	*s;

	nb = va_arg(ap, int);
	s = ft_itoa_base(nb, 8);
	len = (int)ft_strlen(s);
	if (nb != 0 && p->sharp == 2)
	{
		p->width--;
		c_putstr("0");
	}
	if (p->minus != 1)
		print_spaces(p, len);
	c_putstr(s);
	if (p->minus == 1)
		print_spaces(p, len);
}

void	put_long_octal(t_printf *p, va_list ap)
{
	int			len;
	long int	nb;
	char		*s;

	nb = va_arg(ap, long int);
	s = ft_itoa_base(nb, 8);
	len = (int)ft_strlen(s);
	if (p->minus != 1)
		print_spaces(p, len);
	c_putstr(s);
	if (p->minus == 1)
		print_spaces(p, len);
}

void	put_hex(t_printf *p, va_list ap)
{
	int		nb;
	int		len;
	char	*s;

	nb = va_arg(ap, int);
	s = ft_itoa_base(nb, 16);
	len = (int)ft_strlen(s);
	if (nb != 0 && p->sharp == 2)
	{
		p->width -= 2;
		if (p->convers == 'x')
		{
			ft_lowercase(s);
			c_putstr("0x");
		}
		else
			c_putstr("0X");
	}
	if (p->minus != 1)
		print_spaces(p, len);
	c_putstr(s);
	if (p->minus == 1)
		print_spaces(p, len);
}
