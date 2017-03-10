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

#include "RTv1.h"

void		put_pixel(t_env *e, int x, int y, t_vector color)
{
	int i;
	i = (x * e->bpp / 8) + (y * e->size_line);
	if (i >= 0 && i < e->size_line * HEIGHT) {
		e->data[i] = (unsigned char) min(color.z * 255.0f, 255.0f);
		e->data[++i] = (unsigned char) min(color.y * 255.0f, 255.0f);
		e->data[++i] = (unsigned char) min(color.x * 255.0f, 255.0f);
	}
}

void	image(t_env *e)
{
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->size_line, &e->endian);
	//render(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
}

int			expose(t_env *e)
{
	image(e);
	return (0);
}

int key_hook(int keycode, t_env *e)
{
	if (keycode == 53) {
		mlx_destroy_window(e->mlx, e->win);
		free(e);
		exit(0);
	}
	return (0);
}
void 	window(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, e->scene.title);
	mlx_hook(e->win, 2, 0, key_hook, e);
	mlx_expose_hook(e->win, expose, e);
	mlx_loop(e->mlx);
}
