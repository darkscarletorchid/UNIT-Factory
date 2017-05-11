/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 18:27:47 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/31 18:27:48 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_file_error(t_env *e, char *s)
{
	ft_putstr("File ");
	ft_putstr(e->name);
	ft_putstr(" cannot be ");
	ft_putendl(s);
	exit(-1);
}

void	ft_malloc_error(void)
{
	ft_putendl("Cannot allocate memory");
	exit(-1);
}

void	ft_map_error(t_env *e)
{
	ft_putstr("Invalid map ");
	ft_putendl(e->name);
	exit(-1);
}

void	ft_put_usage(char *s)
{
	ft_putendl("Invalid number of parameters");
	ft_putstr("Usage: ");
	ft_putendl(s);
	exit(0);
}
