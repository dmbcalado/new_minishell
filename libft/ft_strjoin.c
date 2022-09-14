/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:32:49 by dmendonc          #+#    #+#             */
/*   Updated: 2022/01/24 14:32:51 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*ptr;
	int		size1;
	int		size2;

	if (!str1 || !str2)
		return (NULL);
	size1 = (int)ft_strlen((char *)str1);
	size2 = (int)ft_strlen((char *)str2);
	ptr = (char *)malloc((size1 + size2 + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	if ((size1 + size2) == 0)
	{
		*ptr = '\0';
		return (ptr);
	}
	ft_strlcpy(ptr, (char *)str1, size1 + 1);
	ptr += size1 * sizeof(char);
	ft_strlcpy(ptr, (char *)str2, size2 + 1);
	ptr += (size2) * sizeof(char);
	*ptr = '\0';
	ptr -= (size2) * sizeof(char);
	ptr -= size1 * sizeof(char);
	return (ptr);
}

/* int	main(void)
{
	//char const	*str1 = "literalmente e so escrever ";
	//char const	*str2 = "duas strings a toa";
	char		*dest;

	dest = ft_strjoin("", "");
	printf("%s", dest);
} */
