/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:04:41 by atrepyto          #+#    #+#             */
/*   Updated: 2017/04/01 14:37:24 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_color(int keycode, t_env *e)
{
	if (keycode == 82)
	{
		e->color->a = e->color->a + 4;
		if (e->color->a > 255)
			e->color->a = 0;
		e->color->r = e->color->r + 4;
		if (e->color->r > 255)
			e->color->r = 0;
		e->color->g = e->color->g + 4;
		if (e->color->g > 255)
			e->color->g = 0;
		e->color->b = e->color->b + 4;
		if (e->color->b > 255)
			e->color->b = 0;
		ft_image(e);
	}
}

void	back_to_default(int keycode, t_env *e)
{
	if (keycode == 36)
	{
		free(e->color);
		e->color = ft_get_color();
		e->params.max_iter = 400;
		e->params.zoom = 0.9;
		get_params(e);
		ft_image(e);
	}
}

void	change_iter(int keycode, t_env *e)
{
	if (keycode == 69)
	{
		e->params.max_iter += 20;
		ft_image(e);
	}
	else if (keycode == 78)
	{
		e->params.max_iter -= 20;
		ft_image(e);
	}
}

void	move_arrows(int keycode, t_env *e)
{
	if (e->fractal == 4 && (keycode == 126 || keycode == 125 || keycode == 123 \
							|| keycode == 124))
	{
		if (keycode == 126)
			e->params.movey += 3;
		else if (keycode == 125)
			e->params.movey -= 3;
		else if (keycode == 123)
			e->params.movex += 3;
		else if (keycode == 124)
			e->params.movex -= 3;
		ft_image(e);
	}
	else if (keycode == 126 || keycode == 125)
	{
		e->params.movey += keycode == 126 ? 0.05 / e->params.zoom : \
											-0.05 / e->params.zoom;
		ft_image(e);
	}
	else if (keycode == 123 || keycode == 124)
	{
		e->params.movex += keycode == 123 ? -0.05 / e->params.zoom : \
											0.05 / e->params.zoom;
		ft_image(e);
	}
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
	{
		mlx_destroy_window(e->mlx, e->win);
		free(e);
		exit(0);
	}
	change_color(keycode, e);
	back_to_default(keycode, e);
	change_iter(keycode, e);
	move_arrows(keycode, e);
	other_julia(keycode, e);
	other_julia1(keycode, e);
	stop_julia(keycode, e);
	return (0);
}
