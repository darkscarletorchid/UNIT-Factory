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
	int len;
	int i;

	i = 0;
	va_start(ap, format);
	char *str = (char *)format;
	len = ft_strlen(str);
	while (str[i] && i < len)
	{
		if (str[i] == '%')
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
	return (count);
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
//	int c = ft_printf("%d%10%des%s\n",100, "Ly");
//	int p = printf("%d%10%des%s\n",100, "Ly");
//	printf("\n%d\n", c);
//	printf("\n%d\n", p);
//	return (0);
//}