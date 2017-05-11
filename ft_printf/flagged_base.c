/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagged_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 14:12:09 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/20 14:12:55 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	h_flag3(t_printf *p, va_list ap, int base)
{
	unsigned short int	nb;

	nb = (unsigned short)va_arg(ap, unsigned int);
	if (p->convers == 'x' || p->convers == 'X')
		base_output(p, nb, base);
	else if (p->convers == 'o' || p->convers == 'O')
		output_octal(p, nb, base);
}

void	hh_flag3(t_printf *p, va_list ap, int base)
{
	unsigned char	nb;

	nb = (unsigned char)va_arg(ap, unsigned int);
	if (p->convers == 'x' || p->convers == 'X')
		base_output(p, nb, base);
	else if (p->convers == 'o' || p->convers == 'O')
		output_octal(p, nb, base);
}

void	l_flag3(t_printf *p, va_list ap, int base)
{
	unsigned long	nb;

	nb = va_arg(ap, unsigned long);
	if (p->convers == 'x' || p->convers == 'X')
		base_output(p, nb, base);
	else if (p->convers == 'o' || p->convers == 'O')
		output_octal(p, nb, base);
}

void	z_flag3(t_printf *p, va_list ap, int base)
{
	size_t	nb;

	nb = va_arg(ap, size_t);
	if (p->convers == 'x' || p->convers == 'X')
		base_output(p, nb, base);
	else if (p->convers == 'o' || p->convers == 'O')
		output_octal(p, nb, base);
}

void	j_flag3(t_printf *p, va_list ap, int base)
{
	intmax_t	nb;

	nb = va_arg(ap, intmax_t);
	if (p->convers == 'x' || p->convers == 'X')
		base_output(p, nb, base);
	else if (p->convers == 'o' || p->convers == 'O')
		output_octal(p, nb, base);
}
