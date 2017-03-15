/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 17:43:50 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/15 17:44:28 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags(t_printf *p)
{
	char *s;

	s = p->arg;
	while (*s)
	{
		if (*s == '-')
			p->minus = 1;
		else if (*s == '+')
			p->plus = 1;
		else if (*s == '0')
			p->zero = 1;
		else if (*s == '#')
			p->sharp = 2;
		else if (*s == ' ')
			p->space = 1;
		s++;
	}
}

void	length_flags(t_printf *p, char *s)
{
	while (*s)
	{
		if (ft_strchr("hljz", *s))
		{
			if (*(s + 1) == 'h' || *(s + 1) == 'l')
				p->length = ft_strndup(s, 2);
			else
				p->length = ft_strndup(s, 1);
			break ;
		}
		s++;
	}
}

void	parse_arg(t_printf *p)
{
	char *s;

	flags(p);
	s = p->arg;
	while (ft_strchr("+-0# ", *s) && *s)
		++s;
	p->width = ft_atoi(s);
	while (*s)
	{
		if (*s == '.')
		{
			p->precision = ft_atoi(s + 1);
			break ;
		}
		s++;
	}
	length_flags(p, s);
}

int		check_conversion(char *format, va_list ap)
{
	size_t		i;
	t_printf	p;

	i = 0;
	p.convers = '0';
	while (format[i])
	{
		if (ft_strchr("sSpdDioOuUxXcC", format[i]))
		{
			p.convers = format[i];
			break ;
		}
		i++;
	}
/*
** if (p.convers == '0')
**		undefined_behaviour(); UNDEFINED BEHAVIOUR if conversion not found
*/
	p.arg = ft_strndup(format, i + 1);
	parse_arg(&p);
	put_arg(&p, ap);
	return ((int)ft_strlen(p.arg));
}
