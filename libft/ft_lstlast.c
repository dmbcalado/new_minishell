/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:21:49 by dmendonc          #+#    #+#             */
/*   Updated: 2022/02/14 12:21:53 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst -> next == NULL)
			return (lst);
		else
			lst = lst -> next;
	}
	return (NULL);
}

/* int	main(void)
{
	int		i;
	int		j;
	int		k;
	t_list	*t1;
	t_list	*t2;
	t_list	*t3;

	i = 1;
	t1 = (t_list *)malloc(sizeof(t_list));
	t2 = (t_list *)malloc(sizeof(t_list));
	t3 = (t_list *)malloc(sizeof(t_list));
	t1 -> content = &i;
	t1 -> next = t2;
	j = 2;
	t2 -> content = &j;
	t2 -> next = t3;
	k = 3;
	t3 -> content = &k;
	t3 -> next = NULL;
	printf("content1: %d\n", *(int *)(t1 -> content));
	printf("pointer1: %p\n", (char *)(t1 -> next));
	printf("content2: %d\n", *(int *)(t2 -> content));
	printf("pointer2: %p\n", (char *)(t2 -> next));
	printf("content3: %d\n", *(int *)(t3 -> content));
	printf("pointer3: %p\n", (char *)(t3 -> next));
	printf("-----------------------------\n");
	*t1 = *ft_lstlast(t1);
	printf("t1 content after lstlast: %d\n", *(int *)(t1 -> content));
	printf("t1 content after lstlast: %p\n", (char *)(t1 -> next));
}

//returns the last element of the linked list. */