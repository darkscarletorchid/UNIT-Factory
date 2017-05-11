/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:27:24 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/20 17:27:47 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
