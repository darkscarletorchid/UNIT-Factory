/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 17:43:50 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/25 10:19:45 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flags(t_printf *p, char *s)
{
	int i;

	i = 0;
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
		else if (ft_strchr(".sSpdDioOuUxXcCb123456789%", *s))
		{
			i++;
			break ;
		}
		s++;
		i++;
	}
	return (i);
}

void	length_flags(t_printf *p, char *s)
{
	int j;

	j = -1;
	while (s[++j])
	{
		if (ft_strchr("hljz", s[j]))
		{
			if (s[j] == 'l' || s[j] == 'h')
			{
				if (s[j + 1] == 'l' || s[j + 1] == 'h')
					p->length = ft_strsub(s, 0, 2);
				else if (s[++j] == ' ')
					undef_flag(p, j, s);
				else
					p->length = ft_strsub(s, 0, 1);
			}
			else
				p->length = ft_strsub(s, 0, 1);
			break ;
		}
	}
}

void	parse_arg(t_printf *p)
{
	char *s;

	flags(p, p->arg);
	s = p->arg;
	while (ft_strchr("+-0# ", *s) && *s)
		++s;
	p->width = ft_atoi(s);
	p->precision = -1;
	while (*s)
	{
		if (*s == '-')
		{
			p->minus = 1;
			if (ft_atoi(s + 1))
				p->width = ft_atoi(s + 1);
		}
		else if (*s == '.')
			p->precision = ft_atoi(s + 1);
		else if (ft_strchr("+-# ", *s))
			flags(p, s);
		if (ft_strchr("sSpdDioOuUxXcCb%hljz", *s))
			break ;
		s++;
	}
	length_flags(p, s);
}

void	null_struct(t_printf *p)
{
	p->sharp = 0;
	p->zero = 0;
	p->minus = 0;
	p->plus = 0;
	p->space = 0;
	p->width = 0;
	p->precision = 0;
	p->length = ft_strnew(0);
}

int		check_conversion(char *format, va_list ap)
{
	int			i;
	t_printf	p;

	i = -1;
	null_struct(&p);
	while (format[++i])
	{
		if (!ft_strchr("-+.# 0123456789hljz%bsSpdDioOuUxXcC", format[i]))
		{
			p.convers = format[i];
			break ;
		}
		else if (ft_strchr("%sSpdDioOuUxXcCb", format[i])
			|| format[i + 1] == '\0')
		{
			p.convers = format[i];
			break ;
		}
	}
	p.arg = ft_strsub(format, 0, i + 1);
	i = ft_strlen(p.arg);
	parse_arg(&p);
	put_arg(&p, ap);
	ft_strdel(&p.length);
	return (i);
}
