/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:21:49 by dmendonc          #+#    #+#             */
/*   Updated: 2022/02/14 12:21:53 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (dest);
	if (src == 0 && dest == 0)
		return (NULL);
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

/* int	main(void)
{
	char		*strs = "rimas";
	const void	*src;
	void		*dest;
	size_t		i;
	size_t		n;

	i = 0;
	n = 9;
	dest = malloc(sizeof(char) * (10));
	i = 0;
	src = strs;
	printf("source: %s\n", (char *)src);
	dest = ft_memcpy(dest, src, 5);
	printf("destiny: %s\n", (char *)dest);
} */
/*--|memcpy is used to copy n characters from memory area src to dest|--*/
// 	dest   ==>    Destiny address of memory to be filled.
//  src	   ==>    Source adress from wich we will copy the n char.
//   n     ==>    Number of characters to copy.