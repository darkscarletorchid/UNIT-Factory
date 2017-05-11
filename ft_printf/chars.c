/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 19:06:20 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/15 19:06:24 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	null_string(t_printf *p, char *s)
{
	int len;
	int i;

	if (p->precision < 0)
	{
		len = ft_strlen(s);
		if (p->minus != 1)
			print_spaces(p, len);
		c_putstr(s);
		if (p->minus == 1)
			print_spaces(p, len);
	}
	else
	{
		len = p->precision;
		if (p->minus != 1)
			print_spaces(p, len);
		i = -1;
		while (++i < len)
			c_putchar(s[i]);
		if (p->minus == 1)
			print_spaces(p, len);
	}
}

void	exist_str(t_printf *p, char *s)
{
	int len;
	int i;

	if (p->precision < 0)
	{
		len = ft_strlen(s);
		if (p->minus != 1)
			print_spaces(p, len);
		c_putstr(s);
		if (p->minus == 1)
			print_spaces(p, len);
	}
	else
	{
		len = ft_strlen(s);
		if (len > p->precision)
			len = p->precision;
		if (p->minus != 1)
			print_spaces(p, len);
		i = -1;
		while (++i < len && s[i])
			c_putchar(s[i]);
		if (p->minus == 1)
			print_spaces(p, len);
	}
}

void	put_string(t_printf *p, va_list ap)
{
	char	*s;

	s = va_arg(ap, char *);
	if (s == NULL)
		null_string(p, "(null)");
	else
		exist_str(p, s);
}

void	put_char(t_printf *p, va_list ap)
{
	char c;

	c = (char)va_arg(ap, int);
	if (p->minus != 1)
		print_spaces(p, 1);
	c_putchar(c);
	if (p->minus == 1)
		print_spaces(p, 1);
}
