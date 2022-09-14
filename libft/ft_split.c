/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:21:49 by dmendonc          #+#    #+#             */
/*   Updated: 2022/02/14 12:21:53 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	how_many_rows(char const *s, char c)
{
	int	how_many;
	int	i;
	int	flag;

	i = 0;
	how_many = 0;
	flag = 0;
	while (s[i] != '\0')
	{
		while (!(s[i] == '\0' || s[i] == c))
		{
			i++;
			flag = 1;
		}
		while (s[i] == c)
			i++;
		if (flag == 0)
			continue ;
		how_many++;
		if (s[i - 1] == '\0')
			break ;
	}
	return (how_many);
}

int	find_next_c(char const *s, char c, int index)
{
	int	i;

	i = index;
	while (!(s[i] == c || s[i] == '\0'))
	{
		i++;
	}
	return (i);
}

int	find_size(char const *s, char c, int index)
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

char	**ft_split(char const *s, char c)
{
	char			**matrix;
	unsigned int	index;
	int				i;

	if (!s)
		return (NULL);
	matrix = (char **)malloc((how_many_rows(s, c) + 1) * sizeof(char *));
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
		matrix[i++] = ft_substr(s, index, find_size(s, c, index));
		index = find_next_c(s, c, index);
		index++;
		if (s[index - 1] == '\0')
			break ;
	}
	matrix[i] = NULL;
	return (matrix);
}

/* int	main(void)
{
	char const	*original_str = "                  olol";
	char		**house_divided;
	int			i;
	int			j;
	int			how_many_r;

	i = 0;
	j = 0;
	how_many_r = how_many_rows(original_str, ' ');
	house_divided = ft_split(original_str, ' ');
	while (i < how_many_r)
	{
		while (*house_divided[i] != '\0')
		{
			printf("%c", *(char *)house_divided[i]);
			house_divided[i] += sizeof(char);
		}
		printf("\n");
		i++;
	}
} */
