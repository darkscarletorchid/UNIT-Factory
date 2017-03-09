/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:44:38 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/09 18:44:43 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

double	find_double(char *line)
{
	int i;
	double nb;

	i = 0;
	while (line[i] != '{')
		++i;
	nb = ft_atof(line + i + 1);
	return (nb);
}

void	find_object_data(int fd, t_env *e, int i)
{
	char	*line;

	while (get_next_line(fd, &line) && ft_strcmp(ft_strtrim(line), "}"))
	{
		if (ft_strstr(line,"position"))
			find_coord(line, &e->scene.obs[i].pos);
		else if (ft_strstr(line, "rotation"))
			find_coord(line, &e->scene.obs[i].rotation);
		else if (ft_strstr(line, "radius"))
			e->scene.obs[i].radius = find_double(line);
		else if (ft_strstr(line, "height"))
			e->scene.obs[i].height = find_double(line);
		else if (ft_strstr(line, "reflection"))
			e->scene.obs[i].reflection = find_double(line);
		else if (ft_strstr(line, "ambient"))
			e->scene.obs[i].ambient = find_double(line);
		else if (ft_strstr(line, "lambert"))
			e->scene.obs[i].lambert = find_double(line);
		else if (ft_strstr(line, "color"))
			 find_coord(line, &e->scene.obs[i].color);
		ft_strdel(&line);
	}
	ft_strdel(&line);
}

void	find_obj(int fd, t_env *e)
{
	int i;
	char *line;

	i = 0;
	while (i < e->scene.obj_nb && get_next_line(fd, &line) && ft_strcmp(ft_strtrim(line), "}"))
	{
		if (ft_strstr(line, "name"))
			e->scene.obs[i].name = find_name(line);
		else if (ft_strstr(line, "data"))
		{
			find_object_data(fd, e, i);
			i++;
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
}
