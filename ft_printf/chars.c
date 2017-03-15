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

void	put_string(t_printf *p, va_list ap)
{
	int		len;
	char	*s;

	s = va_arg(ap, char *);
	len = ft_strlen(s);
	if (p->minus != 1)
		add_width(p, len);
	c_putstr(s);
	if (p->minus == 1)
		add_width(p, len);
}

//void	put_wide_str(t_printf *p, va_list ap);

void	put_char(t_printf *p, va_list ap)
{
	char c;

	c = (char)va_arg(ap, int);
	if (p->minus != 1)
		add_width(p, 1);
	c_putchar(c);
	if (p->minus == 1)
		add_width(p, 1);
}

//void	put_wide_char(t_printf *p, va_list ap);
//void	put_pointer(t_printf *p, va_list ap);