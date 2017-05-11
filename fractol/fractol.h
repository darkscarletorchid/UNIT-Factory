/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:21:30 by atrepyto          #+#    #+#             */
/*   Updated: 2017/04/12 16:19:23 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include "./libft/libft.h"
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# define WIDTH 1500
# define HEIGHT 1000
# define WIDTH_W 1700
# define HEIGHT_W 1000
# define THREAD 24

typedef struct		s_cd
{
	double r;
	double i;
}					t_cd;

typedef struct		s_cord
{
	double x;
	double y;
}					t_cord;

typedef struct		s_rgb
{
	int a;
	int r;
	int g;
	int b;
}					t_rgb;

typedef struct		s_bres
{
	double d_x;
	double d_y;
	double s_x;
	double s_y;
	double error;
	double error2;
	double p1x;
	double p1y;
	double p2x;
	double p2y;
}					t_bres;

typedef struct		s_fract
{
	t_cd	c;
	t_cd	old;
	t_cd	new;
	double	zoom;
	double	movex;
	double	movey;
	int		max_iter;
	double	x;
	double	y;
	int		i;
	t_cd	j;
	int		m;
	int		vx;
	int		vy;
}					t_fract;

typedef struct		s_env
{
	int		fractal;
	void	*mlx;
	void	*win;
	void	*img;
	int		s_line;
	char	*data;
	int		endian;
	int		bpp;
	t_rgb	*color;
	t_fract	params;
	t_fract j;

}					t_env;

typedef struct		s_th
{
	t_env	*e;
	double	nb;
}					t_th;
/*
** main.c
*/
void				ft_malloc_error(void);
int					chose_fractal(char *s, char *s0);

/*
** color.c
*/
t_rgb				*ft_get_color();
int					count_color(int i, t_env *e);
void				get_params(t_env *e);
void				other_julia(int keycode, t_env *e);
void				other_julia1(int keycode, t_env *e);

/*
** draw.c
*/
void				put_pixel(t_env *e, double x, double y, int color);
void				ft_logo(t_env *e);
void				ft_image(t_env *e);
void				ft_window(char *s, int fractal);
int					expose(t_env *e);

/*
** threads.c
*/
void				thread_fract(t_env *e);
void				*create_fract(void *fractal);

/*
** key_hooks.c
*/
int					key_hook(int keycode, t_env *e);
void				change_color(int keycode, t_env *e);
void				back_to_default(int keycode, t_env *e);
void				change_iter(int keycode, t_env *e);
void				move_arrows(int keycode, t_env *e);

/*
** mouse_hooks.c
*/
int					ft_mouse(int button, int x, int y, t_env *e);
int					ft_change_julia(int event, int mask, t_env *e);
void				stop_julia(int keycode, t_env *e);

/*
** fractals.c
*/
int					count_julia(t_fract j);
int					count_bs(t_fract b);
int					count_mandelbrot(t_fract j);
int					fifth(t_fract j);

/*
** cantor_set.c
*/
void				create_cantor(t_env *e);
void				cantor_line(double x, double y, double len, t_env *e);
void				draw_line(t_cord *p1, t_cord *p2, t_env *e);
#endif
