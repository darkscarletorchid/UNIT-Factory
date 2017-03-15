//
// Created by Anastasiia Trepyton on 3/13/17.
//

#include "ft_printf.h"

void	flags(t_printf p)
{
	char *s = p.arg;
	while (*s)
	{
		if (*s == '-')
			p.minus = 1;
		else if (*s == '+')
			p.plus = 1;
		else if (*s == '0')
			p.zero = 1;
		else if (*s == '#')
			p.sharp = 1;
		else if (*s == ' ')
			p.space = 1;
		s++;
	}
}

void	put_arg(t_printf p, va_list ap)
{
	char *s;

	if (p.convers == 'd' || p.convers == 'i')
		c_putnbr(va_arg(ap, int));
	else if (p.convers == 'u')
		c_putnbr(va_arg(ap, unsigned int));
	else if (p.convers == 'U')
		c_putnbr(va_arg(ap, unsigned long int));
	else if (p.convers == 's')
		c_putstr(va_arg(ap, char *));
	else if (p.convers == 'c')
		c_putchar((char)va_arg(ap, int));
	else if (p.convers == 'X' || p.convers == 'x')
	{
		s =  ft_itoa_base(va_arg(ap, int), 16);
		if (p.convers == 'x')
			ft_lowercase(s);
		c_putstr(s);
		ft_strdel(&s);
	}
	else if (p.convers == 'o')
	{
		s =  ft_itoa_base(va_arg(ap, int), 8);
		c_putstr(s);
		ft_strdel(&s);
	}
}

int	check_conversion(char *format, va_list ap)
{
	int i;
	t_printf p;

	i = 0;
	while (format[i])
	{
		if (ft_strchr("sSpdDioOuUxXcC", format[i]))
		{
			p.convers = format[i];
			break;
		}
		i++;
	}
	p.arg = ft_strndup(format, i + 1);
	flags(p);
	put_arg(p, ap);
	return (ft_strlen(p.arg));
}
