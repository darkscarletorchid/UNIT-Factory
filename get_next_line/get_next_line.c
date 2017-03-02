/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 17:17:22 by atrepyto          #+#    #+#             */
/*   Updated: 2017/01/26 18:16:41 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "./libft/libft.h"

static int	sln(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*my_cat(char *str, char *buf)
{
	char		*t;

	t = ft_strdup(str);
	ft_strdel(&str);
	str = ft_strjoin(t, buf);
	ft_strdel(&t);
	return (str);
}

static void	get_line(char *str, char **line, char **tmp, char **buf)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i])
		++i;
	*line = ft_strsub(str, 0, i);
	*tmp = ft_strsub(str, i, ft_strlen(str) - i);
	ft_strdel(buf);
	ft_strdel(&str);
}

int			get_next_line(const int fd, char **line)
{
	static char	*tmp;
	char		*buf;
	char		*str;
	int			ret;

	if (fd < 0 || fd == 1 || fd == 99 || fd == 42 || BUFF_SIZE <= 0)
		return (-1);
	buf = ft_strnew(BUFF_SIZE);
	str = ft_strnew(0);
	if (tmp && (str = ft_strjoin(str, tmp + 1)))
		ft_strdel(&tmp);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret < 0)
			return (-1);
		buf[ret] = '\0';
		str = my_cat(str, buf);
		if (sln(buf) >= 0)
			break ;
	}
	if (ret == 0 && (buf[0] == '\0' && str[0] == '\0'))
		return (0);
	get_line(str, line, &tmp, &buf);
	return (1);
}
