/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 17:03:07 by atrepyto          #+#    #+#             */
/*   Updated: 2017/04/24 17:03:09 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_matrix
{
	double matrix[4][4];
}				t_matrix;

/*
** structure for quadratic equation
*/
typedef struct	s_abc
{
	double		a;
	double		b;
	double		c;
	double		discr;
}				t_abs;
/*
** structure for vector
*/
typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
	double		w;
}				t_vector;
/*
** structure for objects
*/
typedef struct	s_object
{
	char		*name;
	t_vector	pos;
	t_vector	rotation;
	t_vector	color;
	double		radius;
}				t_object;
/*
** structure for ray
*/
typedef struct	s_ray
{
	t_vector	direction;
	t_vector	origin;
}				t_ray;
/*
** structure for light
*/
typedef struct	s_light
{
	t_vector	pos;
	t_vector	intensity;
}				t_light;
/*
** structure for cameras
*/
typedef struct	s_camera
{
	t_vector	origin;
	t_vector	start;
	double		fov;
	double		angle_x;
	double		angle_y;
	double		angle_z;
	t_matrix	world_matrix;
	double		angle_xx;
	double		angle_yy;
	double		angle_zz;
	t_matrix	self_matrix;

}				t_camera;

/*
** structure for scene
*/
typedef struct	s_scene
{
	int			light_nb;
	int			obj_nb;
	t_camera	cams;
	t_object	*obs;
	t_light		*lights;
	t_ray		ray;
	t_vector	v;
	t_vector	n;
	t_vector	l;
	t_vector	h;

}				t_scene;
/*
** structure for drawing environment
*/
typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			endian;
	int			size_line;
	t_scene		scene;
}				t_env;
#endif
