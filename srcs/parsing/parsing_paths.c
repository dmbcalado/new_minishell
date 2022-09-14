/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:13:18 by dmendonc          #+#    #+#             */
/*   Updated: 2022/09/09 01:52:29 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"
// ----------------------------------------------------------------------------
// Function trims the beggining of the envp[i] = PATH:(...)
// ----------------------------------------------------------------------------

void	path_str(t_data *data)
{
	int	i;
	int	j;
	int	k;
	int	len;

	i = -1;
	j = 0;
	k = 4;
	len = 0;
	while (data->envp[++i])
	{
		if (compare (data->envp[i], "PATH") == -2)
		{
			j = 1;
			break ;	
		}
	}
	if(j != 1)
	{
		printf(": No such file or directory\n");
		data->paths.p_str = NULL;
		return ;
	}
	j = 0;
	while (data->envp[len])
		len++;
	if(i == len)
		return ;	
	while (data->envp[i][j])
		j++;
	data->paths.p_str = malloc((j + 1) * sizeof(char));
	while (data->envp[i][++k] != 0)
		data->paths.p_str[k - 5] = data->envp[i][k];
	data->paths.p_str[k - 5] = '\0';
}

// ----------------------------------------------------------------------------
// Function ataches the bar '/' to the paths.
// ----------------------------------------------------------------------------

void	joinbar(t_data *data, int index)
{
	int	i;

	i = 0;
	while (data->paths.spaths[index][i] != '\0')
		i++;
	data->paths.paths[index] = (char *)malloc((i + 2) * sizeof(char));
	i = -1;
	while (data->paths.spaths[index][++i])
		data->paths.paths[index][i] = data->paths.spaths[index][i];
	data->paths.paths[index][i] = '/';
	data->paths.paths[index][i + 1] = '\0';
}

// -----------------------------------------------------------------------------
// Function uses path_returner() to colect the PATH from the envp given by the
// the environment, and uses split to get each path seperatly. After that stores
// in data->paths each seperate path with '/' atached. ex: /usr/bin/
// -----------------------------------------------------------------------------

void	get_paths(t_data *data)
{
	int	i;
	int	count;

	i = -1;
	path_str(data);
	if(data->paths.p_str != NULL)
	{
		count = how_many_paths(data->paths.p_str, 58) + 1;
		data->paths.spaths = spliting(data->paths.p_str, ':');
		data->paths.paths = (char **)malloc(count * sizeof(char *));
		data->paths.paths[count - 1] = NULL;
		while (data->paths.spaths[++i])
		{
			joinbar(data, i);
			free(data->paths.spaths[i]);
		}
		free(data->paths.spaths);
	}
}

// -----------------------------------------------------------------------------
// Function joins the path/ with the command.
// -----------------------------------------------------------------------------

void	path_join(t_data *data, int index, int i_p)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	j = -1;
	count = path_size(data, index, i_p) + 1;
	data->paths.path_cmd[index] = (char *)malloc(count * sizeof(char));
	while (data->paths.paths[i_p][++i])
		data->paths.path_cmd[index][i] = data->paths.paths[i_p][i];
	data->paths.path_cmd[index][0] = '/';
	while (data->cmd.cmdx[index][0][++j])
		data->paths.path_cmd[index][i++] = data->cmd.cmdx[index][0][j];
	data->paths.path_cmd[index][i] = '\0';
}