/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 13:59:39 by atrepyto          #+#    #+#             */
/*   Updated: 2017/04/29 13:59:40 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_matrix	mult_matrices(t_matrix m1, t_matrix m2)
{
	t_matrix	new;
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			new.matrix[j][i] = m1.matrix[0][i] * m2.matrix[j][0] +
				m1.matrix[1][i] * m2.matrix[j][1] + m1.matrix[2][i] *
				m2.matrix[j][2] + m1.matrix[3][i] * m2.matrix[j][3];
			j++;
		}
		i++;
	}
	return (new);
}

t_vector	mult_vector(t_matrix m, t_vector v)
{
	t_vector new;

	new.x = v.x * m.matrix[0][0] + v.y * m.matrix[0][1] + v.z * m.matrix[0][1]
			+ m.matrix[0][2];
	new.y = v.x * m.matrix[1][0] + v.y * m.matrix[1][1] + v.z * m.matrix[1][2]
			+ m.matrix[1][3];
	new.z = v.x * m.matrix[2][0] + v.y * m.matrix[2][1] + v.z * m.matrix[2][2]
			+ m.matrix[2][3];
	new.w = v.x * m.matrix[3][0] + v.y * m.matrix[3][1] + v.z * m.matrix[3][2]
			+ m.matrix[3][3];
	new.x /= new.w;
	new.y /= new.w;
	new.z /= new.w;
	return (new);
}

t_matrix	ft_rotationx(double angle)
{
	t_matrix m;

	m.matrix[0][0] = 1;
	m.matrix[0][1] = 0;
	m.matrix[0][2] = 0;
	m.matrix[0][3] = 0;
	m.matrix[1][1] = cos(angle * RAD);
	m.matrix[1][2] = -sin(angle * RAD);
	m.matrix[1][0] = 0;
	m.matrix[1][3] = 0;
	m.matrix[2][0] = 0;
	m.matrix[2][1] = sin(angle * RAD);
	m.matrix[2][2] = cos(angle * RAD);
	m.matrix[2][3] = 0;
	m.matrix[3][0] = 0;
	m.matrix[3][1] = 0;
	m.matrix[3][2] = 0;
	m.matrix[3][3] = 1;
	return (m);
}

t_matrix	ft_rotationy(double angle)
{
	t_matrix m;

	m.matrix[0][0] = cos(angle * RAD);
	m.matrix[0][1] = 0;
	m.matrix[0][2] = sin(angle * RAD);
	m.matrix[0][3] = 0;
	m.matrix[1][1] = 1;
	m.matrix[1][0] = 0;
	m.matrix[1][2] = 0;
	m.matrix[1][3] = 0;
	m.matrix[2][0] = -sin(angle * RAD);
	m.matrix[2][1] = 0;
	m.matrix[2][2] = cos(angle * RAD);
	m.matrix[2][3] = 0;
	m.matrix[3][0] = 0;
	m.matrix[3][1] = 0;
	m.matrix[3][2] = 0;
	m.matrix[3][3] = 1;
	return (m);
}

t_matrix	ft_rotationz(double angle)
{
	t_matrix m;

	m.matrix[0][0] = cos(angle * RAD);
	m.matrix[0][1] = -sin(angle * RAD);
	m.matrix[0][2] = 0;
	m.matrix[0][3] = 0;
	m.matrix[1][0] = sin(angle * RAD);
	m.matrix[1][1] = cos(angle * RAD);
	m.matrix[1][2] = 0;
	m.matrix[1][3] = 0;
	m.matrix[2][0] = 0;
	m.matrix[2][1] = 0;
	m.matrix[2][2] = 1;
	m.matrix[2][3] = 0;
	m.matrix[3][0] = 0;
	m.matrix[3][1] = 0;
	m.matrix[3][2] = 0;
	m.matrix[3][3] = 1;
	return (m);
}
