/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 11:45:53 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/03 11:45:59 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	window(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "RTv1");
	mlx_hook(e->win, 2, 0, key_hook, e);
	mlx_hook(e->win, 17, 1L << 17, exit_window, e);
	mlx_expose_hook(e->win, expose, e);
	mlx_loop(e->mlx);
}

void	usage(char *s)
{
	ft_putstr("\033[1;31mUsage: ");
	ft_putstr(s);
	ft_putendl(" [number of scene]\n");
	ft_putendl("\033[34mYou can render the following scenes:"
					"\n\033[32m[1] - one sphere\n[2] - one plane\n[3] - "
					"one cone\n[4] - one cylinder\n[5] - all of four "
					"objects together");
	exit(0);
}

void	init_scene(t_env *e)
{
	e->scene.cams.angle_x = 0;
	e->scene.cams.angle_y = 0;
	e->scene.cams.angle_z = 0;
	e->scene.cams.angle_xx = 0;
	e->scene.cams.angle_yy = 0;
	e->scene.cams.angle_zz = 0;
	init_cam(e);
	init_light(e);
}

int		main(int ac, char **av)
{
	t_env e;

	if (ac == 2)
	{
		init_scene(&e);
		if (ft_atoi(av[1]) == 5)
		{
			e.scene.obj_nb = 5;
			init_params(&e);
		}
		else if (ft_atoi(av[1]) == 1)
			init_sphere(&e);
		else if (ft_atoi(av[1]) == 2)
			init_plane(&e);
		else if (ft_atoi(av[1]) == 3)
			init_cone(&e);
		else if (ft_atoi(av[1]) == 4)
			init_cylinder(&e);
		else
			usage(av[0]);
		window(&e);
	}
	else
		usage(av[0]);
	return (0);
}
