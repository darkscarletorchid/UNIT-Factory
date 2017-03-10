//
// Created by Anastasiia Trepyton on 3/7/17.
//

#include "RTv1.h"
//t_vector get_eye_ray(t_camera *cam)
//{
//	t_vector temp;
//	t_vector eye;
//
//	temp = vector_sub(&cam->direction, &cam->origin);
//	eye = unit_vector(&temp);
//	return (eye);
//}

int solve_quadric(double discr, double *t, double b)
{
	int retval;

	if (discr < 0)
		retval = 0;
	else
	{
		double sqrtdiscr = sqrt(discr);
		double t0 = (-b + sqrtdiscr) / (2);
		double t1 = (-b - sqrtdiscr) / (2);
		if (t0 > t1)
			t0 = t1;
		if((t0 > 0.001f) && (t0 < *t))
		{
			*t = t0;
			retval = 1;
		}
		else
			retval = 1; //change to 0 later
	}
	return (retval);
}

//void get_upvector(t_vector *vector_up)
//{
//	vector_up->x = 0;
//	vector_up->y = 1;
//	vector_up->z = 0;
//}
//
//double calculate_contribution(t_light cl, t_vector *hit, t_vector normal)
//{
//	t_vector temp = vector_sub(&cl.pos, hit);
//	t_vector t = unit_vector(&temp);
//	double result = vector_dot(&t, &normal);
//	return (result);
//}