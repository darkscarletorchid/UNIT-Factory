/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 18:58:57 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/25 10:16:43 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	format_str(char *str, va_list ap)
{
	int len;
	int i;

	i = 0;
	len = ft_strlen(str);
	while (str[i] && i < len)
	{
		if (str[i] == '%' && str[i + 1] == '%')
		{
			c_putchar(str[i]);
			i += 2;
		}
		else if (str[i] == '%')
		{
			i++;
			if (str[i] != '\0')
				i += check_conversion(str + i, ap);
		}
		else
		{
			c_putchar(str[i]);
			i++;
		}
	}
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*str;

	g_count = 0;
	va_start(ap, format);
	str = (char *)format;
	format_str(str, ap);
	va_end(ap);
	return (g_count);
}
