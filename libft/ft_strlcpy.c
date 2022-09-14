/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:21:49 by dmendonc          #+#    #+#             */
/*   Updated: 2022/02/14 12:21:53 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	srcsize;
	size_t			contador;

	i = 0;
	contador = 0;
	srcsize = (unsigned int)ft_strlen(src);
	if (size == 0)
		return (srcsize);
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
		if (size < srcsize)
			contador++;
	}
	contador += srcsize;
	dest[i] = '\0';
	contador = srcsize;
	return (contador);
}

/* int	main(void)
{
	char			a[] = "123456789";
	char			b[12] = "say what";
	char			*patha;
	char			*pathb;
	int				cont;
	unsigned int 	sizin;

	cont = 0;
	patha = a;
	pathb = b;
	sizin = ft_strlcpy(pathb, patha, 3);
	while (pathb[cont] != '\0')
	{
		printf("%c", pathb[cont]);
		cont++;
	}
	printf("\n%d", sizin);
	cont = 0;
	sizin = strlcpy(pathb, patha, 3);
	printf("\n");
	while (pathb[cont] != '\0')
	{
		printf("%c", pathb[cont]);
		cont++;
	}
	printf("\n%d\n", sizin);
}
 */