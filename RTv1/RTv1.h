/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:06:53 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/02 16:06:59 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "structs.h"
# include "mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <pthread.h>
# define WIDTH 800
# define HEIGHT 600
# define RATIO WIDTH / HEIGHT
# define THREAD 6
# define min(a,b) (((a) < (b)) ? (a) : (b))
/*
**  other.c
*/
void		ft_error(char *reason);
/*
**   draw.c
*/
void		put_pixel(t_env *e, int x, int y, t_vector color);
void		image(t_env *e);
int			expose(t_env *e);
void 		window(t_env *e);
/*
**   sphere.c
*/
//int		inter_ray_sphere(t_ray *r, t_object *s, double *t);
void 		render(t_env *e);
/*
** 	 vector.c
*/
t_vector	vector_sub(t_vector *v1, t_vector *v2);
double		vector_dot(t_vector *v1, t_vector *v2);
t_vector	vector_scale(double c, t_vector *v);
t_vector	vector_add(t_vector *v1, t_vector *v2);
t_vector	vector_cross(t_vector *v1, t_vector *v2);
double		vector_length(t_vector *v);
t_vector	unit_vector(t_vector *v);
t_vector	vector_add3(t_vector *v1, t_vector *v2, t_vector *v3);
t_vector	reflect_through(t_vector *v, t_vector *normal);
/*
**  render_help.c
*/
t_vector	get_eye_ray(t_camera *cam);
int			solve_quadric(double discr, double *t, double b);
void		get_upvector(t_vector *vector_up);
double		calculate_contribution(t_light cl, t_vector *hit, t_vector normal);
/*
** trace.c
*/
t_vector trace(t_ray *ray, t_env *e, double depth);


/*
**  reader.c
*/
void		open_file(char *file, t_env *e);
void		read_file(int fd, t_env *e);
void		read_objects(int fd, t_env *e);
void		read_scene(int fd, t_env *e);
/*
** scene_reader.c
*/
char		*find_name(char *line);
void		find_scene_size(char *line, int *w, int *h);
void		find_camera_params(int fd, t_env *e);
void		find_coord(char *line, t_vector *pos);
/*
** light_reader.c
*/
void		find_light_pos(char *line, t_env *e);
void		find_light_intensity(char *line, t_env *e);
void		find_light_params(int fd, t_env *e);
/*
** object_reader.c
*/
void		find_obj(int fd, t_env *e);
void		find_object_data(int fd, t_env *e, int i);
double		find_double(char *line);
#endif
