/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:21:49 by dmendonc          #+#    #+#             */
/*   Updated: 2022/02/14 12:21:53 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(fd, "-2", 2);
			n = -147483648;
		}
		else
			write(fd, "-", 1);
		n *= -1;
	}
	if (n >= 0 && n < 10)
	{
		c = 48 + n;
		write(fd, &c, 1);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		c = 48 + n % 10;
		write(fd, &c, 1);
	}
}

/* int	main(void)
{
	ft_putnbr_fd(-420, 1);
} */
