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