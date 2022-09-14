/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 01:04:26 by dmendonc          #+#    #+#             */
/*   Updated: 2022/09/13 16:47:50 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

// -----------------------------------------------------------------------------
// Function allocates all data gpaths.iven for the commands, and stores cmdx[][][]
// matrix that has the format exemplified below:
// cmdx[cmd n-1]+...  [0] = "ls"	;	[1] = "-a"
// cmdx[cmd n]  +... [0] = "grep"	;	[1] = "hello"
// -----------------------------------------------------------------------------

int	count_cmd_args(t_data *data, int i)
{
	int	count;
	
	count = 0;
	while(data->par_line[++i])
	{
		if (builtin_detector (data, data->par_line[i]) == 1)
			break ;
		if (redir_detector (data, data->par_line[i]) > 0)
			break ;
		if (cmd_detector (data, data->par_line[i]) == 1)
			break ;
		count++;
	}
	return (count);
}

int	get_cmd_i(t_data *data, int index)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while(data->par_line[++i])
	{
		if (cmd_detector (data, data->par_line[i]) == 1)
			count++;
		if (count == index + 1)
			break ;
	}
	return(i);
}

void	parse_cmd(t_data *data, int index)
{
	int	i;
	int	j;
	int	k;
	int	count;
	
	i = get_cmd_i(data, index);
	count = count_cmd_args(data, i);
	data->cmd.cmdx[index] = (char **)malloc((count + 2) * sizeof(char *));
	data->cmd.cmdx[index][count + 1] = NULL;
	j = -1;
	while (++j <= count)
	{
		k = 0;
		while (data->par_line[i][k])
			k++;
		data->cmd.cmdx[index][j] = (char *)malloc((k + 1) * sizeof(char));
		data->cmd.cmdx[index][j][k] = '\0';
		k = -1;
		while (data->par_line[i][++k])
			data->cmd.cmdx[index][j][k] = data->par_line[i][k];
		i++;
	}
}

// -----------------------------------------------------------------------------
// Function tests if theres the command executable file in the paths of my env.
// -----------------------------------------------------------------------------

int	acessing_cmd(t_data *data, int index)
{
	int	i;
	int	c;

	i = -1;
	c = 0;
	while(data->paths.paths[c])
		c++;
	while (++i < c)
	{
		path_join (data, index, i);
		if (access (data->paths.path_cmd[index], X_OK) == 0)
			return (1);
		else
			free (data->paths.path_cmd[index]);
	}
	return (0);
}