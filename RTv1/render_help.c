/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 17:40:28 by atrepyto          #+#    #+#             */
/*   Updated: 2017/04/24 17:40:30 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		square_cos(double n)
{
	double res;

	res = (1 + cos(2 * n * RAD)) / 2;
	return (res);
}

double		square_sin(double n)
{
	double res;

	res = (1 - cos(2 * n * RAD)) / 2;
	return (res);
}

t_vector	vector_save(double x, double y, double z)
{
	t_vector res;

	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}

int			solve_quadric(double discr, double *t, double b, double a)
{
	int		retval;
	double	t0;
	double	t1;

	if (discr < 0)
		retval = 0;
	else
	{
		t0 = (-b + sqrt(discr)) / (2 * a);
		t1 = (-b - sqrt(discr)) / (2 * a);
		if (t0 > t1)
			t0 = t1;
		if ((t0 > 0.001) && (t0 < *t))
		{
			*t = t0;
			retval = 1;
		}
		else
			retval = 0;
	}
	return (retval);
}
