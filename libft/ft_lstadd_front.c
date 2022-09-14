/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:21:49 by dmendonc          #+#    #+#             */
/*   Updated: 2022/02/14 12:21:53 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new -> next = *lst;
	*lst = new;
}

/*Adds the node ’new’ at the beginning of the list

    -			  NEW           -
 	-----------------------------
	|				|			|
	|	 CONTENT	|	NEXT 	|
	|				|	  |		|
	-----------------------------
	LIST:			      | 
	-----------------------------
	|				|	  v		|
	|	 CONTENT	|	NEXT 	|
	|				|	  |		|
	----------------------------- 	
	-			(...)     |
	
And: *lst = new 
turns the new into the first element of the list    */
