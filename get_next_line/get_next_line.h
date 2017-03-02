/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:53:13 by atrepyto          #+#    #+#             */
/*   Updated: 2017/01/27 11:46:18 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# define BUFF_SIZE 8

typedef struct	s_lst
{
	char			*tmp;
	int				fd;
	struct s_lst	*next;
}				t_lst;
int				get_next_line(const int fd, char **line);
#endif
