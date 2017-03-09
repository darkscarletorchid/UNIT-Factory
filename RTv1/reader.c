#include "RTv1.h"

void	read_scene(int fd, t_env *e)
{
	char *line;

	while (get_next_line(fd, &line) > 0 && ft_strcmp(ft_strtrim(line), "}"))
	{
		if (ft_strstr(line, "name"))
			e->scene.title = find_name(line);
		else if (ft_strstr(line, "size"))
			find_scene_size(line, &e->scene.width, &e->scene.height);
		else if (ft_strstr(line, "camera"))
			find_camera_params(fd, e);
		else if (ft_strstr(line, "light"))
			find_light_params(fd, e);
		ft_strdel(&line);
	}
	ft_strdel(&line);
}


void	read_objects(int fd, t_env *e)
{
	char	*line;

	while (get_next_line(fd, &line) > 0 && ft_strcmp(ft_strtrim(line), "}"))
	{
		if (ft_strstr(line, "number of objects"))
		{
			e->scene.obj_nb = (int)find_double(line);
			e->scene.obs = (t_object *)malloc(sizeof(t_object) * e->scene.obj_nb); //free in the end
			find_obj(fd, e);
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
}

void	read_file(int fd, t_env *e)
{
	char *line;

	while (get_next_line(fd, &line) && ft_strstr(line, "#end") == 0)
	{
		if (ft_strstr(line, "scene"))
			read_scene(fd, e);
		else if (ft_strstr(line, "objects"))
			read_objects(fd, e);
		ft_strdel(&line);
	}
	ft_strdel(&line);
}

void	open_file(char *file, t_env *e)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("Open error");
	read_file(fd, e);
	if (close(fd) == -1)
		ft_error("Close error");
}