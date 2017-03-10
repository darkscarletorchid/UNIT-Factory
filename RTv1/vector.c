/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 11:46:19 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/03 11:46:21 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

t_vector vector_cross(t_vector *v1, t_vector *v2)
{
	t_vector result;

	result.x = v1->y *v2->z - v1->z* v2->y;
	result.y = v1->z * v2->x - v1->x * v2->z;
	result.z = v1->x * v2->y - v1->y * v2->x;
	return (result);
}

double vector_length(t_vector *v)
{
	double result;

	result = sqrt(vector_dot(v, v));
	return (result);
}

t_vector unit_vector(t_vector *v)
{
	t_vector result;

	result = vector_scale(1 / vector_length(v), v);
	return (result);
}

t_vector reflect_through(t_vector *v, t_vector *normal)
{
	double temp = vector_dot(v, normal);
	t_vector t = vector_scale(temp, normal);
	t_vector te = vector_scale(2, &t);
	t_vector result = vector_sub(&te, v);
	return (result);
}