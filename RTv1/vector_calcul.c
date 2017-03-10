//
// Created by Anastasiia Trepyton on 3/10/17.
//

#include "RTv1.h"

t_vector vector_sub(t_vector *v1, t_vector *v2)
{
	t_vector result;

	result.x = v1->x - v2->x;
	result.y = v1->y - v2->y;
	result.z = v1->z - v2->z;
	return (result);
}

double  vector_dot(t_vector *v1, t_vector *v2)
{
	double result;

	result = v1->x * v2->x  + v1->y * v2->y + v1->z * v2->z;
	return (result);
}

t_vector vector_add(t_vector *v1, t_vector *v2)
{
	t_vector result;

	result.x = v1->x + v2->x;
	result.y = v1->y + v2->y;
	result.z = v1->z + v2->z;
	return (result);
}

t_vector vector_add3(t_vector *v1, t_vector *v2, t_vector *v3)
{
	t_vector result;

	result.x = v1->x + v2->x + v3->x;
	result.y = v1->y + v2->y + v3->y;
	result.z = v1->z + v2->z + v3->z;
	return (result);
}

t_vector vector_scale(double c, t_vector *v)
{
	t_vector result;

	result.x = v->x * c;
	result.y = v->y * c;
	result.z = v->z * c;
	return (result);
}
