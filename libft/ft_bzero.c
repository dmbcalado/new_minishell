/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:21:49 by dmendonc          #+#    #+#             */
/*   Updated: 2022/02/14 12:21:53 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *ptr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)ptr = 0;
		ptr += sizeof(char);
		i++;
	}
	ptr -= sizeof(char) * (int)i;
}

/* int	main(void)
{
	char	*strs;
	void	*ptr;
	size_t	i;
	size_t	n;

	i = 0;
	n = 8;
	strs = malloc(sizeof(char) * (n + 1));
	while(i < n)
	{
		strs[i] = 'a';
		i++;
	}
	strs[i] = '\0';
	printf("before bzero: %s\n", strs);
	ptr = strs;
	ft_bzero(ptr, 1);
	printf("after bzero: %s\n", strs);
} */
/*--|bzero is used to NULL a block of memory|--*/

// 	ptr   ==>    Starting address of memory to be nulled.
//   n    ==>    Number of bytes to be nulled.

// THIS IS THE FIRST TIME WE SEE A VOID POINTER.
// Void pointers serve only to point, and cannot be atributed memory to them,
// so in order for us to change the memory block at wich he is pointing we need
// to specify wich kind of variable we are pointing to, by typing at this case,
// *(char *)ptr we work the pointer as if he was a char pointer.