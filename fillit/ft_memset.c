/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:00:04 by atrepyto          #+#    #+#             */
/*   Updated: 2016/11/30 10:04:37 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char *d;

	d = b;
	while (len != 0)
	{
		*d++ = c;
		len--;
	}
	return (b);
}
