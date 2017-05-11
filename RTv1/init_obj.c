/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 17:24:42 by atrepyto          #+#    #+#             */
/*   Updated: 2017/04/24 17:24:43 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_sphere(t_env *e)
{
	e->scene.obj_nb = 1;
	if (!(e->scene.obs = malloc(sizeof(t_object) * e->scene.obj_nb)))
		ft_malloc_error();
	e->scene.obs[0].name = "sphere";
	e->scene.obs[0].pos = vector_save(-10, 5, -10);
	e->scene.obs[0].rotation = vector_save(0, 0, 0);
	e->scene.obs[0].color = vector_save(255, 0, 0);
	e->scene.obs[0].radius = 5.0;
}

void	init_plane(t_env *e)
{
	e->scene.obj_nb = 1;
	if (!(e->scene.obs = malloc(sizeof(t_object) * e->scene.obj_nb)))
		ft_malloc_error();
	e->scene.obs[0].name = "plane";
	e->scene.obs[0].pos = vector_save(0, 0, -5);
	e->scene.obs[0].rotation = vector_save(1, 1, 1);
	e->scene.obs[0].color = vector_save(128, 128, 0);
}

void	init_cone(t_env *e)
{
	e->scene.obj_nb = 1;
	if (!(e->scene.obs = malloc(sizeof(t_object) * e->scene.obj_nb)))
		ft_malloc_error();
	e->scene.obs[0].name = "cone";
	e->scene.obs[0].pos = vector_save(0, 0, -20);
	e->scene.obs[0].rotation = vector_save(0, 1, 0);
	e->scene.obs[0].color = vector_save(0, 255, 0);
	e->scene.obs[0].radius = 15;
}

void	init_cylinder(t_env *e)
{
	e->scene.obj_nb = 1;
	if (!(e->scene.obs = malloc(sizeof(t_object) * e->scene.obj_nb)))
		ft_malloc_error();
	e->scene.obs[0].name = "cylinder";
	e->scene.obs[0].pos = vector_save(0, 0, 0);
	e->scene.obs[0].radius = 5.0;
	e->scene.obs[0].rotation = vector_save(0, 1, 0);
	e->scene.obs[0].color = vector_save(0, 0, 255);
}
