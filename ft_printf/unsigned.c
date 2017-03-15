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

void	put_unsigned_i(t_printf *p, va_list ap)
{
	int				len;
	unsigned int	nb;

	nb = va_arg(ap, unsigned int);
	len = unsigned_nblen(nb, 10);
	if (p->minus != 1)
		print_spaces(p, len);
	c_putnbr(nb);
	if (p->minus == 1)
		print_spaces(p, len);
}

void	put_unsigned_long_i(t_printf *p, va_list ap)
{
	int					len;
	unsigned long int	nb;

	nb = va_arg(ap, unsigned long int);
	len = unsigned_nblen(nb, 10);
	if (p->minus != 1)
		print_spaces(p, len);
	c_putnbr(nb);
	if (p->minus == 1)
		print_spaces(p, len);
}