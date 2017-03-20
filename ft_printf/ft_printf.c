/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 18:58:57 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/20 09:58:43 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	int		i;
	char	*str;

	i = 0;
	g_count = 0;
	va_start(ap, format);
	str = (char *)format;
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
			i += check_conversion(str + i, ap);
		}
		else
		{
			c_putchar(str[i]);
			i++;
		}
	}
	va_end(ap);
	return (g_count);
}

//int main()
//{
//	//int d = 2665;
////	unsigned long int t = 4559898552222;
////	//int t = 100;
////	char f = 'A';
////
////	int c = ft_printf("fopojjoij%25s llll %6D %3d\n", "kokokkokokoko", t, f);
////	int p = printf("fopojjoij%25s llll %6ld%+4d\n", "kokokkokokoko", t, f);
////	//
////	long int b = 2626262626262;
////	const char A[] = "this is tEEEEst!";
//
//	//int c = ft_printf("%d dff%C ffdsf%s dsfewf%d wefwef%u wef%X efwww%c\n", 100, 'a', "qwerty", -56, 8885, 26, 'a');
//	int c = ft_printf("%22llu", 9223372036854775808);
//	int p = printf("%22llu", 9223372036854775808);
//	printf("\n%d\n", c);
//	printf("\n%d\n", p);
//
//	ft_printf("%@@\n", L"@@");
//	printf("%@@\n", L"%@@");
//	return (0);
//}
