/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:06:53 by atrepyto          #+#    #+#             */
/*   Updated: 2017/05/11 12:54:55 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "structs.h"
# include <mlx.h>
# include "libft/libft.h"
# include <math.h>
# define RAD M_PI / 180
# define WIDTH 1200
# define HEIGHT 720
# define AMB 0.2
# define SPEC 0
# define DIFF 0.25
# define POW 100
# define RATIO WIDTH / (double)HEIGHT

/*
** main.c
*/
void		usage(char *s);
void		window(t_env *e);
void		init_scene(t_env *e);
/*
** image.c
*/
void		put_pixel(t_env *e, int x, int y, t_vector color);
void		image(t_env *e);
int			expose(t_env *e);
int			key_hook(int keycode, t_env *e);
int			exit_window(t_env *e);
/*
** init_obj.c
*/
void		init_sphere(t_env *e);
void		init_plane(t_env *e);
void		init_cone(t_env *e);
void		init_cylinder(t_env *e);
/*
** init_params.c
*/
void		ft_malloc_error(void);
void		init_cam(t_env *e);
void		init_light(t_env *e);
void		init_params(t_env *e);
/*
** ray.c
*/
void		compute_ray(t_env *e, int x, int y);
void		check_intersection(t_env *e, double *t, int *curr, int i);
t_vector	cast_ray(t_env *e);
void		cam_world_rotation(int keycode, t_env *e);
void		cam_axis_rotation(int keycode, t_env *e);
/*
** render.c
*/
int			intersect_plane(t_ray *r, t_object *p, double *t);
int			intersect_cone(t_ray *r, t_object *con, double *t);
int			intersect_cylind(t_ray *r, t_object *cyl, double *t);
int			inter_ray_sphere(t_ray *r, t_object *s, double *t);
void		render(t_env *e);
/*
** render_help.c
*/
double		square_cos(double n);
double		square_sin(double n);
t_vector	vector_save(double x, double y, double z);
int			solve_quadric(double discr, double *t, double b, double a);
/*
** trace.c
*/
t_vector	find_normal(t_env *e, t_vector v, int curr);
void		find_color(t_env *e, int curr, t_vector *retcolor, int i);
t_vector	trace_light(t_env *e, double *t, int curr);
int			ft_shadow(t_env *e, int i, int j);
void		check_bias(t_env *e, t_ray *l, int j);
/*
** vector.c
*/
t_vector	unit_vector(t_vector v);
t_vector	ft_opposite(t_vector v);
double		vector_length(t_vector v);
double		vector_dot(t_vector v1, t_vector v2);
t_vector	vector_scalar(double c, t_vector v);
/*
** vector_calcul.c
*/
t_vector	vector_sub(t_vector v1, t_vector v2);
t_vector	vector_add(t_vector v1, t_vector v2);
/*
** matrices.c
*/
t_matrix	mult_matrices(t_matrix m1, t_matrix m2);
t_vector	mult_vector(t_matrix m, t_vector v);
t_matrix	ft_rotationx(double angle);
t_matrix	ft_rotationy(double angle);
t_matrix	ft_rotationz(double angle);
#endif
