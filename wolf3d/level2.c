/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 12:38:25 by atrepyto          #+#    #+#             */
/*   Updated: 2017/04/01 12:38:28 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_level2(t_env *e)
{
	int w;
	int h;

	if (e->map[(int)(e->c.pos.x + e->c.dir.x)][(int)(e->c.pos.y + \
				e->c.dir.y)] == '7' && e->level == 2)
		ft_end_of_the_game(e);
	if (e->level == 2 && e->f == 1)
	{
		e->img = mlx_xpm_file_to_image(e->mlx, "texture/level2.xpm", &w, &h);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 300, 275);
		mlx_destroy_image(e->mlx, e->img);
	}
}

void	ft_end_of_the_game(t_env *e)
{
	int w;
	int h;

	e->img = mlx_xpm_file_to_image(e->mlx, "texture/gameover.xpm", &w, &h);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 300, 275);
	mlx_destroy_image(e->mlx, e->img);
	e->flag = 1;
	e->newgame = 1;
}

void	ft_textures_l2(t_env *e)
{
	e->t[0].i = mlx_xpm_file_to_image(e->mlx, "texture/l2/RedStone.xpm", \
	&e->t[0].w, &e->t[0].h);
	e->t[0].data = mlx_get_data_addr(e->t[0].i, &e->t[0].bpp, &e->t[0].sl, \
	&e->t[0].endian);
	e->t[1].i = mlx_xpm_file_to_image(e->mlx, "texture/l2/WebWall.xpm", \
	&e->t[1].w, &e->t[1].h);
	e->t[1].data = mlx_get_data_addr(e->t[1].i, &e->t[1].bpp, &e->t[1].sl, \
	&e->t[1].endian);
	e->t[2].i = mlx_xpm_file_to_image(e->mlx, "texture/l2/BookCase.xpm", \
	&e->t[2].w, &e->t[2].h);
	e->t[2].data = mlx_get_data_addr(e->t[2].i, &e->t[2].bpp, &e->t[2].sl, \
	&e->t[2].endian);
	e->t[3].i = mlx_xpm_file_to_image(e->mlx, "texture/l2/BookShell.xpm", \
	&e->t[3].w, &e->t[3].h);
	e->t[3].data = mlx_get_data_addr(e->t[3].i, &e->t[3].bpp, &e->t[3].sl, \
	&e->t[3].endian);
	e->t[4].i = mlx_xpm_file_to_image(e->mlx, "texture/l2/Cryolite.xpm", \
	&e->t[4].w, &e->t[4].h);
	e->t[4].data = mlx_get_data_addr(e->t[4].i, &e->t[4].bpp, &e->t[4].sl, \
	&e->t[4].endian);
}

void	ft_floorsky_texture_l2(t_env *e)
{
	e->t[5].i = mlx_xpm_file_to_image(e->mlx, "texture/l2/Doors.xpm", \
	&e->t[5].w, &e->t[5].h);
	e->t[5].data = mlx_get_data_addr(e->t[5].i, &e->t[5].bpp, &e->t[5].sl, \
	&e->t[5].endian);
	e->t[6].i = mlx_xpm_file_to_image(e->mlx, "texture/l2/Portale.xpm", \
	&e->t[6].w, &e->t[6].h);
	e->t[6].data = mlx_get_data_addr(e->t[6].i, &e->t[6].bpp, &e->t[6].sl, \
	&e->t[6].endian);
	e->t[7].i = mlx_xpm_file_to_image(e->mlx, "texture/l2/Brick.xpm", \
	&e->t[7].w, &e->t[7].h);
	e->t[7].data = mlx_get_data_addr(e->t[7].i, &e->t[7].bpp, &e->t[7].sl, \
	&e->t[7].endian);
	e->t[8].i = mlx_xpm_file_to_image(e->mlx, "texture/l2/Hall.xpm", \
	&e->t[8].w, &e->t[8].h);
	e->t[8].data = mlx_get_data_addr(e->t[8].i, &e->t[8].bpp, &e->t[8].sl, \
	&e->t[8].endian);
	e->t[9].i = mlx_xpm_file_to_image(e->mlx, "texture/l2/DoorTop.xpm", \
	&e->t[9].w, &e->t[9].h);
	e->t[9].data = mlx_get_data_addr(e->t[9].i, &e->t[9].bpp, &e->t[9].sl, \
	&e->t[9].endian);
}

void	ft_start_params_l2(t_env *e)
{
	int i;

	i = -1;
	e->c.pos.x = 8.5;
	e->c.pos.y = 1.5;
	e->c.dir.x = -1;
	e->c.dir.y = 0;
	e->c.plane.x = 0;
	e->c.plane.y = 0.6;
	ft_textures_l2(e);
	ft_floorsky_texture_l2(e);
	while (e->map[++i])
		ft_strdel(&e->map[i]);
	free(e->map);
}
