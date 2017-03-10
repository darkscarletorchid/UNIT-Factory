/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 11:46:05 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/03 11:46:09 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

int intersect_plane(t_ray *r, t_object *p)
{
	t_vector dist = vector_sub(&p->pos, &r->origin);
	double t = sqrt(vector_dot(&dist, &dist) / vector_dot(&r->direction, &r->direction));
	if (t<0)
		return (0);
	else
		return (1);
}

int intersect_cone(t_ray *r, t_object *con, double *t)
{
	int retval = 0;

	double a = r->direction.x * r->direction.x + r->direction.z * r->direction.z - r->direction.y * r->direction.y ;
	t_vector dist = vector_sub(&r->origin, &con->pos);
	double b = 2 * (r->direction.x * dist.x + r->direction.z * dist.z - r->direction.y * dist.y);
	double c = dist.x * dist.x + dist.z * dist.z - dist.y * dist.y;
	double discr = b * b - 4 * a * c;
	retval = solve_quadric(discr, t, b);
	return (retval);
}

int intersect_cylind(t_ray *r, t_object *cyl, double *t)
{
	int retval = 0;

	double a = r->direction.x * r->direction.x + r->direction.z * r->direction.z;
	t_vector dist = vector_sub(&r->origin, &cyl->pos);
	double b = 2 * (r->direction.x * dist.x + r->direction.z * dist.z);
	double c = dist.x * dist.x + dist.z * dist.z - cyl->radius * cyl->radius;
	double discr = b * b - 4 * a * c;
	retval = solve_quadric(discr, t, b);
	return (retval);
}

int inter_ray_sphere(t_ray *r, t_object *s, double *t)
{
	int retval = 0;

	double a = vector_dot(&r->direction, &r->direction);

	t_vector dist = vector_sub(&r->origin, &s->pos);
	double b = 2 * vector_dot(&r->direction, &dist);
	double c = vector_dot(&dist, &dist) - (s->radius * s->radius);
	double discr = b * b - 4 * a * c;
	retval = solve_quadric(discr, t, b);
	return (retval);
}

void 	render(t_env *e)
{
	int x;
	int y;

	y = -1;
	while (++y < HEIGHT)
	{
		e->scene.ray.origin.y = y;
		x = -1;
		while (++x < WIDTH)
		{
			e->scene.ray.origin.x = x;
			e->scene.ray.origin.z = e->scene.cams.origin.z;
			e->scene.ray.direction.x = 0;
			e->scene.ray.direction.y = 0;
			e->scene.ray.direction.z = 1;
			int i = -1;
			double t = 0.001f;
			while (++i < e->scene.obj_nb)
			{
				if (ft_strcmp(e->scene.obs[i].name, "sphere") == 0) {
					if (inter_ray_sphere(&e->scene.ray, &e->scene.obs[i], &t))
						put_pixel(e, x, y, e->scene.obs[i].color);
				}
				else if (ft_strcmp(e->scene.obs[i].name, "cone") == 0) {
					if (intersect_cone(&e->scene.ray, &e->scene.obs[i], &t))
						put_pixel(e, x, y, e->scene.obs[i].color);
				}
				else if (ft_strcmp(e->scene.obs[i].name, "cylinder") == 0){
					if (intersect_cylind(&e->scene.ray, &e->scene.obs[i], &t))
						put_pixel(e, x, y, e->scene.obs[i].color);
				}
			}
		}
	}
}

