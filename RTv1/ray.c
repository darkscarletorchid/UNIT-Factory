/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 15:18:18 by atrepyto          #+#    #+#             */
/*   Updated: 2017/04/22 15:18:22 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		compute_ray(t_env *e, int x, int y)
{
	double		px;
	double		py;
	t_vector	dir;
	double		scale;

	scale = tan(e->scene.cams.fov / 2 * RAD);
	px = (2 * (x + 0.5) / WIDTH - 1) * scale * RATIO;
	py = (1 - 2 * (y + 0.5) / HEIGHT) * scale;
	e->scene.ray.origin = e->scene.cams.origin;
	dir = vector_save(px, py, e->scene.cams.start.z - 1);
	e->scene.ray.direction = unit_vector(vector_sub(dir, e->scene.cams.start));
	e->scene.ray.direction = mult_vector(e->scene.cams.world_matrix,
									e->scene.ray.direction);
	e->scene.ray.direction = mult_vector(e->scene.cams.self_matrix,
									e->scene.ray.direction);
}

void		check_intersection(t_env *e, double *t, int *curr, int i)
{
	while (++i < e->scene.obj_nb)
	{
		if (ft_strcmp(e->scene.obs[i].name, "sphere") == 0 &&
				inter_ray_sphere(&e->scene.ray, &e->scene.obs[i], t))
			*curr = i;
		else if (ft_strcmp(e->scene.obs[i].name, "cone") == 0 &&
				intersect_cone(&e->scene.ray, &e->scene.obs[i], t))
			*curr = i;
		else if (ft_strcmp(e->scene.obs[i].name, "cylinder") == 0 &&
				intersect_cylind(&e->scene.ray, &e->scene.obs[i], t))
			*curr = i;
		else if (ft_strcmp(e->scene.obs[i].name, "plane") == 0 &&
				intersect_plane(&e->scene.ray, &e->scene.obs[i], t))
			*curr = i;
	}
}

t_vector	cast_ray(t_env *e)
{
	double	t;
	int		curr;

	curr = -1;
	t = 2000000.0;
	check_intersection(e, &t, &curr, -1);
	if (curr == -1)
		return (vector_save(25, 25, 25));
	else
		return (trace_light(e, &t, curr));
}

void		cam_world_rotation(int keycode, t_env *e)
{
	if (keycode == 86 || keycode == 83)
		e->scene.cams.angle_x += keycode == 86 ? -5 : 5;
	else if (keycode == 87 || keycode == 84)
		e->scene.cams.angle_y += keycode == 87 ? -5 : 5;
	else if (keycode == 88 || keycode == 85)
		e->scene.cams.angle_z += keycode == 88 ? -5 : 5;
	init_cam(e);
	image(e);
}

void		cam_axis_rotation(int keycode, t_env *e)
{
	if (keycode == 12 || keycode == 0)
		e->scene.cams.angle_xx += keycode == 12 ? 5 : -5;
	else if (keycode == 13 || keycode == 1)
		e->scene.cams.angle_yy += keycode == 13 ? 5 : -5;
	else if (keycode == 14 || keycode == 2)
		e->scene.cams.angle_zz += keycode == 14 ? 5 : -5;
	init_cam(e);
	image(e);
}
