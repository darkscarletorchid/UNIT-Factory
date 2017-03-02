/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:01:37 by atrepyto          #+#    #+#             */
/*   Updated: 2017/01/13 18:52:01 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		ft_validate(char *str)
{
	int	i;
	int tag;
	int	connection;

	i = -1;
	tag = 0;
	connection = 0;
	while (str[++i])
	{
		if (str[i] == '#')
		{
			tag++;
			if (str[i + 1] == '#' && i < 20)
				connection++;
			if (str[i + 5] == '#' && i < 20)
				connection++;
			if (str[i - 1] == '#' && i > 0)
				connection++;
			if (str[i - 5] == '#' && i > 0)
				connection++;
		}
	}
	if (tag != 4 || (connection != 6 && connection != 8))
		ft_error();
	return (1);
}

void	ft_valid_file(char *str, int i)
{
	int		j;
	int		count;

	j = 0;
	count = 0;
	if (str[i] != '.' && str[i] != '#')
		ft_error();
	while (str[i])
	{
		while (str[i] != '\n')
		{
			if (str[i] == '.' || str[i] == '#')
				count++;
			i++;
		}
		j++;
		if (str[i + 1] == '\n' || str[i + 1] == '\0')
		{
			if (count != 16 || j < 4)
				ft_error();
			count = 0;
		}
		i++;
	}
}

int		ft_count(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] != '\n')
		{
			if (str[i] == '.' || str[i] == '#')
				count++;
			if (str[i + 1] == '\n' && count % 4 != 0)
				ft_error();
			i++;
		}
		i++;
	}
	if (count == 16)
		return (1);
	return (0);
}
