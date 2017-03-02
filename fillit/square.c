/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:32:33 by atrepyto          #+#    #+#             */
/*   Updated: 2017/01/13 16:37:55 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void		ft_del(char **d)
{
	int		i;

	i = 0;
	while (d[i])
	{
		free(d[i]);
		i++;
	}
	free(d);
}

void		free_square(t_square **square)
{
	free(*square);
	*square = NULL;
}

void		ft_sqroutput(char **square)
{
	int i;

	i = -1;
	while (square[++i])
		ft_putendl(square[i]);
}

int			ft_sqrlen(int len)
{
	int sqrsize;
	int i;

	i = 2;
	sqrsize = len * 4;
	while (i * i < sqrsize)
		i++;
	return (i);
}

t_square	*ft_square(int len)
{
	t_square	*square;
	int			k;

	k = 0;
	square = (t_square*)malloc(sizeof(t_square));
	square->size = ft_sqrlen(len);
	if (!(square->field = (char **)malloc(sizeof(char*) * square->size + 1)))
		return (NULL);
	while (k < square->size)
	{
		square->field[k] = (char *)malloc(sizeof(char) * square->size + 1);
		ft_memset(square->field[k], '.', square->size);
		square->field[k][square->size] = '\0';
		k++;
	}
	square->field[k] = 0;
	return (square);
}
