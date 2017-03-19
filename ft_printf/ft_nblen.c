//
// Created by Anastasiia Trepyton on 3/15/17.
//
#include "libft.h"

int		nblen(long long int nb, int base)
{
	int i;

	i = 0;
	if (nb == 0)
		i++;
	if (nb < 0 && base == 10)
		i++;
	while (nb)
	{
		nb = nb / base;
		i++;
	}
	return (i);
}

int		unsigned_nblen(unsigned long int nb, int base)
{
	int i;

	i = 0;
	if (nb == 0)
		i++;
	while (nb)
	{
		nb = nb / base;
		i++;
	}
	return (i);
}