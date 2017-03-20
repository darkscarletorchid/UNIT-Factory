/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchars.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 13:15:43 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/20 13:18:18 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	precision_str(t_printf *p, int len, char *s, wint_t *str)
{
	int i;
	int j;
	int cl;
	int temp;

	if (len > p->precision)
		len = p->precision;
	if (p->minus != 1)
		print_spaces(p, len);
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
	i = -1;
	while (++i < cl && s[i])
		c_putchar(s[i]);
	if (p->minus == 1)
		print_spaces(p, cl);
}

void	exist_str_unicode(t_printf *p, char *s, wint_t *str)
{
	int len;

	len = ft_strlen(s);
	if (p->precision < 0)
	{
		if (p->minus != 1)
			print_spaces(p, len);
		c_putstr(s);
		if (p->minus == 1)
			print_spaces(p, len);
	}
	else
		precision_str(p, len, s, str);
}

void	put_string_unicode(t_printf *p, va_list ap)
{
	wchar_t	*s;
	char	*str;

	s = va_arg(ap, wint_t*);
	str = get_str(s);
	if (!s)
		null_string(p, "(null)");
	else
		exist_str_unicode(p, str, s);
}
