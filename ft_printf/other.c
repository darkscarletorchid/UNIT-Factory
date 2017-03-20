/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 18:46:54 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/15 18:46:57 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_spaces(t_printf *p, int len)
{
	char c;

	c = ' ';
	if (p->zero == 1 && p->minus != 1)
		c = '0';
	while (p->width - len > 0)
	{
		c_putchar(c);
		len++;
	}
}

void	add_width(t_printf *p, int len)
{
	while (p->width - len > 0)
	{
		c_putchar(' ');
		len++;
	}
}

void	undef_flag(t_printf *p, int j, char *s)
{
	while (s[j] == ' ' && s[j])
		j++;
	if (s[j] == 'l')
		p->length = ft_strdup("ll");
	else if (s[j] == 'h')
		p->length = ft_strdup("hh");
}

void	ox_kostyl(int flag, t_printf *p)
{
	if (flag && p->convers == 'x')
		c_putstr("0x");
	else if (flag && p->convers == 'X')
		c_putstr("0X");
	else if (flag && p->convers == 'o')
		c_putstr("0");
	else if (flag && p->convers == 'O')
		c_putstr("0");
}

void	space_kostyl(t_output *o, t_printf *p)
{
	while (o->w > 0 && p->minus != 1 &&
		   (p->zero != 1 || (p->zero == 1 && p->precision > 0)))
	{
		c_putchar(' ');
		o->w--;
	}
}
