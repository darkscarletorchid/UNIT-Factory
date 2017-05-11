/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 15:59:49 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/23 15:18:32 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_rgb	*ft_get_color(void)
{
	t_rgb *color;

	if (!(color = (t_rgb*)malloc(sizeof(t_rgb))))
		ft_malloc_error();
	color->a = 0;
	color->r = 1;
	color->g = 4;
	color->b = 8;
	return (color);
}

int		count_color(int i, t_env *e)
{
	int color;

	color = e->color->a << 24 | e->color->r << 16 | e->color->g << 8 | \
			e->color->b;
	i = i * color;
	return (i);
}

void	get_params(t_env *e)
{
	e->params.m = 0;
	if (e->fractal == 1)
	{
		e->params.movex = 0;
		e->params.movey = 0;
	}
	else if (e->fractal == 2)
	{
		e->params.movex = -0.8;
		e->params.movey = 0;
		e->params.c.r = 0;
		e->params.c.i = 0;
	}
	else if (e->fractal == 3)
	{
		e->params.movex = -0.5;
		e->params.movey = -0.5;
	}
	else if (e->fractal == 5)
	{
		e->params.movex = 0;
		e->params.movey = 0;
		e->params.c.r = -0.7269;
		e->params.c.i = 0.1889;
	}
}

void	other_julia(int keycode, t_env *e)
{
	if (keycode == 83)
	{
		e->params.c.r = -0.7269;
		e->params.c.i = 0.1889;
		ft_image(e);
	}
	else if (keycode == 84)
	{
		e->params.c.r = 0;
		e->params.c.i = -0.8;
		ft_image(e);
	}
	else if (keycode == 85)
	{
		e->params.c.r = -0.8;
		e->params.c.i = 0.156;
		ft_image(e);
	}
	else if (keycode == 86)
	{
		e->params.c.r = -0.835;
		e->params.c.i = 0.2321;
		ft_image(e);
	}
}

void	other_julia1(int keycode, t_env *e)
{
	if (keycode == 87)
	{
		e->params.c.r = -0.70176;
		e->params.c.i = 0.3842;
		ft_image(e);
	}
	else if (keycode == 88)
	{
		e->params.c.r = 0.45;
		e->params.c.i = 0.1428;
		ft_image(e);
	}
	else if (keycode == 89)
	{
		e->params.c.r = 0.285;
		e->params.c.i = 0;
		ft_image(e);
	}
	else if (keycode == 91)
	{
		e->params.c.r = 0.285;
		e->params.c.i = 0.01;
		ft_image(e);
	}
}
