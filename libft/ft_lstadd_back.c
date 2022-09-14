/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:21:49 by dmendonc          #+#    #+#             */
/*   Updated: 2022/02/14 12:21:53 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = *lst;
	if (!last)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(last);
	last -> next = new;
}

/*Adds the node ’new’ at the end of the list.
For that we first test if the list exists, if it does,
then we use the function ft_lstlast() to reach the last
element of the list. After that we just need to point the
last element to the new one, and point the new one to NULL.

    (...)Last element of the list:
 	-----------------------------
	|				|			|
	|	 CONTENT	|	NEXT 	|0
	|				|	  |		|
	-----------------------------
	NEW:			      | 
	-----------------------------
	|				|	  v		|
	|	 CONTENT	|	NEXT ---|---> NULL 
	|				|	  		|
	----------------------------- 	
 */