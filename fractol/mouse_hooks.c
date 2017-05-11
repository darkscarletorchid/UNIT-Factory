/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:59:22 by atrepyto          #+#    #+#             */
/*   Updated: 2017/05/05 17:25:01 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mouse(int button, int x, int y, t_env *e)
{
	if (button == 4)
	{
		e->params.zoom *= 1.1;
		e->params.movex += \
				(double)((x - WIDTH / 2)) / WIDTH / 2 / e->params.zoom;
		e->params.movey += \
				(double)((y - HEIGHT / 2)) / HEIGHT / 2 / e->params.zoom;
		ft_image(e);
	}
	else if ((button == 5) && e->params.zoom > 0.9)
	{
		e->params.zoom /= 1.1;
		e->params.movex -= \
				(double)((WIDTH / 2 - x)) / WIDTH / 2 / e->params.zoom;
		e->params.movey -= \
				(double)((HEIGHT / 2 - y)) / HEIGHT / 2 / e->params.zoom;
		ft_image(e);
	}
	return (0);
}

int		ft_change_julia(int x, int y, t_env *e)
{
	if (x >= 0 && y >= 0 && x <= WIDTH && y <= HEIGHT && e->params.m == 1)
	{
		e->params.c.r = (double)x / (double)WIDTH * 4 - 2;
		e->params.c.i = (double)y / (double)HEIGHT * 4 - 2;
		ft_image(e);
	}
	return (0);
}

void	stop_julia(int keycode, t_env *e)
{
	static int count;

	if (keycode == 6 && count == 0)
	{
		e->params.m = 1;
		count = 1;
	}
	else if (keycode == 6 && count == 1)
	{
		e->params.m = 0;
		count = 0;
	}
}
