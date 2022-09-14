/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:21:49 by dmendonc          #+#    #+#             */
/*   Updated: 2022/02/14 12:21:53 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		index;
	char	*pointer;

	index = 0;
	while (s[index] != '\0')
		index++;
	pointer = malloc((index + 1) * sizeof(char));
	if (!pointer)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		pointer[index] = s[index];
		index++;
	}
	pointer[index] = '\0';
	return (pointer);
}

/* int	main(void)
{
	const char	*str = "vamos la ver se isto da";
	char		*ptr;

	ptr = strdup(str);
	printf("str : %s\n", (char *)str);
	printf("ptr : %s\n", (char *)ptr);

} */
