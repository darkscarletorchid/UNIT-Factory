/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 20:09:34 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/31 20:09:35 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "libft/libft.h"
# include "mlx.h"
# include <math.h>

# define WIDTH 800
# define HEIGHT 600
# define ROT 4 * 0.0174532925
# define MOV 5
# define MAP 5

typedef struct	s_cd
{
	double		x;
	double		y;
}				t_cd;

typedef struct	s_cast
{
	int			x;
	int			y;
	t_cd		pos;
	t_cd		dir;
	t_cd		plane;
	t_cd		camera;
	t_cd		raypos;
	t_cd		raydir;
	t_cd		map;
	t_cd		sidedist;
	t_cd		deltadist;
	double		perp;
	t_cd		step;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	t_cd		tex;
	double		wallx;
	t_cd		fl;
	t_cd		flcur;
	t_cd		fltext;
}				t_cast;

typedef struct	s_text
{
	void		*i;
	char		*data;
	int			w;
	int			h;
	int			bpp;
	int			endian;
	int			sl;
}				t_text;

typedef struct	s_env
{
	char		*name;
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			endian;
	int			sizeline;
	char		**map;
	int			map_h;
	int			map_w;
	t_cast		c;
	int			xprev;
	int			flag;
	t_cd		icon;
	int			switcher;
	t_text		t[10];
	int			newgame;
	int			level;
	int			f;
}				t_env;
/*
** error.c
*/
void			ft_map_error(t_env *e);
void			ft_malloc_error(void);
void			ft_file_error(t_env *e, char *s);
void			ft_put_usage(char *s);
/*
** map.c
*/
void			ft_get_map(t_env *e);
void			ft_get_map_grid(t_env *e, int fd);
void			ft_validate_maze(t_env *e);
void			ft_get_map_size(t_env *e, char *s);
/*
** map_visualizer.c
*/
void			ft_pixel_put(int x, int y, t_env *e, int color);
void			ft_drawmap(t_env *e);
void			ft_draw_sqr(t_env *e, int x, int y, int color);
void			ft_texture(t_env *e, int i, int j, int nb);
/*
** env.c
*/
void			ft_init_env(t_env *e);
void			ft_start_params(t_env *e);
void			ft_textures_l1(t_env *e);
void			ft_floorsky_texture_l1(t_env *e);
/*
** events.c
*/
int				ft_mouse_rot(int x, int y, t_env *e);
int				ft_redcross(t_env *e);
int				ft_keyhook(int keycode, t_env *e);
int				ft_expose(t_env *e);
/*
** raycast.c
*/
void			ft_init_params(t_cast *c);
void			ft_count_step(t_cast *c);
void			ft_check_hit(t_cast *c, t_env *e);
void			ft_count_height(t_cast *c);
/*
** image.c
*/
void			ft_raycast(t_env *e);
void			ft_init_floor(t_env *e);
void			ft_draw_floor(t_env *e);
void			ft_draw_line(t_cast *c, t_env *e);
void			ft_image(t_env *e);
/*
** start_page.c
*/
void			ft_start_page(int keycode, t_env *e);
void			ft_switcher(t_env *e);
void			ft_chose_down(t_env *e);
void			ft_chose_up(t_env *e);
/*
** keycodes.c
*/
void			ft_controls(int keycode, t_env *e);
void			ft_rotation(int keycode, t_env *e);
void			ft_doors(int keycode, t_env *e);
void			ft_move_back(t_env *e);
void			ft_resume(t_env *e);
/*
** level2.c
*/
void			ft_start_params_l2(t_env *e);
void			ft_textures_l2(t_env *e);
void			ft_floorsky_texture_l2(t_env *e);
void			ft_end_of_the_game(t_env *e);
void			ft_level2(t_env *e);
#endif
