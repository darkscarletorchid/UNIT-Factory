/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 18:20:25 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/31 18:20:27 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_expose(t_env *e)
{
	int w;
	int h;

	if (e->flag == 1)
	{
		e->img = mlx_xpm_file_to_image(e->mlx, "texture/Startpage.xpm", &w, &h);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
		mlx_destroy_image(e->mlx, e->img);
		e->img = mlx_xpm_file_to_image(e->mlx, "texture/Icon.xpm", &w, &h);
		mlx_put_image_to_window(e->mlx, e->win, e->img, e->icon.x, e->icon.y);
		mlx_destroy_image(e->mlx, e->img);
	}
	else
		ft_image(e);
	return (0);
}

int		ft_keyhook(int keycode, t_env *e)
{
	if (keycode == 53)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	else if (keycode == 126 || keycode == 125 || keycode == 36)
		ft_start_page(keycode, e);
	else if (keycode == 12)
		ft_resume(e);
	else
	{
		ft_controls(keycode, e);
		ft_rotation(keycode, e);
		ft_doors(keycode, e);
	}
	return (0);
}

int		ft_redcross(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	exit(0);
	return (0);
}

int		ft_mouse_rot(int x, int y, t_env *e)
{
	double tmp;

	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT && e->flag == 0)
	{
		if (e->xprev - x < 0 && (e->xprev = x))
		{
			tmp = e->c.dir.x;
			e->c.dir.x = e->c.dir.x * cos(-ROT) - e->c.dir.y * sin(-ROT);
			e->c.dir.y = tmp * sin(-ROT) + e->c.dir.y * cos(-ROT);
			tmp = e->c.plane.x;
			e->c.plane.x = e->c.plane.x * cos(-ROT) - e->c.plane.y * sin(-ROT);
			e->c.plane.y = tmp * sin(-ROT) + e->c.plane.y * cos(-ROT);
		}
		else if (e->xprev - x > 0 && (e->xprev = x))
		{
			tmp = e->c.dir.x;
			e->c.dir.x = e->c.dir.x * cos(ROT) - e->c.dir.y * sin(ROT);
			e->c.dir.y = tmp * sin(ROT) + e->c.dir.y * cos(ROT);
			tmp = e->c.plane.x;
			e->c.plane.x = e->c.plane.x * cos(ROT) - e->c.plane.y * sin(ROT);
			e->c.plane.y = tmp * sin(ROT) + e->c.plane.y * cos(ROT);
		}
		ft_image(e);
	}
	return (0);
}
