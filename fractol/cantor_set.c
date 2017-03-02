/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cantor_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:47:00 by atrepyto          #+#    #+#             */
/*   Updated: 2017/02/28 15:47:02 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_get_params(t_bres *line, t_cord *p1, t_cord *p2)
{
	line->p1x = p1->x;
	line->p1y = p1->y;
	line->p2x = p2->x;
	line->p2y = p2->y;
	line->d_x = fabs(line->p2x - line->p1x);
	line->d_y = fabs(line->p2y - line->p1y);
	line->s_x = line->p1x < line->p2x ? 1 : -1;
	line->s_y = line->p1y < line->p2y ? 1 : -1;
	line->error = line->d_x - line->d_y;
}

void		draw_line(t_cord *p1, t_cord *p2, t_env *e)
{
	t_bres line;

	ft_get_params(&line, p1, p2);
	while ((int)line.p1x != (int)line.p2x || (int)line.p1y != (int)line.p2y)
	{
		put_pixel(e, line.p1x, line.p1y, count_color(300, e));
		line.error2 = line.error * 2;
		if (line.error2 > -line.d_y)
		{
			line.error -= line.d_y;
			line.p1x += line.s_x;
		}
		if (line.error2 < line.d_x)
		{
			line.error += line.d_x;
			line.p1y += line.s_y;
		}
	}
}

void		cantor_line(double x, double y, double len, t_env *e)
{
	t_cord *p1;
	t_cord *p2;

	if (len >= 1)
	{
		p1 = (t_cord*)malloc(sizeof(t_cord));
		p2 = (t_cord*)malloc(sizeof(t_cord));
		p1->x = x;
		p1->y = y;
		p2->x = x + len;
		p2->y = y;
		draw_line(p1, p2, e);
		y += 20;
		cantor_line(x, y, len / 3, e);
		cantor_line(x + len * 2 / 3, y, len / 3, e);
	}
}

void		create_cantor(t_env *e)
{
	double y;
	double x;

	y = 0 + e->params.movey;
	x = 0 + e->params.movex;
	while (y <= HEIGHT)
	{
		cantor_line(x, y, WIDTH, e);
		y += 100;
	}
}
