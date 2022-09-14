/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:21:49 by dmendonc          #+#    #+#             */
/*   Updated: 2022/02/14 12:21:53 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	looping(char const *s1, char const *set, int starter)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (s1[starter] == set[i])
		{
			i = 0;
			starter++;
		}
		else
			i++;
	}
	return (starter);
}

int	give_last_rev(char const *s1, char const *set, int last)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (s1[last] == set[i])
		{
			i = 0;
			last --;
		}
		else
			i++;
	}
	return (last);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		first;
	int		last;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	first = looping(s1, set, 0);
	if (first == (int)ft_strlen((char *)s1))
	{
		ptr = malloc(sizeof(char));
		*ptr = '\0';
		return (ptr);
	}
	last = ft_strlen((char *)s1) - 1;
	last = give_last_rev(s1, set, last);
	ptr = ft_substr(s1, (unsigned int)first, (last - first + 1));
	return (ptr);
}

/* 
int	main(void)
{
	char	*str1 = "          "; //27
	char	*str2 = " "; //18
	char	*dest;

	dest = ft_strtrim(str1, str2);
	printf("%s", dest);
	dest = strtrim(str1, str2);
	printf("%s", dest);
} */