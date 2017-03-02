/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:30:54 by atrepyto          #+#    #+#             */
/*   Updated: 2017/01/13 17:59:43 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_lst	*ft_create_elem(char *data, int index)
{
	t_lst	*element;
	int		x;
	int		y;

	x = 1;
	y = 1;
	element = NULL;
	element = malloc(sizeof(t_lst));
	element->data = data;
	element->letter = 'A' + index;
	element->cd = ft_coordinate(data, x, y);
	element->min = find_min(element->cd);
	element->max = find_max(element->cd);
	element->next = NULL;
	return (element);
}

void	ft_list_push_back(t_lst **begin_list, char *data, int index)
{
	t_lst *current;

	current = *begin_list;
	if (current == NULL)
		*begin_list = ft_create_elem(data, index);
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = ft_create_elem(data, index);
	}
}

t_lst	*ft_divide(char *str, int len)
{
	t_lst	*list;
	int		j;
	char	*tetr;
	int		index;

	j = 0;
	index = -1;
	list = NULL;
	while (len)
	{
		tetr = ft_strsub(str, j, 20);
		if (ft_validate(tetr) && ft_count(tetr))
			ft_list_push_back(&list, tetr, ++index);
		j = j + 21;
		len--;
	}
	return (list);
}
