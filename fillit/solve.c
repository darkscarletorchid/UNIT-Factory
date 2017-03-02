/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:13:15 by atrepyto          #+#    #+#             */
/*   Updated: 2017/01/13 17:40:43 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int		ft_checkput(t_lst *list, char **field, int x, int y)
{
	int **cd;
	int *min;
	int i;

	cd = list->cd;
	min = list->min;
	i = 0;
	while (i < 4)
	{
		if ((field[y + cd[i][1] - min[1]][x + cd[i][0] - min[0]]) != '.')
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		field[y + cd[i][1] - min[1]][x + cd[i][0] - min[0]] = list->letter;
		i++;
	}
	return (1);
}

int		ft_remove(t_lst *list, char **field, int x, int y)
{
	int **cd;
	int *min;
	int j;

	cd = list->cd;
	min = list->min;
	j = 0;
	while (j < 4)
	{
		field[y + cd[j][1] - min[1]][x + cd[j][0] - min[0]] = '.';
		j++;
	}
	return (1);
}

int		*ft_size(int *min, int *max)
{
	int *big;

	big = (int *)malloc(sizeof(int) * 2);
	big[1] = max[1] - min[1] + 1;
	big[0] = max[0] - min[0] + 1;
	return (big);
}

int		ft_putelem(t_square *square, t_lst *list)
{
	int x;
	int y;
	int *big;

	if (list == NULL)
		return (1);
	big = ft_size(list->min, list->max);
	y = -1;
	while (++y <= square->size - big[1])
	{
		x = -1;
		while (++x <= square->size - big[0])
		{
			if (ft_checkput(list, square->field, x, y))
			{
				if (ft_putelem(square, list->next))
					return (1);
				else
					ft_remove(list, square->field, x, y);
			}
		}
	}
	return (0);
}

void	ft_solve(char *str)
{
	int			len;
	t_square	*square;
	t_lst		*list;

	len = (ft_strlen(str) + 1) / 21;
	list = ft_divide(str, len);
	square = ft_square(len);
	while (!ft_putelem(square, list))
	{
		len++;
		ft_del(square->field);
		free_square(&square);
		square = ft_square(len);
	}
	ft_sqroutput(square->field);
	ft_del(square->field);
	free_square(&square);
	free_list(list);
	free_list_list(&list);
}
