/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:55:05 by atrepyto          #+#    #+#             */
/*   Updated: 2017/04/12 16:18:22 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		count_julia(t_fract j)
{
	double mu;

	j.new.r = 1.5 * (j.x - WIDTH / 2) / (0.5 * j.zoom * WIDTH) + j.movex;
	j.new.i = (j.y - HEIGHT / 2) / (0.5 * j.zoom * HEIGHT) + j.movey;
	j.i = -1;
	while (++j.i < j.max_iter)
	{
		j.old.r = j.new.r;
		j.old.i = j.new.i;
		j.new.r = j.old.r * j.old.r - j.old.i * j.old.i + j.c.r;
		j.new.i = 2 * j.old.r * j.old.i + j.c.i;
		if ((j.new.r * j.new.r + j.new.i * j.new.i) > 4)
			break ;
	}
	mu = j.i + 1 - \
			(log(log(sqrt(j.new.r * j.new.r + j.new.i * j.new.i)))) / log(2);
	return (mu);
}

int		count_bs(t_fract b)
{
	double mu;

	b.c.r = 1.5 * (b.x - WIDTH / 2) / (0.5 * b.zoom * WIDTH) + b.movex;
	b.c.i = (b.y - HEIGHT / 2) / (0.5 * b.zoom * HEIGHT) + b.movey;
	b.new.r = 0;
	b.new.i = 0;
	b.old.r = 0;
	b.old.i = 0;
	b.i = -1;
	while (++b.i < b.max_iter)
	{
		b.old.r = b.new.r;
		b.old.i = b.new.i;
		b.new.r = b.old.r * b.old.r - b.old.i * b.old.i + b.c.r;
		b.new.i = 2 * fabs(b.old.r * b.old.i) + b.c.i;
		if ((b.new.r * b.new.r + b.new.i * b.new.i) > 4)
			break ;
	}
	mu = b.i + 1 - \
			(log(log(sqrt(b.new.r * b.new.r + b.new.i * b.new.i)))) / log(2);
	return (mu);
}

int		count_mandelbrot(t_fract j)
{
	double mu;

	j.c.r = 1.5 * (j.x - WIDTH / 2) / (0.5 * j.zoom * WIDTH) + j.movex;
	j.c.i = (j.y - HEIGHT / 2) / (0.5 * j.zoom * HEIGHT) + j.movey;
	j.new.r = 0;
	j.new.i = 0;
	j.old.r = 0;
	j.old.i = 0;
	j.i = -1;
	while ((++j.i < j.max_iter) && (j.new.r * j.new.r + j.new.i * j.new.i) < 4)
	{
		j.old.r = j.new.r;
		j.old.i = j.new.i;
		j.new.r = j.old.r * j.old.r - j.old.i * j.old.i + j.c.r;
		j.new.i = 2 * j.old.r * j.old.i + j.c.i;
	}
	mu = j.i + 1 - \
			(log(log(sqrt(j.new.r * j.new.r + j.new.i * j.new.i)))) / log(2);
	return (mu);
}

int		fifth(t_fract j)
{
	double mu;

	j.new.r = (j.x - WIDTH / 2) / (0.3 * j.zoom * WIDTH) + j.movex;
	j.new.i = (j.y - HEIGHT / 2) / (0.3 * j.zoom * HEIGHT) + j.movey;
	j.i = -1;
	while ((++j.i < j.max_iter) && (j.new.r * j.new.r + j.new.i * j.new.i) < 4)
	{
		j.old.r = j.new.r;
		j.old.i = j.new.i;
		j.new.r = fabs(j.old.r * j.old.r - j.old.i * j.old.i) + j.c.r;
		j.new.i = -2 * j.old.r * j.old.i + j.c.i;
	}
	mu = j.i + 1 - \
			(log(log(sqrt(j.new.r * j.new.r + j.new.i * j.new.i)))) / log(2);
	return (mu);
}
