/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:21:49 by dmendonc          #+#    #+#             */
/*   Updated: 2022/02/14 12:21:53 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalpha(int arg)
{
	if (arg >= 65 && arg <= 90)
	{
		return (1);
	}
	else if (arg >= 97 && arg <= 122)
	{
		return (2);
	}
	else
	{
		return (0);
	}
}

/*--|The isalpha() function checks whether a character is an alphabet|--*/
//	if uppercase alphabet is passed: 1
//	if lowercase alphabet is passed: 2
//	else : 0