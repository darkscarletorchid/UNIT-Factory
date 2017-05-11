/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 15:11:28 by atrepyto          #+#    #+#             */
/*   Updated: 2017/05/07 14:03:45 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_malloc_error(void)
{
	ft_putendl("Malloc error");
	exit(0);
}

void	init_cam(t_env *e)
{
	e->scene.cams.start = vector_save(0, 0, 450);
	e->scene.cams.fov = 30;
	e->scene.cams.world_matrix = mult_matrices(
			ft_rotationx(e->scene.cams.angle_x),
			ft_rotationy(e->scene.cams.angle_y));
	e->scene.cams.world_matrix = mult_matrices(
			e->scene.cams.world_matrix,
			ft_rotationz(e->scene.cams.angle_z));
	e->scene.cams.origin = mult_vector(e->scene.cams.world_matrix,
			e->scene.cams.start);
	e->scene.cams.self_matrix = mult_matrices(
			ft_rotationx(e->scene.cams.angle_xx),
			ft_rotationy(e->scene.cams.angle_yy));
	e->scene.cams.self_matrix = mult_matrices(
			e->scene.cams.self_matrix,
			ft_rotationz(e->scene.cams.angle_zz));
}

void	init_light(t_env *e)
{
	e->scene.light_nb = 1;
	if (!(e->scene.lights = malloc(sizeof(t_light) * e->scene.light_nb)))
		ft_malloc_error();
	e->scene.lights[0].pos = vector_save(0, 100, 60);
	e->scene.lights[0].intensity = vector_save(200, 200, 200);
	//e->scene.lights[1].pos = vector_save(60, 30, 30);
	//e->scene.lights[1].intensity = vector_save(25, 25, 25);
	//e->scene.lights[2].pos = vector_save(0, 5, 50);
	//e->scene.lights[2].intensity = vector_save(125, 125, 125);
}

void	init_params(t_env *e)
{
	if (!(e->scene.obs = malloc(sizeof(t_object) * e->scene.obj_nb)))
		ft_malloc_error();
	e->scene.obs[0].name = "plane";
	e->scene.obs[0].pos = vector_save(0, -25, -35);
	e->scene.obs[0].rotation = vector_save(0, 5, 0);
	e->scene.obs[0].color = vector_save(128, 128, 0);
	e->scene.obs[1].name = "sphere";
	e->scene.obs[1].pos = vector_save(-10, 5, -10);
	e->scene.obs[1].rotation = vector_save(0, 0, 0);
	e->scene.obs[1].color = vector_save(255, 0, 0);
	e->scene.obs[1].radius = 5.0;
	e->scene.obs[2].name = "cone";
	e->scene.obs[2].pos = vector_save(10, 2, -20);
	e->scene.obs[2].rotation = vector_save(1, 1, 0);
	e->scene.obs[2].color = vector_save(0, 255, 0);
	e->scene.obs[2].radius = 15;
	e->scene.obs[3].name = "cylinder";
	e->scene.obs[3].pos = vector_save(0, 0, -15);
	e->scene.obs[3].radius = 5.0;
	e->scene.obs[3].rotation = vector_save(-1, 1, -1);
	e->scene.obs[3].color = vector_save(0, 0, 255);
	e->scene.obs[4].name = "plane";
	e->scene.obs[4].pos = vector_save(0, -1, -35);
	e->scene.obs[4].rotation = vector_save(0, 0, -1);
	e->scene.obs[4].color = vector_save(255, 0, 255);
}
