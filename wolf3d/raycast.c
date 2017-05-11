/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 19:59:11 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/31 19:59:18 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_init_params(t_cast *c)
{
	c->camera.x = 2 * c->x / (double)(WIDTH) - 1;
	c->raypos.x = c->pos.x;
	c->raypos.y = c->pos.y;
	c->raydir.x = c->dir.x + c->plane.x * c->camera.x;
	c->raydir.y = c->dir.y + c->plane.y * c->camera.x;
	c->map.x = (int)(c->raypos.x);
	c->map.y = (int)(c->raypos.y);
	c->deltadist.x = sqrt(1 + (c->raydir.y * c->raydir.y) / (c->raydir.x * \
			c->raydir.x));
	c->deltadist.y = sqrt(1 + (c->raydir.x * c->raydir.x) / (c->raydir.y * \
			c->raydir.y));
}

void	ft_count_step(t_cast *c)
{
	if (c->raydir.x < 0)
	{
		c->step.x = -1;
		c->sidedist.x = (c->raypos.x - c->map.x) * c->deltadist.x;
	}
	else
	{
		c->step.x = 1;
		c->sidedist.x = (c->map.x + 1.0 - c->raypos.x) * c->deltadist.x;
	}
	if (c->raydir.y < 0)
	{
		c->step.y = -1;
		c->sidedist.y = (c->raypos.y - c->map.y) * c->deltadist.y;
	}
	else
	{
		c->step.y = 1;
		c->sidedist.y = (c->map.y + 1.0 - c->raypos.y) * c->deltadist.y;
	}
}

void	ft_check_hit(t_cast *c, t_env *e)
{
	c->hit = 0;
	while (c->hit == 0)
	{
		if (c->sidedist.x < c->sidedist.y)
		{
			c->sidedist.x += c->deltadist.x;
			c->map.x += c->step.x;
			c->side = 0;
		}
		else
		{
			c->sidedist.y += c->deltadist.y;
			c->map.y += c->step.y;
			c->side = 1;
		}
		if (c->map.x >= 0 && c->map.y >= 0 && c->map.x < e->map_h \
			&& c->map.y < e->map_w)
			c->hit = e->map[(int)c->map.x][(int)c->map.y] > '0' ? 1 : 0;
	}
	if (c->side == 0)
		c->perp = (c->map.x - c->raypos.x + (1 - c->step.x) / 2) / c->raydir.x;
	else
		c->perp = (c->map.y - c->raypos.y + (1 - c->step.y) / 2) / c->raydir.y;
}

void	ft_count_height(t_cast *c)
{
	c->lineheight = (int)(HEIGHT / c->perp);
	c->drawstart = -c->lineheight / 2 + HEIGHT / 2;
	if (c->drawstart < 0)
		c->drawstart = 0;
	c->drawend = c->lineheight / 2 + HEIGHT / 2;
	if (c->drawend >= HEIGHT)
		c->drawend = HEIGHT - 1;
}
