/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 12:26:16 by exam              #+#    #+#             */
/*   Updated: 2017/03/20 17:28:09 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(long long int value, int base)
{
	const char		*hex;
	char			*res;
	int				len;
	long long int	temp;

	hex = "0123456789ABCDEF";
	temp = value;
	if (base < 2 || base > 16)
		return (0);
	len = nblen(value, base);
	res = (char *)malloc(sizeof(char) * len + 1);
	res[len] = '\0';
	--len;
	if (temp == 0)
		res[len] = '0';
	while (temp)
	{
		res[len] = hex[temp < 0 ? -(temp % base) : (temp % base)];
		temp = temp / base;
		len--;
	}
	if (value < 0 && base == 10)
		res[len] = '-';
	return (res);
}
