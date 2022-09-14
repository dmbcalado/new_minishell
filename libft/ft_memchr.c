/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:21:49 by dmendonc          #+#    #+#             */
/*   Updated: 2022/02/14 12:21:53 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;
	void	*ptr;

	i = 0;
	while (i < n)
	{
		if (*(char *)str == (char)c)
		{
			ptr = (char *)str;
			return (ptr);
		}
		else
		{
			i++;
			str += sizeof(char);
		}
	}
	return (NULL);
}

/* int	main(void)
{
	char		*strs;
	const void	*str;
	size_t		i;
	size_t		n;
	void		*ptr;

	i = 0;
	n = 8;
	strs = malloc(sizeof(char) * (n + 1));
	while(i < n)
	{
		strs[i] = 'a' + i;
		i++;
	}
	strs[i] = '\0';
	str = strs;
	ptr = ft_memchr(str, 101, n);
	printf("str1: %s\n", (char *)str);
	printf("ptr : %s\n", (char *)ptr);

} */
/*--|memchr is used to find a given character in the first n bytes,
	of the string passed in the pointer.|--*/

// 	str    ==>    string in wich we will search for c.
//   c     ==>    character we are searching for.
//   n     ==>    Number of bytes to search for c.

// THIS IS THE FIRST TIME WE SEE A CONSTANT VOID POINTER.
// The constant void pointer is the same as a void pointer, besides the fact 
// that its instructed to point to a memory that should not be modified.