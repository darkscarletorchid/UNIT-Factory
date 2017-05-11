/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 11:45:32 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/03 11:45:36 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		put_pixel(t_env *e, int x, int y, t_vector color)
{
	int i;

	i = (x * e->bpp / 8) + (y * e->size_line);
	if (i >= 0 && i < e->size_line * HEIGHT)
	{
		e->data[i] = (char)fmax(fmin(color.z, 255.0), 0);
		e->data[++i] = (char)fmax(fmin(color.y, 255.0), 0);
		e->data[++i] = (char)fmax(fmin(color.x, 255.0), 0);
	}
}

void		image(t_env *e)
{
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->size_line, &e->endian);
	render(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
}

int			expose(t_env *e)
{
	image(e);
	return (0);
}

int			key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	else if (keycode <= 88 && keycode >= 83)
		cam_world_rotation(keycode, e);
	else if ((keycode <= 2 && keycode >= 0) || (keycode <= 14 && keycode >= 12))
		cam_axis_rotation(keycode, e);
	return (0);
}

int			exit_window(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	exit(0);
	return (0);
}
