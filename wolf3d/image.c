/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 19:36:49 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/31 19:36:50 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_raycast(t_env *e)
{
	e->c.x = -1;
	while (++e->c.x < WIDTH)
	{
		ft_init_params(&e->c);
		ft_count_step(&e->c);
		ft_check_hit(&e->c, e);
		ft_count_height(&e->c);
		ft_draw_line(&e->c, e);
		ft_init_floor(e);
		ft_draw_floor(e);
	}
}

void	ft_init_floor(t_env *e)
{
	if (e->c.side == 0 && e->c.raydir.x > 0)
	{
		e->c.fl.x = e->c.map.x;
		e->c.fl.y = e->c.map.y + e->c.wallx;
	}
	else if (e->c.side == 0 && e->c.raydir.x < 0)
	{
		e->c.fl.x = e->c.map.x + 1.0;
		e->c.fl.y = e->c.map.y + e->c.wallx;
	}
	else if (e->c.side == 1 && e->c.raydir.y > 0)
	{
		e->c.fl.x = e->c.map.x + e->c.wallx;
		e->c.fl.y = e->c.map.y;
	}
	else
	{
		e->c.fl.x = e->c.map.x + e->c.wallx;
		e->c.fl.y = e->c.map.y + 1.0;
	}
}

void	ft_draw_floor(t_env *e)
{
	int		y;
	double	w;
	int		i;
	int		j;

	e->c.drawend = e->c.drawend < 0 ? HEIGHT : e->c.drawend;
	y = e->c.drawend - 1;
	while (++y < HEIGHT)
	{
		w = HEIGHT / (2.0 * y - HEIGHT) / e->c.perp;
		e->c.flcur.x = w * e->c.fl.x + (1.0 - w) * e->c.pos.x;
		e->c.flcur.y = w * e->c.fl.y + (1.0 - w) * e->c.pos.y;
		e->c.fltext.x = (int)(e->c.flcur.x * 64) % 64;
		e->c.fltext.y = (int)(e->c.flcur.y * 64) % 64;
		i = e->c.x * e->bpp / 8 + y * e->sizeline;
		j = (int)(e->t[9].sl * e->c.fltext.y + e->c.fltext.x * e->t[9].bpp / 8);
		e->data[i] = e->t[9].data[j];
		e->data[++i] = e->t[9].data[++j];
		e->data[++i] = e->t[9].data[++j];
		i = e->c.x * e->bpp / 8 + (HEIGHT - y) * e->sizeline;
		j = (int)(e->t[8].sl * e->c.fltext.y + e->c.fltext.x * e->t[8].bpp / 8);
		e->data[i] = e->t[8].data[j];
		e->data[++i] = e->t[8].data[++j];
		e->data[++i] = e->t[8].data[++j];
	}
}

void	ft_draw_line(t_cast *c, t_env *e)
{
	int nb;
	int d;
	int i;
	int j;

	c->y = c->drawstart - 1;
	while (++c->y <= c->drawend)
	{
		nb = (e->map[(int)(c->map.x)][(int)(c->map.y)] - 48) - 1;
		if (e->c.side == 0)
			e->c.wallx = e->c.raypos.y + e->c.perp * e->c.raydir.y;
		else
			e->c.wallx = e->c.raypos.x + e->c.perp * e->c.raydir.x;
		e->c.wallx -= floor((e->c.wallx));
		e->c.tex.x = (int)(e->c.wallx * 64.0);
		if (e->c.side == 0 && e->c.raydir.x > 0)
			e->c.tex.x = 64 - e->c.tex.x - 1;
		if (e->c.side == 1 && e->c.raydir.y < 0)
			e->c.tex.x = 64 - e->c.tex.x - 1;
		d = c->y * 256 - HEIGHT * 128 + e->c.lineheight * 128;
		e->c.tex.y = ((d * 64) / e->c.lineheight) / 256;
		i = e->c.x * e->bpp / 8 + c->y * e->sizeline;
		j = (int)(e->t[nb].sl * e->c.tex.y + e->c.tex.x * e->t[nb].bpp / 8);
		ft_texture(e, i, j, nb);
	}
}

void	ft_image(t_env *e)
{
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sizeline, &e->endian);
	ft_raycast(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, MAP * e->map_w, MAP * e->map_h);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sizeline, &e->endian);
	ft_drawmap(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, WIDTH - e->map_w * MAP, \
							HEIGHT - e->map_h * MAP);
	mlx_destroy_image(e->mlx, e->img);
}
