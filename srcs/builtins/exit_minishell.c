/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:53:19 by anfreire          #+#    #+#             */
/*   Updated: 2022/10/10 21:38:03 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static int	ft_isdigit_n_dash(int arg)
{
	if ((arg >= 48 && arg <= 57) || arg == '-')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

static int	is_string_digit(char *str)
{
	int	i;

	i = -1;
	while(str[++i])
	{
		if(!ft_isdigit_n_dash(str[i]))
			return (0);
	}
	return (1);
}

static int	return_exit_v2(int	digit)
{
	int	div;
	
	if (digit < 0)
	{
		digit = -digit;
		div = (digit / 256);
		while (--div > 0)
		{
			digit = digit / 256;
		}
		digit %= 256;
		digit = 256 - digit;
	}
	else if (digit > 0)
	{
		div = (digit / 256);
		while (--div > 0)
		{
			digit /= 256;
		}
		digit %= 256;
	}
	return (digit);
}

static int	return_exit(char *str)
{
	int	digit;

	digit = ft_atoi(str);
	if (return_exit_v2(digit))
		return (return_exit_v2(digit));
	return (0);
}


void	exit_minishell(t_data *data)
{
	int	args;

	args = 0;
	while(data->par_line[args])
		args++;
	if(args >= 2)
	{
		if (!is_string_digit(data->par_line[1]))
		{
			printf("minishell: exit: %s: numeric argument required\n", data->par_line[1]);
			exit(2);
		}
		else if (args == 2)
		{
			printf("exit\n");
			exit(return_exit(data->par_line[1]));
		}
		printf("minishell: exit: too many arguments\n");
		exit(1);
	}
	printf("exit\n");
	exit(0);
}