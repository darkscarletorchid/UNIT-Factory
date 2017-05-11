/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagged_decimals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 14:10:41 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/20 14:10:45 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	h_flag(t_printf *p, va_list ap)
{
	short int	nb;

	nb = (short)va_arg(ap, int);
	output_int(nb, p);
}

void	hh_flag(t_printf *p, va_list ap)
{
	signed char	nb;

	nb = (signed char)va_arg(ap, int);
	output_int(nb, p);
}

void	ll_flag(t_printf *p, va_list ap)
{
	long long int	nb;

	nb = va_arg(ap, long long int);
	output_int(nb, p);
}

void	z_flag(t_printf *p, va_list ap)
{
	size_t	nb;

	nb = va_arg(ap, size_t);
	output_int(nb, p);
}

void	j_flag(t_printf *p, va_list ap)
{
	intmax_t	nb;

	nb = va_arg(ap, intmax_t);
	output_int(nb, p);
}
