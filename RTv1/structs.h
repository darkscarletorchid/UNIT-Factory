//
// Created by Anastasiia Trepyton on 3/9/17.
//

#ifndef STRUCTS_H
#define STRUCTS_H
/*
 * structure for vector
 */
typedef struct 	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;
/*
 * structure for objects
 */
typedef struct	s_object
{
	char		*name;
	t_vector	pos;
	t_vector	rotation;
	t_vector	color;
	double		radius;
	double		height;
	double 		lambert;
	double 		ambient;
	double 		reflection;
}				t_object;
/*
 * structure for ray
 */
typedef struct	s_ray
{
	t_vector	direction;
	t_vector	origin;
}				t_ray;
/*
 * structure for light
 */
typedef struct	s_light
{
	t_vector	pos;
	t_vector	intensity;
}				t_light;
/*
 * structure for cameras
 */
typedef struct s_camera
{
	t_vector	origin;
	t_vector	rotation;
	t_vector	direction;
	int 		fov;
}				t_camera;
/*
** structure for scene
*/
typedef struct s_scene
{
	char		*title;
	int			width;
	int			height;
	int			light_nb;
	int			obj_nb;
	t_camera	cams;
	t_object	*obs;
	t_light		*lights;
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
	int 		endian;
	int			size_line;
	t_scene		scene;
}				t_env;
#endif
