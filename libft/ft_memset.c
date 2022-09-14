/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:21:49 by dmendonc          #+#    #+#             */
/*   Updated: 2022/02/14 12:21:53 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *ptr, int ascii, size_t n)
{
	size_t	i;
	char	c;

	c = ascii;
	i = 0;
	while (i < n)
	{
		*(char *)ptr = c;
		ptr += sizeof(char);
		i++;
	}
	ptr -= i * sizeof(char);
	return (ptr);
}

/* int	main(void)
{
	char	*strs;
	void	*ptr;
	int		i;
	int		n;

	i = 0;
	n = 8;
	strs = malloc(sizeof(char) * n);
	ptr = strs;
	ft_memset(ptr, 97, n);
	while(i < n)
	{
		printf("%c", strs[i]);
		i++;
	}
} */
/*--|memset is used to fill a block of memory with a particular value|--*/

// 	ptr   ==>    Starting address of memory to be filled
//  ascii ==>    Char to be filled in, given in ascii number.
//   n    ==>    Number of bytes to be filled starting from ptr to be filled