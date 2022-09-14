/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:21:49 by dmendonc          #+#    #+#             */
/*   Updated: 2022/02/14 12:21:53 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	int		mv;

	i = 0;
	mv = n;
	if (!dest && !src)
		return (NULL);
	if (src > dest)
	{
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	else
	{
		while (mv--)
			((char *)dest)[mv] = ((char *)src)[mv];
	}
	return (dest);
}

/* int	main(void)
{
	char		*strs;
	const void	*src;
	void		*dest;
	size_t		i;
	size_t		n;

	i = 0;
	n = 5;
	strs = malloc(sizeof(char) * (n + 2));
	dest = malloc(sizeof(char) * (n + 2));
	while (i <= n)
	{
		strs[i] = 'a' + i;
		i++;
	}
	strs[i] = '\0';
	i = 0;
	src = strs + 1;
	dest = strs;
	printf("source : %s\n", (char *)src);
	dest = ft_memmove(dest, src, 3);
	printf("destiny: %s\n", (char *)dest);
} */
/* --|memmove is used to copy n characters from memory area src to dest|--
	althought memmove is a lot similar to memcpy, it deals better with overlaps
	on memory, since it first copys the words intended to a buffer and then 
	pastes in the destiny.

	dest   ==>    Destiny address of memory to be filled.
 src	   ==>    Source adress from wich we will copy the n char.
  n     ==>    Number of characters to copy. */