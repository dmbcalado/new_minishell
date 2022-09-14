/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:21:49 by dmendonc          #+#    #+#             */
/*   Updated: 2022/02/14 12:21:53 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	howmanymics(const char *str, int c)
{
	int		how_many;
	int		i;

	how_many = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			how_many++;
		}
		i++;
	}
	return (how_many);
}

char	*pointtolast(const char *str, int c, int how_many)
{
	int		enough;

	enough = 0;
	while (*str)
	{
		if (*str == (char)c)
		{
			enough++;
			if (how_many == enough)
				return ((char *)str);
		}
		str++;
	}
	if (*(char *)str == (char)c)
		return ((char *)str);
	return (NULL);
}

char	*ft_strrchr(const char *str, int c)
{
	int		how_many;
	char	*ptr;

	while (c < 0)
		c += 128;
	while (c > 127)
		c -= 128;
	how_many = howmanymics(str, c);
	if (how_many == 0 && c != 0)
		return (NULL);
	ptr = pointtolast(str, c, how_many);
	return (ptr);
}

/* int	main(void)
{
	const char	*str =  "tripoulie do crl";
	char		*ptr;
	char		*ptr2;
	int			i;

	i = 0;
	ptr = ft_strrchr(str, 't' + 256);
	ptr2 = (char *)str + strlen(str);
	printf("char: %c\nadress: %p\n\n", *(char *)ptr, ptr);
	printf("char: %c\nadress: %p", *(char *)ptr2, ptr2);
	if (ptr == ptr2)
		printf("true\n");
} */
/*--|strrchr returns a pointer to the last occurrence of the character in 
	a given string|--*/
// 	str   ==>    str is a constant char array, 
//   c    ==>    Char to be found, given in ascii number.