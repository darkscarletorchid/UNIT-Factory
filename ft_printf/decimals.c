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
			w = p->width - p->precision - 1;
		else
			w = p->width - 1;
		while (w > 0)
		{
			c_putchar(' ');
			w--;
		}
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
	}
}

void	unflagged_di(t_printf *p, va_list ap)
{
	int			len;
	long int	nb;
	int			prec;
	int 		w;
	int			i;
	int flag;


	nb = va_arg(ap, int);
	prec = 0;
	len = nblen(nb, 10);
	if (nb == 0)
		number_zero(p);
	else
	{
		flag = nb < 0 ? 1 : 0;
		if (p->precision >= len)
			prec = p->precision - len + flag;
		if ((p->space || p->plus) && nb > 0)
			len++;
		w = p->width - prec - len;
		while (w > 0 && p->minus != 1 && (p->zero != 1 || (p->zero == 1 && p->precision >0)))
		{
			c_putchar(' ');
			w--;
		}
		if (p->space == 1 && p->plus != 1 && nb >= 0 )
			c_putchar(' ');
		if (p->plus == 1 && nb >= 0 && flag != 1)
			c_putchar('+');
		if (flag == 1)
		{
			c_putchar('-');
			nb = -nb;
		}
		while (w > 0 && p->minus != 1 && p->zero == 1 && prec == 0)
		{
			c_putchar('0');
			w--;
		}
		i = -1;
		while (++i < prec)
			c_putchar('0');
		c_putnbr(nb);
		while (w > 0 && p->minus == 1)
		{
			c_putchar(' ');
			w--;
		}
		while (w > 0 && p->minus == 1 && p->zero == 1 && prec == 0)
		{
			c_putchar('0');
			w--;
		}
	}
}

void	put_d_i(t_printf *p, va_list ap)
{
	if (p->length && p->length[0] != '\0') {
		if (ft_strcmp("h", p->length) == 0)
		{
			h_flag(p, ap);
		//	ft_strdel(&p->length);
		}
		else if (ft_strcmp("hh", p->length) == 0)
		{
			hh_flag(p, ap);
	//		ft_strdel(&p->length);
		}
		else if (ft_strcmp("l", p->length) == 0)
		{
			put_long_d(p, ap);
	//		ft_strdel(&p->length);
		}
		else if (ft_strcmp("ll", p->length) == 0)
		{
			ll_flag(p, ap);
	//		ft_strdel(&p->length);
		}
		else if (ft_strcmp("z", p->length) == 0)
		{
			z_flag(p, ap);
	//		ft_strdel(&p->length);
		}
		else if (ft_strcmp("j", p->length) == 0)
		{
			j_flag(p, ap);
	//		ft_strdel(&p->length);
		}
	}
	else
		unflagged_di(p, ap);
}

void	put_long_d(t_printf *p, va_list ap)
{
	int			len;
	long long int	nb;
	//size_t nb;
	int			prec;
	int 		w;
	int			i;
	int flag;

	nb = va_arg(ap, long int);
	prec = 0;
	len = nblen(nb, 10);
	if (nb == 0)
		number_zero(p);
	else
	{
		flag = nb < 0 ? 1 : 0;
		if (p->precision >= len)
			prec = p->precision - len + flag;
		if ((p->space || p->plus) && nb > 0)
			len++;
		w = p->width - prec - len;
		while (--w >= 0 && p->minus != 1 && (p->zero != 1 || (p->zero == 1 && p->precision >0)))
			c_putchar(' ');
		if (p->space == 1 && p->plus != 1 && nb >= 0 )
			c_putchar(' ');
		if (p->plus == 1 && nb >= 0 && flag != 1)
			c_putchar('+');
		if (flag == 1)
		{
			c_putchar('-');
			nb = -nb;
		}
		while (--w >= 0 && p->minus != 1 && p->zero == 1 && prec == 0)
			c_putchar('0');
		i = -1;
		while (++i < prec)
			c_putchar('0');
		c_putnbr(nb);
		while (--w >= 0 && p->minus == 1)
			c_putchar(' ');
//		while (--w >= 0 && p->minus == 1 && p->zero == 1 && prec == 0)
//			c_putchar('0');
	}
}
