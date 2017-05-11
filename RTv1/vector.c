/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 11:46:19 by atrepyto          #+#    #+#             */
/*   Updated: 2017/04/11 21:08:18 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		vector_length(t_vector v)
{
	double result;

	result = sqrt(vector_dot(v, v));
	return (result);
}

t_vector	unit_vector(t_vector v)
{
	t_vector result;

	result = vector_scalar(1 / vector_length(v), v);
	return (result);
}

t_vector	ft_opposite(t_vector v)
{
	t_vector res;

	res.x = -v.x;
	res.y = -v.y;
	res.z = -v.z;
	return (res);
}

double		vector_dot(t_vector v1, t_vector v2)
{
	double result;

	result = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (result);
}

t_vector	vector_scalar(double c, t_vector v)
{
	t_vector result;

	result.x = v.x * c;
	result.y = v.y * c;
	result.z = v.z * c;
	return (result);
}
