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
		else if (ft_strchr("sSpdDioOuUxXcChljz123456789%", *s))
			break ;
		s++;
	}
}

void	length_flags(t_printf *p, char *s)
{
	int i;
	int j;

	j = 0;
	while (s[j])
	{
		if (ft_strchr("hljz", s[j]))
		{
			i = j;
			while(!ft_strchr("sSpdDioOuUxXcC%", s[i]))
				i++;
			//if (*(s + 1) == 'h' || *(s + 1) == 'l')
			//	p->length = ft_strsub(s, 0, 2);
			if (s[j] == 'l' && i > 1)
				p->length = ft_strdup("ll");
			else if (s[j] == 'h' && i > 1)
				p->length = ft_strdup("hh");
			else
				p->length = ft_strsub(s, 0, i);
			//else
			//	p->length = ft_strsub(s, 0, 1);
			break ;
		}
		j++;
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
	p->precision = -1;
	while (*s)
	{
		if (*s == '-')
		{
			p->minus = 1;
			if (ft_atoi(s + 1))
				p->width = ft_atoi(s + 1);
		}
		if (*s == '.')
			p->precision = ft_atoi(s + 1);
		if (ft_strchr("sSpdDioOuUxXcC%hljz", *s))
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
}
int		check_conversion(char *format, va_list ap)
{
	size_t		i;
	t_printf	p;

	i = 0;
	null_struct(&p);
	p.convers = '0';
	while (format[i])
	{
		if (ft_strchr("%sSpdDioOuUxXcC", format[i]))
		{
			p.convers = format[i];
			i++;
			break ;
		}
		i++;
	}
/*
** if (p.convers == '0')
**		undefined_behaviour(); UNDEFINED BEHAVIOUR if conversion not found
*/
	p.arg = ft_strsub(format, 0, i);
//	printf("arg %s\n", p.arg);
	parse_arg(&p);
	put_arg(&p, ap);
	return (ft_strlen(p.arg));
}
