/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:11:06 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/09 17:11:09 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

char	*find_name(char *line)
{
	size_t	i;
	size_t	t;
	char	*name;

	i = 0;
	while (line[i] != '{')
		i++;
	t = i + 2;
	while (line[i] != '}')
		i++;
	name = ft_strsub(line, t, i - t - 1);
	return (name);
}

void	find_scene_size(char *line, int *w, int *h)
{
	size_t i;

	i = 0;
	while (line[i] != '{')
		i++;
	*w = ft_atoi(line + i + 1);
	while (line[i] != ',')
		i++;
	*h = ft_atoi(line + i + 1);
}

void	find_coord(char *line, t_vector *pos)
{
	size_t i;

	i = 0;
	while (line[i] != '{')
		i++;
	pos->x = ft_atof(line + i + 1);
	while (line[i] != ',')
		i++;
	i++;
	pos->y = ft_atof(line + i);
	while (line[i] != ',')
		i++;
	i++;
	pos->z = ft_atof(line + i);
}

void	find_camera_params(int fd, t_env *e)
{
	char	*line;

	while (get_next_line(fd, &line) > 0 && ft_strcmp(ft_strtrim(line), "}"))
	{
		if (ft_strstr(line, "position"))
			find_coord(line, &e->scene.cams.origin);
		else if (ft_strstr(line, "fov"))
			e->scene.cams.fov = (int)find_double(line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
}