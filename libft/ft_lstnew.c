/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:21:49 by dmendonc          #+#    #+#             */
/*   Updated: 2022/02/14 12:21:53 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*first;

	first = (t_list *)malloc(sizeof(t_list));
	if (!first)
		return (NULL);
	first -> content = content;
	first -> next = NULL;
	return (first);
}

/* int	main(void)
{
	int		i;
	t_list	*first;

	i = 101;
	first = ft_lstnew(&i);
	printf("content: %d\n", *(int *)(first -> content));
	printf("pointer: %s\n", (char *)(first -> next));
} */

/* Lstnew creates a new node of the linked list, casting the content
passed as parameter and atributing it, and by pointing it to NULL.
 	-----------------------------
	|				|			|
	|	 CONTENT	|	NEXT  --|----> NULL
	|				|			|
	-----------------------------           */