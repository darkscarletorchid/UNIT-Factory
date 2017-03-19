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

int		charlen(wint_t c)
{
	int len;

	if (c <= 0x7F)
		len = 1;
	else if (c <= 0x7FF)
		len = 2;
	else if (c <= 0xFFFF)
		len = 3;
	else if (c <= 0x10FFFF)
		len = 4;
	return (len);
}

void	exist_str_unicode(t_printf *p, char *s, wint_t *str)
{
	int len;
	int i;
	int j;
	int cl;
	int temp;

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
		j = 0;
		temp = 0;
		cl = 0;
		while (cl < len && str[j])
		{
			temp += charlen(str[j]);
			if (temp <= len)
				cl = temp;
			j++;
		}
		while (++i < cl && s[i])
			c_putchar(s[i]);
		if (p->minus == 1)
			print_spaces(p, cl);
	}
}

void	put_string_unicode(t_printf *p, va_list ap)
{
	wint_t	*s;
	char	*str;

	s = va_arg(ap, wint_t *);
	str = get_str(s);
	if (!s)
		null_string(p, "(null)");
	else
		exist_str_unicode(p, str, s);
}

void	put_char(t_printf *p, va_list ap)
{
	char c;

	c = (char) va_arg(ap, int);
	if (p->minus != 1)
		print_spaces(p, 1);
	c_putchar(c);
	if (p->minus == 1)
		print_spaces(p, 1);
}
