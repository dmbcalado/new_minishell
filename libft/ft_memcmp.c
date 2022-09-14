/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:21:49 by dmendonc          #+#    #+#             */
/*   Updated: 2022/02/14 12:21:53 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t	i;
	int		cmp;

	i = 0;
	cmp = 0;
	while (i < n)
	{
		if (*(unsigned char *)str1 == *(unsigned char *)str2)
		{
			i++;
			str1 += sizeof(char);
			str2 += sizeof(char);
		}
		else
		{
			cmp = *(unsigned char *)str1 - *(unsigned char *)str2;
			return (cmp);
		}
	}
	return (cmp);
}

/* int	main(void)
{
	char		*strs1;
	char		*strs2;
	const void	*str1;
	const void	*str2;
	size_t		i;
	size_t		n;
	int			cmp;

	i = 0;
	n = 8;
	strs1 = malloc(sizeof(char) * (n + 1));
	strs2 = malloc(sizeof(char) * (n + 1));
	while(i < n)
	{
		strs1[i] = 'a' + i;
		i++;
	}
	strs1[i] = '\0';
	i = 0;
	while(i < (n - 4))
	{
		strs2[i] = 'a' + i;
		i++;
	}
	while(i < n)
	{
		strs2[i] = 'k' + i;
		i++;
	}
	strs2[i] = '\0';
	str1 = strs1;
	str2 = strs2;
	cmp = ft_memcmp(str1, str2, n);
	printf("str1: %s\n", (char *)str1);
	printf("str2: %s\n", (char *)str2);
	printf("comparing: %d\n", cmp);
} */
/*--|memcmp is used to compare the first n bytes of 2 blocks of memory.|--*/
// 	str1   ==>    first block of memory.
//  str2   ==>    second block of memory.
//   n     ==>    Number of bytes to be compared.
// THIS IS THE FIRST TIME WE SEE A CONSTANT VOID POINTER.
// The constant void pointer is the same as a void pointer, besides the fact 
// that its instructed to point to a memory that should not be modified.