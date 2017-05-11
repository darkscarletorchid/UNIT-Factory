/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagged_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 14:15:20 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/20 14:15:21 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	h_flag2(t_printf *p, va_list ap)
{
	unsigned short int	nb;

	nb = (unsigned short)va_arg(ap, unsigned int);
	output_unsigned(p, nb);
}

void	hh_flag2(t_printf *p, va_list ap)
{
	unsigned char	nb;

	nb = (unsigned char)va_arg(ap, unsigned int);
	output_unsigned(p, nb);
}

void	ll_flag2(t_printf *p, va_list ap)
{
	unsigned long long	nb;

	nb = va_arg(ap, unsigned long long);
	output_unsigned(p, nb);
}

void	z_flag2(t_printf *p, va_list ap)
{
	size_t	nb;

	nb = va_arg(ap, size_t);
	output_unsigned(p, nb);
}

void	j_flag2(t_printf *p, va_list ap)
{
	intmax_t	nb;

	nb = va_arg(ap, intmax_t);
	output_unsigned(p, nb);
}
