#include "RTv1.h"

void	find_light_pos(char *line, t_env *e)
{
	int i;

	i = 0;
	while (i < e->scene.light_nb)
	{
		while (*line != '{')
			line++;
		find_coord(line++, &e->scene.lights[i].pos);
		i++;
	}
}

void	find_light_intensity(char *line, t_env *e)
{
	int i;

	i = 0;
	while (i < e->scene.light_nb)
	{
		while (*line != '{')
			line++;
		find_coord(line++, &e->scene.lights[i].intensity);
		i++;
	}
}

void	find_light_params(int fd, t_env *e)
{
	char	*line;

	while (get_next_line(fd, &line) > 0 && ft_strcmp(ft_strtrim(line), "}"))
	{
		if (ft_strstr(line, "number of light"))
		{
			e->scene.light_nb = (int)find_double(line);
			e->scene.lights = (t_light *)malloc(sizeof(t_light) * e->scene.light_nb);
		}
		else if (ft_strstr(line, "position"))
			find_light_pos(line, e);
		else if (ft_strstr(line, "intensity"))
			find_light_intensity(line, e);
		ft_strdel(&line);
	}
	ft_strdel(&line);
}

