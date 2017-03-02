/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:58:03 by atrepyto          #+#    #+#             */
/*   Updated: 2017/01/13 14:58:08 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	free_str(char *str)
{
	free(str);
	str = NULL;
}

void	free_int1(int **cd)
{
	int i;

	i = 0;
	while (i < 4)
	{
		free(cd[i]);
		i++;
	}
	free(cd);
}

void	free_min_max(int *array)
{
	free(array);
	array = NULL;
}

void	free_list(t_lst *list)
{
	t_lst *tmp;
	t_lst *buf;

	while (list)
	{
		tmp = list;
		buf = list;
		free_str(tmp->data);
		free_int1(tmp->cd);
		free_min_max(tmp->min);
		free_min_max(tmp->max);
		tmp = NULL;
		free(tmp);
		list = buf->next;
	}
	list = NULL;
}

void	free_list_list(t_lst **lst)
{
	t_lst *tmp;

	while (*lst)
	{
		tmp = *lst;
		free(*lst);
		*lst = tmp->next;
	}
	*lst = NULL;
}
