/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_visualizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 19:32:52 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/31 19:32:55 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_texture(t_env *e, int i, int j, int nb)
{
	if (e->c.side == 0)
	{
		e->data[i] = e->t[nb].data[j];
		e->data[++i] = e->t[nb].data[++j];
		e->data[++i] = e->t[nb].data[++j];
	}
	else if (e->c.side == 1)
	{
		e->data[i] = (e->t[nb].data[j] >> 1) & 8355711;
		e->data[++i] = (e->t[nb].data[++j] >> 1) & 8355711;
		e->data[++i] = (e->t[nb].data[++j] >> 1) & 8355711;
	}
}

void	ft_pixel_put(int x, int y, t_env *e, int color)
{
	int i;

	i = x * e->bpp / 8 + y * e->sizeline;
	if (i >= 0 && i < e->sizeline * HEIGHT)
	{
		e->data[i] = color;
		e->data[++i] = color >> 8;
		e->data[++i] = color >> 16;
	}
}

void	ft_draw_sqr(t_env *e, int x, int y, int color)
{
	int i;
	int j;

	j = 0;
	while (y * MAP + j < y * MAP + MAP)
	{
		i = 0;
		while (x * MAP + i < x * MAP + MAP)
		{
			ft_pixel_put(x * MAP + i, y * MAP + j, e, color);
			i++;
		}
		j++;
	}
}

void	ft_drawmap(t_env *e)
{
	int y;
	int x;

	y = 0;
	while (y < e->map_h)
	{
		x = 0;
		while (x < e->map_w)
		{
			if (e->map[y][x] > 48)
				ft_draw_sqr(e, x, y, 0x00FF00);
			else if (e->map[y][x] == 48 || e->map[y][x] == '.')
			{
				if (y == floor(e->c.pos.x) && x == floor(e->c.pos.y))
					ft_draw_sqr(e, x, y, 0xFF0000);
			}
			x++;
		}
		y++;
	}
}
