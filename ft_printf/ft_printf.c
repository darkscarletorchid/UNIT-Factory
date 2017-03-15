/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 18:58:57 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/12 19:13:45 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	char *str = (char *)format;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == '%')
				c_putchar(*str);
			else
				str += check_conversion(str, ap);
		}
		c_putchar(*str);
		str++;
	}
	va_end(ap);
	return (count);
}

int main()
{
	//int d = 2665;
	unsigned long int t = 4559898552222;
	//int t = 100;
	char f = 'A';

//	int c = ft_printf("fopojjoij%25s llll %6D %3d\n", "kokokkokokoko", t, f);
//	int p = printf("fopojjoij%25s llll %6ld%+4d\n", "kokokkokokoko", t, f);
	//
	signed char b = 'a';
	int c = ft_printf("fopojjoij %hhd\n", b);
	int p = printf("fopojjoij %hhd\n", b);
	printf("\n%d\n", c);
	printf("\n%d\n", p);
	return (0);
}