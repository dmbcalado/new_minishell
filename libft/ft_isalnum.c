/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:21:49 by dmendonc          #+#    #+#             */
/*   Updated: 2022/02/14 12:21:53 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int arg)
{
	if ((arg >= 65 && arg <= 90) || (arg >= 97 && arg <= 122))
	{
		return (1);
	}
	else if (arg >= 48 && arg <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/*--|The isalnum() function checks whether the argument passed is an 
		alphanumeric character (alphabet or number) or not.|--*/
//	if alphanumeric char is passed: 1
//	if non-alphanumeric char is passed: 0
