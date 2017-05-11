/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 19:52:01 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/31 19:52:04 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_textures_l1(t_env *e)
{
	e->t[0].i = mlx_xpm_file_to_image(e->mlx, "texture/l1/GrassSide.xpm", \
	&e->t[0].w, &e->t[0].h);
	e->t[0].data = mlx_get_data_addr(e->t[0].i, &e->t[0].bpp, &e->t[0].sl, \
	&e->t[0].endian);
	e->t[1].i = mlx_xpm_file_to_image(e->mlx, "texture/l1/Brick.xpm", \
	&e->t[1].w, &e->t[1].h);
	e->t[1].data = mlx_get_data_addr(e->t[1].i, &e->t[1].bpp, &e->t[1].sl, \
	&e->t[1].endian);
	e->t[2].i = mlx_xpm_file_to_image(e->mlx, "texture/l1/Plank.xpm", \
	&e->t[2].w, &e->t[2].h);
	e->t[2].data = mlx_get_data_addr(e->t[2].i, &e->t[2].bpp, &e->t[2].sl, \
	&e->t[2].endian);
	e->t[3].i = mlx_xpm_file_to_image(e->mlx, "texture/l1/Stone.xpm", \
	&e->t[3].w, &e->t[3].h);
	e->t[3].data = mlx_get_data_addr(e->t[3].i, &e->t[3].bpp, &e->t[3].sl, \
	&e->t[3].endian);
	e->t[4].i = mlx_xpm_file_to_image(e->mlx, "texture/l1/Tree.xpm", \
	&e->t[4].w, &e->t[4].h);
	e->t[4].data = mlx_get_data_addr(e->t[4].i, &e->t[4].bpp, &e->t[4].sl, \
	&e->t[4].endian);
}

void	ft_floorsky_texture_l1(t_env *e)
{
	e->t[5].i = mlx_xpm_file_to_image(e->mlx, "texture/l1/Door.xpm", \
	&e->t[5].w, &e->t[5].h);
	e->t[5].data = mlx_get_data_addr(e->t[5].i, &e->t[5].bpp, &e->t[5].sl, \
	&e->t[5].endian);
	e->t[6].i = mlx_xpm_file_to_image(e->mlx, "texture/l1/Portal.xpm", \
	&e->t[6].w, &e->t[6].h);
	e->t[6].data = mlx_get_data_addr(e->t[6].i, &e->t[6].bpp, &e->t[6].sl, \
	&e->t[6].endian);
	e->t[7].i = mlx_xpm_file_to_image(e->mlx, "texture/l1/Dog.xpm", \
	&e->t[7].w, &e->t[7].h);
	e->t[7].data = mlx_get_data_addr(e->t[7].i, &e->t[7].bpp, &e->t[7].sl, \
	&e->t[7].endian);
	e->t[8].i = mlx_xpm_file_to_image(e->mlx, "texture/l1/Sky.xpm", \
	&e->t[8].w, &e->t[8].h);
	e->t[8].data = mlx_get_data_addr(e->t[8].i, &e->t[8].bpp, &e->t[8].sl, \
	&e->t[8].endian);
	e->t[9].i = mlx_xpm_file_to_image(e->mlx, "texture/l1/Grass.xpm", \
	&e->t[9].w, &e->t[9].h);
	e->t[9].data = mlx_get_data_addr(e->t[9].i, &e->t[9].bpp, &e->t[9].sl, \
	&e->t[9].endian);
}

void	ft_start_params(t_env *e)
{
	e->name = "maps/level1.wolf3d";
	e->c.pos.x = 8.5;
	e->c.pos.y = 32.5;
	e->c.dir.x = -1;
	e->c.dir.y = 0;
	e->c.plane.x = 0;
	e->c.plane.y = 0.6;
	e->xprev = 400;
	e->icon.x = 230;
	e->icon.y = 266;
	e->switcher = 1;
	ft_textures_l1(e);
	ft_floorsky_texture_l1(e);
}

void	ft_init_env(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, e->name);
	ft_start_params(e);
	e->newgame = 1;
	e->flag = 1;
	mlx_expose_hook(e->win, ft_expose, e);
	mlx_hook(e->win, 17, 1L << 17, ft_redcross, e);
	mlx_hook(e->win, 6, 1L << 6, ft_mouse_rot, e);
	mlx_hook(e->win, 2, 1L << 2, ft_keyhook, e);
	mlx_loop(e->mlx);
}
