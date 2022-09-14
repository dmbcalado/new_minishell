/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:21:49 by dmendonc          #+#    #+#             */
/*   Updated: 2022/02/14 12:21:53 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char	*str, const char *to_find, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
		return ((char *)str);
	while (*str != '\0' && i < len)
	{
		while (str[j] == to_find[j] && (i + j) < len)
		{
			if (to_find[j + 1] == '\0')
			{
				return ((char *)str);
			}
			j++;
		}
		i++;
		str++;
		j = 0;
	}
	return (0);
}

/* int	main(void)
{
	char	haystack[30] = "aaabcabcd";
	char	needle[10] = "aabc";
	char	*ptr;
	size_t	i;

	i = -1;
	printf("%zu\n", i);
 	ptr = ft_strnstr(haystack, needle, -1);
 	printf("%s\n", ptr);
} */
/*--|The strnstr() function locates the	first occurrence of the	
	null-terminated string to_find in the	string str, where 
	not more than	len characters are searched.|--*/