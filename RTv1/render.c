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

#include "rtv1.h"

int		intersect_plane(t_ray *r, t_object *p, double *t)
{
	double		denom;
	double		t0;
	double		dp;
	t_vector	tmp;

	r->direction = unit_vector(r->direction);
	p->rotation = unit_vector(p->rotation);
	denom = vector_dot(p->rotation, r->direction);
	tmp = vector_sub(p->pos, r->origin);
	dp = vector_dot(tmp, p->rotation);
	t0 = dp / denom;
	if ((denom > 0.000001 || denom < -0.000001)
		&& dp != 0 && t0 >= 0)
	{
		if (t0 < *t)
		{
			*t = t0;
			return (1);
		}
		else
			return (0);
	}
	else
		return (0);
}

int		intersect_cone(t_ray *r, t_object *con, double *t)
{
	t_abs		solve;
	t_vector	delta_p;
	t_vector	tmp;
	t_vector	tmp2;

	r->direction = unit_vector(r->direction);
	con->rotation = unit_vector(con->rotation);
	delta_p = vector_sub(r->origin, con->pos);
	tmp = vector_sub(r->direction, vector_scalar(vector_dot(r->direction, \
	con->rotation), con->rotation));
	solve.a = square_cos(con->radius) * vector_dot(tmp, tmp)\
		- square_sin(con->radius) * vector_dot(r->direction, con->rotation)
		* vector_dot(r->direction, con->rotation);
	tmp2 = vector_sub(delta_p, \
	vector_scalar(vector_dot(delta_p, con->rotation), con->rotation));
	solve.b = 2 * square_cos(con->radius) * vector_dot(tmp, tmp2)
		- 2 * square_sin(con->radius) * vector_dot(r->direction, con->rotation)\
		* vector_dot(delta_p, con->rotation);
	solve.c = square_cos(con->radius) * vector_dot(tmp2, tmp2)
		- square_sin(con->radius) * vector_dot(delta_p, con->rotation)
		* vector_dot(delta_p, con->rotation);
	solve.discr = solve.b * solve.b - 4 * solve.a * solve.c;
	return (solve_quadric(solve.discr, t, solve.b, solve.a));
}

int		intersect_cylind(t_ray *r, t_object *cyl, double *t)
{
	t_abs		solve;
	t_vector	tmp;
	t_vector	tmp2;
	t_vector	delta_p;

	r->direction = unit_vector(r->direction);
	delta_p = vector_sub(r->origin, cyl->pos);
	cyl->rotation = unit_vector(cyl->rotation);
	tmp = vector_sub(r->direction, vector_scalar(vector_dot(r->direction,\
	cyl->rotation), cyl->rotation));
	solve.a = vector_dot(tmp, tmp);
	tmp2 = vector_sub(delta_p, vector_scalar(vector_dot(delta_p,\
	cyl->rotation), cyl->rotation));
	solve.b = 2 * vector_dot(tmp, tmp2);
	solve.c = vector_dot(tmp2, tmp2) - cyl->radius * cyl->radius;
	solve.discr = solve.b * solve.b - 4 * solve.a * solve.c;
	return (solve_quadric(solve.discr, t, solve.b, solve.a));
}

int		inter_ray_sphere(t_ray *r, t_object *s, double *t)
{
	t_abs		solve;
	t_vector	dist;

	r->direction = unit_vector(r->direction);
	solve.a = vector_dot(r->direction, r->direction);
	dist = vector_sub(r->origin, s->pos);
	solve.b = 2 * vector_dot(r->direction, dist);
	solve.c = vector_dot(dist, dist) - (s->radius * s->radius);
	solve.discr = solve.b * solve.b - 4 * solve.a * solve.c;
	return (solve_quadric(solve.discr, t, solve.b, solve.a));
}

void	render(t_env *e)
{
	int			x;
	int			y;
	t_vector	hit_color;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			compute_ray(e, x, y);
			hit_color = cast_ray(e);
			put_pixel(e, x, y, hit_color);
		}
	}
}
