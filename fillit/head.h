/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:59:22 by atrepyto          #+#    #+#             */
/*   Updated: 2017/01/13 18:50:20 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdlib.h>
# define BUFF_SIZE 545

typedef struct	s_square {
	char	**field;
	int		size;
}				t_square;
typedef struct	s_lst
{
	char			*data;
	char			letter;
	int				**cd;
	int				*min;
	int				*max;
	struct s_lst	*next;
}				t_lst;
void			*ft_memset(void *b, int c, size_t len);
void			ft_putendl(char *str);
void			ft_putstr(char *str);
void			ft_strdel(char **as);
char			*ft_strdup(const char *src);
size_t			ft_strlen(const char *str);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
void			ft_error(void);
char			*ft_read(int fd);
int				ft_validate(char *str);
int				ft_count(char *str);
int				**ft_coordinate(char *str, int x, int y);
int				*find_min(int **cd);
int				*find_max(int **cd);
t_lst			*ft_create_elem(char *data, int index);
t_lst			*ft_divide(char *str, int len);
void			free_square(t_square **square);
void			ft_sqroutput(char **square);
int				ft_sqrlen(int len);
t_square		*ft_square(int len);
int				ft_checkput(t_lst *list, char **field, int x, int y);
int				ft_remove(t_lst *list, char **field, int x, int y);
int				*ft_size(int *min, int *max);
int				ft_putelem(t_square *square, t_lst *list);
void			ft_solve(char *str);
void			ft_valid_file(char *str, int i);
void			free_list(t_lst *list);
void			free_list_list(t_lst **lst);
void			free_str(char *str);
void			free_int1(int **cd);
void			free_min_max(int *array);
void			ft_del(char **d);
#endif
