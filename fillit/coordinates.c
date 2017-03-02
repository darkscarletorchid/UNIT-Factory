/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:27:19 by atrepyto          #+#    #+#             */
/*   Updated: 2017/01/13 16:34:41 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		**ft_coordinate(char *str, int x, int y)
{
	int i;
	int j;
	int **cd;

	i = -1;
	j = -1;
	cd = (int **)malloc(sizeof(int*) * 4);
	while (str[++i])
	{
		if (str[i] == '.')
			x++;
		else if (str[i] == '\n')
		{
			x = 1;
			y = y + 1;
		}
		else
		{
			cd[++j] = (int *)malloc(sizeof(int) * 2);
			cd[j][0] = x;
			cd[j][1] = y;
			x++;
		}
	}
	return (cd);
}

int		*find_min(int **cd)
{
	int i;
	int ytemp;
	int xtemp;
	int *min;

	i = 0;
	min = (int *)malloc(sizeof(int) * 2);
	xtemp = cd[i][0];
	while (i < 3)
	{
		if (xtemp > cd[i + 1][0])
			xtemp = cd[i + 1][0];
		i++;
	}
	min[0] = xtemp;
	i = 0;
	ytemp = cd[i][1];
	while (i < 3)
	{
		if (ytemp > cd[i + 1][1])
			ytemp = cd[i + 1][1];
		i++;
	}
	min[1] = ytemp;
	return (min);
}

int		*find_max(int **cd)
{
	int i;
	int ytemp;
	int xtemp;
	int *max;

	i = 0;
	max = (int *)malloc(sizeof(int) * 2);
	xtemp = cd[i][0];
	while (i < 3)
	{
		if (xtemp < cd[i + 1][0])
			xtemp = cd[i + 1][0];
		i++;
	}
	max[0] = xtemp;
	i = 0;
	ytemp = cd[i][1];
	while (i < 3)
	{
		if (ytemp < cd[i + 1][1])
			ytemp = cd[i + 1][1];
		i++;
	}
	max[1] = ytemp;
	return (max);
}
