/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 22:48:56 by dmendonc          #+#    #+#             */
/*   Updated: 2022/08/29 00:32:09 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*substring(char *s, int start, int len)
{
	int		i;
	int		fulen;
	char	*ptr;

	i = -1;
	fulen = 0;
	while (s[fulen])
		fulen++;
	if (fulen - start < len && start < fulen)
	{
		ptr = (char *)malloc((fulen - start + 1) * sizeof(char));
		len = fulen - start;
	}
	else if (fulen - start >= len)
	{
		ptr = (char *)malloc((len + 1) * sizeof(char));
		ptr[len] = 0;
	}
	start--;
	while (++start < fulen && ++i < len)
		ptr[i] = s[start];
	return (ptr);
}

int	count_rows(char *s, char c)
{
	int	how_many;
	int	i;
	int	flag;

	i = -1;
	how_many = 0;
	flag = 0;
	while (s[++i])
	{
		if (s[i] == c)
			flag = 1;
		while (s[i] == c)
			i++;
		if (flag == 0)
			continue ;
		how_many++;
		flag = 0;
		if (s[i] == '\0')
			break ;
	}
	return (how_many + 1);
}

int	find_c(char *s, char c, int index)
{
	int	i;

	i = index + 1;
	while (!(s[i] == c || s[i] == '\0'))
		i++;
	return (i);
}

int	find_len(char *s, char c, int index)
{
	int	i;
	int	size;

	size = 0;
	i = index;
	while (!(s[i] == c || s[i] == '\0'))
	{
		i++;
		size++;
	}
	return (size);
}

char	**spliting(char *s, char c)
{
	int		i;
	int		index;
	char	**matrix;

	matrix = (char **)malloc((count_rows(s, c) + 1) * sizeof(char *));
	if (!matrix)
		return (NULL);
	index = 0;
	i = 0;
	while (s[index] != '\0')
	{
		while (s[index] == c)
			index++;
		if (s[index] == '\0')
			break ;
		matrix[i] = substring(s, index, find_len(s, c, index));
		i++;
		index = find_c(s, c, index);
		index++;
		if (s[index - 1] == '\0')
			break ;
	}
	matrix[i] = NULL;
	return (matrix);
}
