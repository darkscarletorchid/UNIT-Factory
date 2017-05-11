/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_lib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 13:37:36 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/20 13:37:42 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	c_putchar(char c)
{
	write(1, &c, 1);
	g_count++;
}

void	c_putstr(char *str)
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			write(1, &str[i], 1);
			g_count++;
			i++;
		}
	}
}

void	c_putnbr(unsigned long long nb)
{
	if (nb >= 10)
	{
		c_putnbr(nb / 10);
		c_putnbr(nb % 10);
	}
	if (nb == 0 || (nb > 0 && nb <= 9))
	{
		nb = nb + '0';
		write(1, &nb, 1);
		g_count++;
	}
}
