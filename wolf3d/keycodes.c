/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 18:29:25 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/31 18:30:08 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_move_back(t_env *e)
{
	if (e->map[(int)(e->c.pos.x - e->c.dir.x / MOV)][(int)e->c.pos.y] == 48)
		e->c.pos.x -= e->c.dir.x / MOV;
	else if (e->map[(int)(e->c.pos.x - e->c.dir.x / MOV)][(int)e->c.pos.y] \
				== '.')
		e->c.pos.x -= e->c.dir.x / MOV;
	if (e->map[(int)(e->c.pos.x)][(int)(e->c.pos.y - \
				e->c.dir.y / MOV)] == 48)
		e->c.pos.y -= e->c.dir.y / MOV;
	else if (e->map[(int)(e->c.pos.x)][(int)(e->c.pos.y - \
				e->c.dir.y / MOV)] == '.')
		e->c.pos.y -= e->c.dir.y / MOV;
	ft_image(e);
}

void	ft_controls(int keycode, t_env *e)
{
	if (keycode == 13 && e->flag == 0)
	{
		if (e->map[(int)(e->c.pos.x + e->c.dir.x / MOV)][(int)e->c.pos.y] == 48)
			e->c.pos.x += e->c.dir.x / MOV;
		else if (e->map[(int)(e->c.pos.x + e->c.dir.x / MOV)][(int)e->c.pos.y] \
				== '.')
			e->c.pos.x += e->c.dir.x / MOV;
		if (e->map[(int)(e->c.pos.x)][(int)(e->c.pos.y + \
				e->c.dir.y / MOV)] == 48)
			e->c.pos.y += e->c.dir.y / MOV;
		else if (e->map[(int)(e->c.pos.x)][(int)(e->c.pos.y + \
				e->c.dir.y / MOV)] == '.')
			e->c.pos.y += e->c.dir.y / MOV;
		ft_image(e);
	}
	else if (keycode == 1 && e->flag == 0)
		ft_move_back(e);
}

void	ft_rotation(int keycode, t_env *e)
{
	double tmp;

	if (keycode == 2 && e->flag == 0)
	{
		tmp = e->c.dir.x;
		e->c.dir.x = e->c.dir.x * cos(-ROT) - e->c.dir.y * sin(-ROT);
		e->c.dir.y = tmp * sin(-ROT) + e->c.dir.y * cos(-ROT);
		tmp = e->c.plane.x;
		e->c.plane.x = e->c.plane.x * cos(-ROT) - e->c.plane.y * sin(-ROT);
		e->c.plane.y = tmp * sin(-ROT) + e->c.plane.y * cos(-ROT);
		ft_image(e);
	}
	else if (keycode == 0 && e->flag == 0)
	{
		tmp = e->c.dir.x;
		e->c.dir.x = e->c.dir.x * cos(ROT) - e->c.dir.y * sin(ROT);
		e->c.dir.y = tmp * sin(ROT) + e->c.dir.y * cos(ROT);
		tmp = e->c.plane.x;
		e->c.plane.x = e->c.plane.x * cos(ROT) - e->c.plane.y * sin(ROT);
		e->c.plane.y = tmp * sin(ROT) + e->c.plane.y * cos(ROT);
		ft_image(e);
	}
}

void	ft_doors(int keycode, t_env *e)
{
	e->f = 0;
	if ((keycode == 49 || keycode == 14) && e->flag == 0)
	{
		if (e->map[(int)(e->c.pos.x + e->c.dir.x)][(int)(e->c.pos.y + \
				e->c.dir.y)] == '6')
			e->map[(int)(e->c.pos.x + e->c.dir.x)][(int)(e->c.pos.y + \
				e->c.dir.y)] = '.';
		else if (e->map[(int)(e->c.pos.x - e->c.dir.x)][(int)(e->c.pos.y \
				- e->c.dir.y)] == '.')
			e->map[(int)(e->c.pos.x - e->c.dir.x)][(int)(e->c.pos.y - \
				e->c.dir.y)] = '6';
		else if (e->map[(int)(e->c.pos.x + e->c.dir.x)][(int)(e->c.pos.y + \
				e->c.dir.y)] == '7' && e->level == 1)
		{
			e->name = "maps/level2.wolf3d";
			e->level = 2;
			ft_start_params_l2(e);
			ft_get_map(e);
			e->f = 1;
		}
		ft_image(e);
		ft_level2(e);
	}
}

void	ft_resume(t_env *e)
{
	int		w;
	int		h;
	void	*i;

	e->flag = 1;
	i = mlx_xpm_file_to_image(e->mlx, "texture/Startpage.xpm", &w, &h);
	mlx_put_image_to_window(e->mlx, e->win, i, 0, 0);
	mlx_destroy_image(e->mlx, i);
	i = mlx_xpm_file_to_image(e->mlx, "texture/Icon.xpm", &w, &h);
	mlx_put_image_to_window(e->mlx, e->win, i, (int)e->icon.x, (int)e->icon.y);
	mlx_destroy_image(e->mlx, i);
}
