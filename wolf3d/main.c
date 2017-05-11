/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 18:24:19 by atrepyto          #+#    #+#             */
/*   Updated: 2017/03/31 18:24:21 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(int ac, char **av)
{
	t_env	e;

	if (ac == 1)
	{
		e.name = "maps/level1.wolf3d";
		e.level = 1;
		//ft_get_map(&e);
		ft_init_env(&e);
	}
	else
		ft_put_usage(av[0]);
	return (0);
}
