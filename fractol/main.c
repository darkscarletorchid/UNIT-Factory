/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 15:54:58 by atrepyto          #+#    #+#             */
/*   Updated: 2017/02/24 15:55:00 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_malloc_error(void)
{
	ft_putendl("Malloc error");
	exit(0);
}

static void	display_usage(char *s)
{
	ft_putstr("\033[1;31;05mUsage: ");
	ft_putstr(s);
	ft_putendl("\033[1;5;34m [Julia]\033[1;5;35m [Mandelbrot]"
					"\033[1;5;36m [BurningShip]\033[1;5;32m [Cantor]"
					"\033[1;5;34m [Brain]");
}

int			chose_fractal(char *s, char *s0)
{
	if (ft_strcmp(s, "Julia") == 0)
		ft_window(s, 1);
	else if (ft_strcmp(s, "Mandelbrot") == 0)
		ft_window(s, 2);
	else if (ft_strcmp(s, "BurningShip") == 0)
		ft_window(s, 3);
	else if (ft_strcmp(s, "Cantor") == 0)
		ft_window(s, 4);
	else if (ft_strcmp(s, "Brain") == 0)
		ft_window(s, 5);
	else
		display_usage(s0);
	return (0);
}

int			main(int ac, char **av)
{
	pid_t pid;

	if (ac == 2)
		chose_fractal(av[1], av[0]);
	else if (ac == 3)
	{
		pid = fork();
		if (pid == 0)
			chose_fractal(av[2], av[0]);
		else if (pid > 0)
			chose_fractal(av[1], av[0]);
		else
			return (1);
	}
	else
		display_usage(av[0]);
	return (0);
}
