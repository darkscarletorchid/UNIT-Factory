/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:11:00 by atrepyto          #+#    #+#             */
/*   Updated: 2017/01/13 18:49:50 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	ft_error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

char	*ft_read(int fd)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*str;
	int		count;

	count = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		str = ft_strdup(buf);
		count++;
	}
	if (count != 1)
		ft_error();
	return (str);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*str;

	if (argc != 2)
	{
		ft_putendl("usage: fillit input_file");
		exit(0);
	}
	else
	{
		fd = open(argv[1], O_RDONLY | S_IRUSR);
		if (fd == -1)
			ft_error();
		str = ft_read(fd);
		ft_valid_file(str, 0);
		ft_solve(str);
		if (close(fd) == -1)
			ft_error();
	}
	return (0);
}
