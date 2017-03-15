/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 15:58:06 by atrepyto          #+#    #+#             */
/*   Updated: 2017/02/24 15:58:08 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			expose(t_env *e)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (e->fractal == 1)
	{
		e->img = mlx_xpm_file_to_image(e->mlx, "julia_set.xpm", &x, &y);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 200, 0);
		mlx_destroy_image(e->mlx, e->img);
		e->img = mlx_xpm_file_to_image(e->mlx, "controls.xpm", &x, &y);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
		mlx_destroy_image(e->mlx, e->img);
	}
	else
		ft_image(e);
	return (0);
}

void		ft_logo(t_env *e)
{
	int		x;
	int		y;
	void	*logo;

	x = 0;
	y = 0;
	logo = mlx_xpm_file_to_image(e->mlx, "controls.xpm", &x, &y);
	mlx_put_image_to_window(e->mlx, e->win, logo, 0, 0);
	mlx_destroy_image(e->mlx, logo);
}

void		ft_image(t_env *e)
{
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->s_line, &e->endian);
	if (e->fractal == 1 || e->fractal == 2 || e->fractal == 3 || \
			e->fractal == 5)
		thread_fract(e);
	else if (e->fractal == 4)
		create_cantor(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 200, 0);
	mlx_destroy_image(e->mlx, e->img);
	ft_logo(e);
}

void		put_pixel(t_env *e, double x, double y, int color)
{
	int i;

	i = ((int)x * e->bpp / 8) + ((int)y * e->s_line);
	if (i >= 0 && i < e->s_line * HEIGHT)
	{
		e->data[i] = color;
		e->data[++i] = color >> 8;
		e->data[++i] = color >> 16;
	}
}

void		ft_window(char *s, int fractal)
{
	t_env *e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		ft_malloc_error();
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH_W, HEIGHT_W, s);
	e->fractal = fractal;
	e->color = ft_get_color();
	e->params.max_iter = 400;
	e->params.zoom = 0.9;
	get_params(e);
	mlx_hook(e->win, 2, (1L << 0), key_hook, e);
	mlx_hook(e->win, 4, (1L << 2), ft_mouse, e);
	if (e->fractal == 1 || e->fractal == 5)
		mlx_hook(e->win, 6, (1L << 6), ft_change_julia, e);
	mlx_expose_hook(e->win, expose, e);
	mlx_loop(e->mlx);
}
