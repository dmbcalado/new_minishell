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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	i;
	unsigned int	cont;

	i = 0;
	cont = 0;
	if (!s)
		return (NULL);
	if (ft_strlen((char *)s) - start < len && start <= ft_strlen((char *)s))
		ptr = (char *)malloc((ft_strlen((char *)s) - start + 1) * sizeof(char));
	else if (start <= ft_strlen((char *)s))
		ptr = malloc((len + 1) * sizeof(char));
	else
		ptr = malloc(sizeof(char));
	if (!ptr)
		return (NULL);
	while (s[cont])
	{
		if (cont >= start && i < len)
			ptr[i++] = (char)s[cont];
		cont++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/* int	main(void)
{
	char const			*string = "o pai ta on tipo neymar.";
	char				*ptr;
	int					cont;
	unsigned int		go;
	size_t				len;

	cont = 0;
	go = 25;
	len = 40;
	printf("\ninput:\n");
	printf("\n");
	while (*string != '\0')
	{
		printf("%c", *(char *)string);
		string += sizeof(char);
		cont++;
	}
	string -= sizeof(char) * cont;
	ptr = ft_substr(string, go, len);
	printf("\n");
	printf("\nsubstring:\n");
	printf("\n");
	while (*ptr != '\0')
	{
		printf("%c", *(char *)ptr);
		ptr += sizeof(char);
		cont++;
	}
	printf("\n\n");
} */
