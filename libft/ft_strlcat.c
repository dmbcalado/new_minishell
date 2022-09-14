/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:21:49 by dmendonc          #+#    #+#             */
/*   Updated: 2022/02/14 12:21:53 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	while (dest[i] && i < size)
		i++;
	while (src[j] && (j + i + 1) < size)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i < size)
		dest[i + j] = '\0';
	return (i + ft_strlen((char *)src));
}

/* int	main(void)
{
	char			src[25] = "aa";
	char			dest[60] = "the grass was greener!";
	char			dest2[60] = "the grass was greener!";
	unsigned int	i;
	unsigned int	j;
	char			*ptrdest;
	char			*ptrdest2;
	char			*ptrsrc;

	ptrsrc = src;
	ptrdest = dest;
	ptrdest2 = dest2;
	i = ft_strlcat(ptrdest, ptrsrc, 28);
	printf("size : %d \n dest: %s \n", i, dest);
	j = strlcat(ptrdest2, ptrsrc, 28);
	printf("size : %d \n dest: %s", i, dest2);
} */
