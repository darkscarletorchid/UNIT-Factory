/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 15:41:52 by atrepyto          #+#    #+#             */
/*   Updated: 2017/05/07 14:09:21 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	find_normal(t_env *e, t_vector v, int curr)
{
	t_vector	tmp;
	double		t;

	if (ft_strcmp(e->scene.obs[curr].name, "plane") == 0)
		return (e->scene.obs[curr].rotation);
	else if (ft_strcmp(e->scene.obs[curr].name, "cylinder") == 0)
	{
		t = vector_dot(vector_sub(e->scene.v, e->scene.obs[curr].pos),
					e->scene.obs[curr].rotation);
		return (vector_sub(e->scene.v, vector_add(e->scene.obs[curr].pos,
					vector_scalar(t, e->scene.obs[curr].rotation))));
	}
	else if (ft_strcmp(e->scene.obs[curr].name, "cone") == 0)
	{
		tmp = vector_sub(v, e->scene.obs[curr].pos);
		t = vector_length(tmp) / (vector_dot(e->scene.obs[curr].rotation,
					unit_vector(tmp)));
		return (vector_sub(v, vector_add(e->scene.obs[curr].pos,
					vector_scalar(t, e->scene.obs[curr].rotation))));
	}
	else if (ft_strcmp(e->scene.obs[curr].name, "sphere") == 0)
		return (vector_sub(v, e->scene.obs[curr].pos));
	return (vector_save(0, 0, 0));
}

void		find_color(t_env *e, int curr, t_vector *retcolor, int i)
{
	e->scene.n = unit_vector(e->scene.n);
	if (ft_shadow(e, -1, i) == 0)
	{
		e->scene.v = unit_vector(e->scene.v);
		e->scene.l = unit_vector(e->scene.l);
		e->scene.h = unit_vector(e->scene.h);
		retcolor->x += e->scene.obs[curr].color.x * (AMB + DIFF *
				vector_dot(e->scene.n, e->scene.l)) +
				e->scene.lights[i].intensity.x * SPEC *
				pow(vector_dot(e->scene.n, e->scene.h), POW);
		retcolor->y += e->scene.obs[curr].color.y * (AMB + DIFF *
				vector_dot(e->scene.n, e->scene.l)) +
				e->scene.lights[i].intensity.y * SPEC *
				pow(vector_dot(e->scene.n, e->scene.h), POW);
		retcolor->z += e->scene.obs[curr].color.z * (AMB + DIFF *
				vector_dot(e->scene.n, e->scene.l)) +
				e->scene.lights[i].intensity.z * SPEC *
				pow(vector_dot(e->scene.n, e->scene.h), POW);
	}
	else
		*retcolor = vector_save(retcolor->x * 0.8, retcolor->y * 0.8,
								retcolor->z * 0.8);
}

t_vector	trace_light(t_env *e, double *t, int curr)
{
	t_vector	retcolor;
	int			i;

	retcolor = vector_save(0, 0, 0);
	i = -1;
	while (++i < e->scene.light_nb)
	{
		e->scene.v = vector_add(e->scene.ray.origin,
								vector_scalar(*t, e->scene.ray.direction));
		e->scene.n = find_normal(e, e->scene.v, curr);
		e->scene.l = vector_sub(e->scene.lights[i].pos, e->scene.v);
		e->scene.h = vector_add(ft_opposite(e->scene.v), e->scene.l);
		find_color(e, curr, &retcolor, i);
	}
	return (retcolor);
}

void		check_bias(t_env *e, t_ray *l, int j)
{
	if (sqrt(vector_dot(vector_sub(e->scene.v, e->scene.lights[j].pos),
						vector_sub(e->scene.v, e->scene.lights[j].pos))) >
		sqrt(vector_dot(vector_sub(l->origin, e->scene.lights[j].pos),
						vector_sub(l->origin, e->scene.lights[j].pos))))
		l->origin = vector_add(vector_scalar(0.0000001, e->scene.n),
						e->scene.v);
	else
	{
		e->scene.n = ft_opposite(e->scene.n);
		l->origin = vector_add(vector_scalar(0.0000001, e->scene.n),
						e->scene.v);
	}
}

int			ft_shadow(t_env *e, int i, int j)
{
	t_ray	l;
	double	t;

	t = sqrt(vector_dot(e->scene.l, e->scene.l));
	l.origin = vector_add(vector_scalar(0.0000001, e->scene.n), e->scene.v);
	l.direction = e->scene.l;
	while (++i < e->scene.obj_nb)
	{
		if (ft_strcmp(e->scene.obs[i].name, "sphere") == 0
			&& inter_ray_sphere(&l, &e->scene.obs[i], &t))
			return (1);
		else if (ft_strcmp(e->scene.obs[i].name, "cone") == 0
			&& intersect_cone(&l, &e->scene.obs[i], &t))
			return (1);
		else if (ft_strcmp(e->scene.obs[i].name, "cylinder") == 0
			&& intersect_cylind(&l, &e->scene.obs[i], &t))
			return (1);
		else if (ft_strcmp(e->scene.obs[i].name, "plane") == 0)
		{
			check_bias(e, &l, j);
			if (intersect_plane(&l, &e->scene.obs[i], &t))
				return (1);
		}
	}
	return (0);
}
