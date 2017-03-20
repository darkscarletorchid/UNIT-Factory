/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide_chars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 13:21:42 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/20 13:21:43 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		wint_convert(char **dest, wint_t *str, int i, int *a)
{
	if (str[i] <= 0x7FF)
	{
		(*dest)[(*a)++] = (char)(((str[i] & 0x07c0) >> 6) + 0xC0);
		(*dest)[(*a)++] = (char)((str[i] & 0x3F) + 0x80);
	}
	else if (str[i] <= 0xFFFF)
	{
		(*dest)[(*a)++] = (char)(((str[i] & 0xF000) >> 12) + 0xE0);
		(*dest)[(*a)++] = (char)(((str[i] & 0x0Fc0) >> 6) + 0x80);
		(*dest)[(*a)++] = (char)((str[i] & 0x3F) + 0x80);
	}
	else if (str[i] <= 0x10FFFF)
	{
		(*dest)[(*a)++] = (char)(((str[i] & 0x1c0000) >> 18) + 0xF0);
		(*dest)[(*a)++] = (char)(((str[i] & 0x03F000) >> 12) + 0x80);
		(*dest)[(*a)++] = (char)(((str[i] & 0x0Fc0) >> 6) + 0x80);
		(*dest)[(*a)++] = (char)((str[i] & 0x3F) + 0x80);
	}
}

char			*convert_to_char(char *dest, wint_t *str)
{
	int		i;
	int		a;

	i = 0;
	a = 0;
	while (str[i])
	{
		if (str[i] <= 0x7F)
			dest[a++] = (char)str[i];
		else
			wint_convert(&dest, str, i, &a);
		i++;
	}
	dest[a] = '\0';
	return (dest);
}

int				wide_strlen(wint_t *str)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] <= 0x7F)
			len += 1;
		else if (str[i] <= 0x7FF)
			len += 2;
		else if (str[i] <= 0xFFFF)
			len += 3;
		else if (str[i] <= 0x10FFFF)
			len += 4;
		i++;
	}
	return (len);
}

char			*get_str(wint_t *str)
{
	char *dest;

	if (!str)
	{
		dest = ft_strdup("(null)");
		return (dest);
	}
	else
	{
		dest = ft_strnew(wide_strlen(str));
		dest = convert_to_char(dest, str);
		return (dest);
	}
}
