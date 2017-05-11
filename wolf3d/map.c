/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 18:25:37 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/31 18:25:39 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_get_map_size(t_env *e, char *s)
{
	while (*s && ft_isspace(*s))
		s++;
	e->map_w = ft_atoi(s);
	while (*s && !(ft_isspace(*s)))
		s++;
	e->map_h = ft_atoi(s);
	if (e->map_w < 3 || e->map_w > 100)
		ft_map_error(e);
	if (e->map_h < 3 || e->map_h > 100)
		ft_map_error(e);
}

void	ft_validate_maze(t_env *e)
{
	int i;
	int j;

	j = -1;
	while (e->map[++j] && j < e->map_h)
	{
		if (e->map[j][0] == '0' || e->map[j][e->map_w - 1] == '0')
			ft_map_error(e);
		i = 0;
		while (e->map[j][++i] && i < e->map_w - 1)
		{
			if (j == 0 || j == e->map_h - 1)
			{
				if (e->map[j][i] == '0' || e->map[j][i] == 7)
					ft_map_error(e);
			}
			if (!(ft_isdigit(e->map[j][i])))
				ft_map_error(e);
		}
	}
}

void	ft_get_map_grid(t_env *e, int fd)
{
	int i;

	e->map = (char **)malloc(sizeof(char *) * e->map_h + 1);
	if (!(e->map))
		ft_malloc_error();
	e->map[e->map_h] = 0;
	i = 0;
	while (i < e->map_h && get_next_line(fd, &e->map[i]) > 0)
	{
		if (ft_strlen(e->map[i]) != (size_t)e->map_w)
			ft_map_error(e);
		i++;
	}
	if (i < e->map_h)
		ft_map_error(e);
}

void	ft_get_map(t_env *e)
{
	char	*line;
	int		fd;

	fd = open(e->name, O_RDONLY);
	if (fd == -1)
		ft_file_error(e, "opened");
	get_next_line(fd, &line);
	ft_get_map_size(e, line);
	free(line);
	ft_get_map_grid(e, fd);
	ft_validate_maze(e);
	if (close(fd) == -1)
		ft_file_error(e, "closed");
}
