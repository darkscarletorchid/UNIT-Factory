/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 10:44:00 by atrepyto          #+#    #+#             */
/*   Updated: 2016/11/28 11:00:14 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}
