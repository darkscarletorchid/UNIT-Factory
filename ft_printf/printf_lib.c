//
// Created by Anastasiia Trepyton on 3/13/17.
//

#include "ft_printf.h"

void	c_putchar(char c)
{
	write(1, &c, 1);
	count++;
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
			count++;
			i++;
		}
	}
}

void	c_putnbr(unsigned long long int nb)
{
//	if (nb < 0) {
//		write(1, "-", 1);
//		count++;
//		nb = -nb;
//	}
	if (nb >= 10) {
		c_putnbr(nb / 10);
		c_putnbr(nb % 10);
	}
	if (nb >= 0 && nb <= 9) {
		nb = nb + '0';
		write(1, &nb, 1);
		count++;
	}
}
