/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 11:12:16 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/19 11:12:17 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_percent(t_printf *p)
{
	int i;

	i = 0;
	if (p->minus != 1)
		print_spaces(p, 1);
	while (ft_strchr("-+.0123456789 hljz", p->arg[i]) && p->arg[i])
		i++;
	if (p->arg[i] == '%')
		c_putchar('%');
	else
	{
		while (p->arg[i] && p->arg[i] != '%')
		{
			c_putchar(p->arg[i]);
			i++;
		}
	}
	if (p->minus == 1)
		print_spaces(p, 1);
}

void	put_arg(t_printf *p, va_list ap)
{
	if (p->convers == 'd' || p->convers == 'i')
		put_d_i(p, ap);
	else if (p->convers == 'D')
		put_long_d(p, ap);
	else if (p->convers == 'o')
		put_octal(p, ap);
	else if (p->convers == 'O')
		put_long_octal(p, ap);
	else if (p->convers == 'X' || p->convers == 'x')
		put_hex(p, ap);
	else if (p->convers == 'u')
		put_unsigned_i(p, ap);
	else if (p->convers == 'U')
		put_unsigned_long_i(p, ap);
	else if (p->convers == 's')
		put_string(p, ap);
	else if (p->convers == 'c' || p->convers == 'C')
		put_char(p, ap);
	else if (p->convers == 'S')
		put_string_unicode(p, ap);
	else if (p->convers == 'p')
		put_pointer(p, ap);
	else
		put_percent(p);
}
