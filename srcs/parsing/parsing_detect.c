/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_detect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:54:28 by dmendonc          #+#    #+#             */
/*   Updated: 2022/09/14 19:36:25 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	full_detector(t_data *data, char *str)
{
	if (builtin_detector (data, str) > 0)
		return (1);
	else if (cmd_detector(data, str) == 1)
		return (2);
	else if (redir_detector(data, str) > 0)
		return (3);
	return (0);
}

int	builtin_detector(t_data *data, char *str)
{
	int	i;
	int	j;
	int	size;

	j = -1;
	while (data->built.builtins[++j])
	{
		size = 0;
		while(data->built.builtins[j][size])
			size++;
		i = -1;
		while(str[++i])
		{
			if(str[i] != data->built.builtins[j][i])
				break;
			else if(i == size - 1)
				return(j);
		}
	}
	return(0);
}

// -----------------------------------------------------------------------------
// This function checks if its a command the string given.
// -----------------------------------------------------------------------------

int	cmd_detector(t_data *data, char *str)
{
	int	i_p;

	i_p = -1;
	while(data->paths.paths[++i_p])
	{
		joining (data, str, i_p);
		if (access (data->paths.test_cmd, X_OK) == 0)
		{
			free(data->paths.test_cmd);
			return (1);
		}
		else
			free(data->paths.test_cmd);
	}
	return(0);
}

int	redir_detector(t_data *data, char *str)
{
	int i;
	int j;
	
	i = -1;
	while(str[++i])
	{
		j = -1;
		while(data->redir.redir_lib[++j])
		{
			if(str[i] == data->redir.redir_lib[j])
			{
				if(j == 0)
					return (1);
				else if (j == 1)		// <
				{
					if(str[i + 1] == data->redir.redir_lib[j])
						return (3);
					else
						return (2);
				}
				else if (j == 2)		// >
				{
					if(str[i + 1] == data->redir.redir_lib[j])
						return (5);
					else
						return (4);	
				}
			}
		}
	}
	return(0);
}