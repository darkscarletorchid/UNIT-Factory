/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:57:12 by atrepyto          #+#    #+#             */
/*   Updated: 2017/02/28 15:57:14 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*create_fract(void *fractal)
{
	t_fract	j;
	t_th	*data;

	data = (t_th *)fractal;
	j = data->e->params;
	j.y = data->nb;
	while (j.y < HEIGHT)
	{
		j.x = -1;
		while (++j.x < WIDTH)
		{
			if (data->e->fractal == 1)
				j.i = count_julia(j);
			else if (data->e->fractal == 2)
				j.i = count_mandelbrot(j);
			else if (data->e->fractal == 3)
				j.i = count_bs(j);
			else if (data->e->fractal == 5)
				j.i = fifth(j);
			j.i = count_color(j.i, data->e);
			put_pixel(data->e, j.x, j.y, j.i);
		}
		j.y += THREAD;
	}
	pthread_exit(NULL);
}

void	thread_fract(t_env *e)
{
	pthread_t	threads[THREAD];
	t_th		fractal[THREAD];
	int			i;

	i = 0;
	while (i < THREAD)
	{
		fractal[i].e = e;
		fractal[i].nb = i;
		if (pthread_create(&threads[i], NULL, create_fract, &fractal[i]) != 0)
			exit(-1);
		i++;
	}
	i = 0;
	while (i < THREAD)
	{
		if (pthread_join(threads[i], NULL) != 0)
			exit(-1);
		i++;
	}
}
