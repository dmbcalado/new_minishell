/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:21:49 by dmendonc          #+#    #+#             */
/*   Updated: 2022/02/14 12:21:53 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*(char *)str == (char)c)
		{
			return ((char *)str);
		}
		str++;
	}
	if (*(char *)str == (char)c)
		return ((char *)str);
	return (0);
}

/* int	main(void)
{
    const char  *str =  "\0";
    char        *ptr;
    int         i;

	i = 0;
    //ptr = ft_strchr(str, 97); // 'a' = 97
	ptr = ft_strchr(str, 0);
    while (ptr[i] != '\0')
    {
        printf("%c", ptr[i]);
		i++;
    }
	printf("\n");
} */
/*--|strrchr returns a pointer to the first occurrence of the character 
		in a given string|--*/
// 	str   ==>    str is a constant char array. 
//   c    ==>    Char to be found, given in ascii number.
