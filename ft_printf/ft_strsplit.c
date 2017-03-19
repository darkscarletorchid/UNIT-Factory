/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrepyto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:05:08 by atrepyto          #+#    #+#             */
/*   Updated: 2016/12/09 15:12:59 by atrepyto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *s, char c)
{
	size_t space;
	size_t nword;

	space = 0;
	nword = 0;
	while (*s)
	{
		if (space == 1 && *s == c)
			space = 0;
		if (space == 0 && *s != c)
		{
			nword++;
			space = 1;
		}
		s++;
	}
	return (nword);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**new;
	size_t	i;
	size_t	j;
	size_t	start;

	if (!s)
		return (0);
	new = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!new)
		return (0);
	i = -1;
	j = 0;
	while (++i < count_word(s, c))
	{
		while (s[j] == c)
			j++;
		start = j;
		while (s[j] != c && s[j] != '\0')
			j++;
		new[i] = ft_strsub(s, start, (j - start));
	}
	new[i] = 0;
	return (new);
}
