/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:21:49 by dmendonc          #+#    #+#             */
/*   Updated: 2022/02/14 12:21:53 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nitems, size_t sizeofitems)
{
	void	*pointer;

	pointer = malloc(nitems * sizeofitems);
	if (!pointer)
		return (NULL);
	ft_bzero(pointer, nitems * sizeofitems);
	return (pointer);
}

/* int	main(void)
{
	void	*ptr;
	int		i;

	i = 0;
	ptr = ft_calloc(5, sizeof(char));
	while (i < 79)
	{
		printf("%d ", *(int *)ptr);
		ptr += sizeof(char);
		i++;
	}
}
 */