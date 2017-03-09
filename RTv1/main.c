/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 11:45:53 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/03 11:45:59 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"
//# define PRINT_S

#ifdef PRINT_S
void 	print_scene(t_env *e)
{
	t_scene s;
	s = e->scene;
	printf("title = %s width = %d height = %d\n", s.title, s.width, s.height);
	printf("light nb = %d obj nb = %d\n", s.light_nb, s.obj_nb);
	printf("camera\n");
	printf("origin x %f y %f z %f fov %d\n", s.cams.origin.x, s.cams.origin.y, s.cams.origin.z, s.cams.fov);
	printf("Objects\n");
	int i = 0;
	while (i < s.obj_nb)
	{
		printf("name = %s radius = %f height = %f lambert = %f ambient = %f reflection = %f\n",
			   s.obs[i].name, s.obs[i].radius, s.obs[i].height, s.obs[i].lambert, s.obs[i].ambient, s.obs[i].reflection);
		printf("pos x %f y %f z %f\n", s.obs[i].pos.x, s.obs[i].pos.y, s.obs[i].pos.z);
		printf("rotation x %f y %f z %f\n", s.obs[i].rotation.x, s.obs[i].rotation.y, s.obs[i].rotation.z);
		printf("color x %f y %f z %f\n", s.obs[i].color.x, s.obs[i].color.y, s.obs[i].color.z);
		i++;
	}
	printf("Lights\n");
	i = 0;
	while (i < s.light_nb)
	{
		printf("pos x %f y %f z %f\n", s.lights[i].pos.x, s.lights[i].pos.y, s.lights[i].pos.z);
		printf("intensity x %f y %f z %f\n", s.lights[i].intensity.x, s.lights[i].intensity.y,s.lights[i].intensity.z);
		i++;
	}
}
#endif
int		main(int ac, char **av)
{
	t_env *e;

	if (ac > 1)
	{
		if (!(e = (t_env *)malloc(sizeof(t_env))))
			ft_error("Malloc error");
		open_file(av[1], e);
#ifdef PRINT_S
		print_scene(e);
#endif

		//window(e);
	}
	else
		ft_putendl("no input file");
	sleep(20);
	return (0);
}
