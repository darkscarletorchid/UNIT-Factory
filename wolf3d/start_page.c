/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_page.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 19:25:58 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/31 19:25:59 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_switcher(t_env *e)
{
	int w;
	int h;

	if (e->switcher == 1)
	{
		e->flag = 0;
		e->newgame = 0;
		ft_start_params(e);
		ft_get_map(e);
		ft_image(e);
		e->img = mlx_xpm_file_to_image(e->mlx, "texture/level1.xpm", &w, &h);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 300, 275);
		mlx_destroy_image(e->mlx, e->img);
	}
	else if (e->switcher == 2 && e->newgame != 1)
	{
		e->flag = 0;
		ft_image(e);
	}
	else if (e->switcher == 3)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
}

void	ft_chose_down(t_env *e)
{
	int		w;
	int		h;
	void	*i;

	if (e->switcher < 3 && e->switcher >= 1)
	{
		e->icon.y += 60;
		e->switcher++;
	}
	i = mlx_xpm_file_to_image(e->mlx, "texture/Startpage.xpm", &w, &h);
	mlx_put_image_to_window(e->mlx, e->win, i, 0, 0);
	mlx_destroy_image(e->mlx, i);
	i = mlx_xpm_file_to_image(e->mlx, "texture/Icon.xpm", &w, &h);
	mlx_put_image_to_window(e->mlx, e->win, i, (int)e->icon.x, (int)e->icon.y);
	mlx_destroy_image(e->mlx, i);
}

void	ft_chose_up(t_env *e)
{
	int		w;
	int		h;
	void	*i;

	if (e->switcher > 1 && e->switcher <= 3)
	{
		e->icon.y -= 60;
		e->switcher--;
	}
	i = mlx_xpm_file_to_image(e->mlx, "texture/Startpage.xpm", &w, &h);
	mlx_put_image_to_window(e->mlx, e->win, i, 0, 0);
	mlx_destroy_image(e->mlx, i);
	i = mlx_xpm_file_to_image(e->mlx, "texture/Icon.xpm", &w, &h);
	mlx_put_image_to_window(e->mlx, e->win, i, e->icon.x, e->icon.y);
	mlx_destroy_image(e->mlx, i);
}

void	ft_start_page(int keycode, t_env *e)
{
	if (keycode == 126 && e->flag == 1)
		ft_chose_up(e);
	else if (keycode == 125 && e->flag == 1)
		ft_chose_down(e);
	if (keycode == 36 && e->flag == 1)
		ft_switcher(e);
}
